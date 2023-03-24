/**
 * @file RedundancyFly.cpp
 * @author Courtney Thang
 * @author Joanna Rodriguez
 * @author Parker Morgan
 */

#include "pch.h"
#include "RedundancyFly.h"
#include "Game.h"
#include <string>
#include <stdlib.h>
#include <wx/event.h>


using namespace std;

/// Redundancy fly filename
const wstring FlyBaseImage = L"images/redundancy-fly-base.png";

/// Redundancy fly filename
const wstring FlyLeftWing = L"images/redundancy-fly-lwing.png";

/// Redundancy fly filename
const wstring FlyRightWing = L"images/redundancy-fly-rwing.png";

/// Redundancy fly filename
const wstring FlyTopImage = L"images/redundancy-fly-top.png";

/// Redundancy fly filename
const wstring FlySplat = L"images/redundancy-fly-splat.png";

/// Wing flapping period in seconds
const double WingPeriod = 0.2;

/// Starting rotation angle for wings in radians
const double WingRotateStart = 0.0;

/// End rotation angle for wings in radians
const double WingRotateEnd = 1.5;

/// How many sets of wings does this bug have?
const int NumberOfSetsOfWings = 4;

/// Number of virtual pixels between each of the wing sets
const int WingSetXOffset = 12;

/// X position relative to center of bug for the first (back) wing set
const int FirstWingSetX = -36;

/// Y position relative to center of bug for the right wings. The negative
/// of this is the Y position for the left wings.
const int WingSetY = 5;

/**
 * Constructor
 * @param game Game this fly is a member of
 */
RedundancyFly::RedundancyFly(Game *game) : BugCollection(game, FlyBaseImage)
{
	/// m var in game that holds map of all images
	/// a function in game that gets the image (65-73)
	/// a function in game that gets the images into the map
	/// call game function that adds image to the map

	//loads the image of the flybase
	mFlyBaseImage = make_unique<wxImage>(FlyBaseImage, wxBITMAP_TYPE_ANY);

	mFlyLeftWingImage = make_unique<wxImage>(FlyLeftWing, wxBITMAP_TYPE_ANY);

	mFlyRightWingImage = make_unique<wxImage>(FlyRightWing, wxBITMAP_TYPE_ANY);

	mFlyTopImage = make_unique<wxImage>(FlyTopImage, wxBITMAP_TYPE_ANY);

	mFlySplat = make_unique<wxImage>(FlySplat, wxBITMAP_TYPE_ANY);
	//mFlyBitmap = make_unique<wxBitmap>(*mFlySplat);

}


/**
 * Draw this fly
 * @param dc Device context to draw on
 */
void RedundancyFly::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
	if(mFlyBaseBitmap.IsNull())
	{
		mFlyBaseBitmap = graphics->CreateBitmapFromImage(*mFlyBaseImage);
	}
	if(mFlyLeftWingBitmap.IsNull())
	{
		mFlyLeftWingBitmap = graphics->CreateBitmapFromImage(*mFlyLeftWingImage);
	}
	if(mFlyRightWingBitmap.IsNull())
	{
		mFlyRightWingBitmap = graphics->CreateBitmapFromImage(*mFlyRightWingImage);
	}
	if(mFlyTopBitmap.IsNull())
	{
		mFlyTopBitmap = graphics->CreateBitmapFromImage(*mFlyTopImage);
	}
	int wid = mFlyBaseImage->GetWidth();
	int hit = mFlyBaseImage->GetHeight();
	graphics->DrawBitmap(mFlyBaseBitmap,
						 int(GetX() - wid / 2),
						 int(GetY() - hit / 2), wid, hit);

	int widleft = mFlyLeftWingImage->GetWidth();
	int hitleft = mFlyLeftWingImage->GetHeight();
	graphics->DrawBitmap(mFlyLeftWingBitmap,
						 int(GetX()- wid / 2),
						 int(GetY() - WingSetY - hit / 2), widleft, hitleft);

	graphics->DrawBitmap(mFlyLeftWingBitmap,
						 int(GetX() - WingSetXOffset - wid / 2),
						 int(GetY() - WingSetY - hit / 2), widleft, hitleft);

	graphics->DrawBitmap(mFlyLeftWingBitmap,
						 int(GetX() - (WingSetXOffset * 2) - wid / 2),
						 int(GetY() - WingSetY - hit / 2), widleft, hitleft);

	graphics->DrawBitmap(mFlyLeftWingBitmap,
						 int(GetX() - (WingSetXOffset * 3) - wid / 2),
						 int(GetY() - WingSetY - hit / 2), widleft, hitleft);

	int widright = mFlyRightWingImage->GetWidth();
	int hitright = mFlyLeftWingImage->GetHeight();
	graphics->DrawBitmap(mFlyRightWingBitmap,
						 int(GetX()- wid / 2),
						 int(GetY() + WingSetY - hit / 2), widright, hitright);

	graphics->DrawBitmap(mFlyRightWingBitmap,
						 int(GetX() - WingSetXOffset - wid / 2),
						 int(GetY() + WingSetY - hit / 2), widright, hitright);

	graphics->DrawBitmap(mFlyRightWingBitmap,
						 int(GetX() - (WingSetXOffset * 2) - wid / 2),
						 int(GetY() + WingSetY - hit / 2), widright, hitright);

	graphics->DrawBitmap(mFlyRightWingBitmap,
						 int(GetX() - (WingSetXOffset * 3) - wid / 2),
						 int(GetY() + WingSetY - hit / 2), widright, hitright);

	int widtop = mFlyTopImage->GetWidth();
	int hittop = mFlyTopImage->GetHeight();
	graphics->DrawBitmap(mFlyTopBitmap,
						 int(GetX() - wid / 2),
						 int(GetY() - hit / 2), widtop, hittop);
}

wxXmlNode* RedundancyFly::XmlSave(wxXmlNode* node)
{
	auto itemNode = Item::XmlSave(node);

	itemNode->AddAttribute(L"type", L"redundancyfly");

	return itemNode;
}

/**
 * Test to see if we hit this object with a mouse.
 * @param x X position to test
 * @param y Y position to test
 * @return true if hit.
 */
bool RedundancyFly::HitTest(int x, int y)
{
	double dx = x - GetX();
	double dy = y - GetY();

	return sqrt(dx * dx + dy * dy) < 50;
}

void RedundancyFly::MultiplyBug(wxMouseEvent &event)
{
	// Amount of flies to appear after clicking bug
	int flyMultiplier = rand() % 3 + 3;

	double xPos = GetX();
	double yPos = GetY();

	// New fly positions that are +- 200 x/y location from originally clicked bug
	int flyLocationX = xPos + (rand() % 200);
	int flyLocationY = yPos + (rand() % 200);

	//mClickedFly = mFly;
	if (event.LeftIsDown())
	{

	}
//	if (mClickedFly != nullptr)
//	{
//		for(int i = 0; i < flyMultiplier; i++)
//		{
//			// Spawn new fly
//		}
//	}


	//int flyLocation = rand() % location clicked +- 200 y and x direction;
	//if redundancyfly is clicked
		//replace clicked fly with 3-6 other redundancy flies at random
		//locations an average of 200 pixels from bug initially clicked

}

void RedundancyFly::SingleClick(int x, int y)
{

}
