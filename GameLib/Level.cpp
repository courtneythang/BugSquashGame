/**
 * @file Level.cpp
 * @author Courtney Thang
 */

#include "pch.h"
#include "Level.h"
#include "RedundancyFly.h"
#include "FatBug.h"
#include "GarbageBug.h"
#include "NullBug.h"
#include "Laptop.h"
#include "Feature.h"
#include "DoublePointsBug.h"

using namespace std;

Level::Level()
{

}

/**
 * Load the game level from an XML file.
 *
 * Opens the XML file and reads the nodes, creating items as appropriate.
 *
 * @param filename The filename of the file to load the game level from.
 */
void Level::Load(const wxString &filename, Game * game)
{
	mGame = game;

	wxXmlDocument xmlDoc;
	if(!xmlDoc.Load(filename))
	{
		wxMessageBox(L"Unable to load level file.");
		return;
	}

	auto root = xmlDoc.GetRoot();

	mLevelName = root->GetAttribute(L"level");

	auto rootName = root->GetName();

	auto laptopChild = root->GetChildren();

	double x;
	double y;

	for( ; laptopChild; laptopChild=laptopChild->GetNext())
	{
		laptopChild->GetAttribute(L"x").ToDouble(&x);
		laptopChild->GetAttribute(L"y").ToDouble(&y);
		shared_ptr<Laptop> laptop = make_shared<Laptop>(game);
		laptop->SetLocation(x,y);
		mProgramName = laptopChild->GetAttribute(L"name");
		laptop->SetName(mProgramName);
		game->SetLaptop(laptop);
		mLevelItems.push_back(laptop);

		auto child = laptopChild->GetChildren();

		for( ; child; child=child->GetNext())
		{
			auto name = child->GetName();
			XmlItem(child, game, laptop);
		}
	}
}

/**
 * Handle a node of type item.
 * @param node XML node
 */
void Level::XmlItem(wxXmlNode *node, Game * game, shared_ptr<Laptop> parent)
{

	shared_ptr<BugCollection> item;

	auto type = node->GetAttribute(L"type");

	double x;
	double y;
	node->GetAttribute(L"x").ToDouble(&x);
	node->GetAttribute(L"y").ToDouble(&y);

	double speed;
	node->GetAttribute(L"speed").ToDouble(&speed);

	double starttime;
	node->GetAttribute(L"start").ToDouble(&starttime);

	auto name = node->GetName();
	if(name == L"bug"){
		if (type == L"redundancy")
		{
			item = make_shared<RedundancyFly>(mGame);
			item->SetLocation(x,y);
			item->SetSpeed(speed);
			item->SetStartTime(starttime);
			item->SetLaptop(parent);
		}
		if (type == L"garbage")
		{
			item = make_shared<GarbageBug>(mGame);
			item->SetLocation(x,y);
			item->SetSpeed(speed);
			item->SetStartTime(starttime);
			if (node->GetChildren())
			{
				item = make_shared<FatBug>(mGame,L"garbage");
				item->SetLocation(x,y);
				item->SetSpeed(speed);
				item->SetStartTime(starttime);
				item->SetLaptop(parent);
			}
			item->SetLaptop(parent);
		}
		if (type == L"null")
		{
			item = make_shared<NullBug>(mGame);
			item->SetLocation(x,y);
			item->SetSpeed(speed);
			item->SetStartTime(starttime);
			if (node->GetChildren() && node->GetChildren()->GetName() == L"code")
			{
				item = make_shared<FatBug>(mGame,L"null");
				item->SetLocation(x,y);
				item->SetSpeed(speed);
				item->SetStartTime(starttime);
				item->SetLaptop(parent);
			}
			if (node->GetChildren() && node->GetChildren()->GetName() == L"double")
			{
				item = make_shared<DoublePointsBug>(mGame);
				item->SetLocation(x,y);
				item->SetSpeed(speed);
				item->SetStartTime(starttime);
				item->SetLaptop(parent);
			}
			item->SetLaptop(parent);
		}
	}
	if (name == L"feature")
	{
		item = make_shared<Feature>(mGame);
		item->SetLocation(x,y);
		item->SetSpeed(speed);
		item->SetStartTime(starttime);
		item->SetLaptop(parent);
	}
	if (item != nullptr)
	{
		mLevelItems.push_back(item);
		item->XmlLoad(node);
	}
}

/**
 * Clear the level data
 * Deletes all known items in the level
*/
void Level::Clear()
{
	mLevelItems.erase(mLevelItems.begin(), mLevelItems.end());
}

void Level::Update(double elapsed)
{
	mCurrentTime += elapsed;
}

void Level::DrawTitle(std::shared_ptr<wxGraphicsContext> graphics, int wid, int height)
{
	wxFont font(wxSize(0, 130),
				wxFONTFAMILY_SWISS,
				wxFONTSTYLE_NORMAL,
				wxFONTWEIGHT_NORMAL);
	double textwid;
	double textheight;
	graphics->SetFont(font, *wxRED);
	graphics->GetTextExtent(wxString(mLevelName), &textwid, &textheight);
	graphics->DrawText(wxString(mLevelName),
					   (wid-textwid)/2,
					   (height-textheight)/2);
}



