/**
 * @file Game.cpp
 * @author rmpal
 * @author Courtney Thang
 * @author Kaijia Joanna Zhan
 * @author Parker Morgan
 */

#include "pch.h"
#include "Game.h"
#include "Laptop.h"
#include "DoublePointsBug.h"
#include "Leaderboard.h"
#include "wx/xml/xml.h"
#include <wx/graphics.h>


using namespace std;

const int levelStartDuration = 2;

const int levelTotalDuration = 50;

/**
* Game Constructor
*/
Game::Game()
{
	LoadLevel(0);
}

/**
 * Set the directory the images are stored in
 * @param dir
 */
void Game::SetImagesDirectory(const std::wstring &dir) {
	mResourcesDirectory = dir;
}

std::shared_ptr<wxImage> Game::SetImage(std::wstring imageName)
{
	auto image = mImage.find(imageName);
	if (image != mImage.end())
	{
		return image->second;
	}
	else
	{
		auto path =  imageName;
		auto newImage = make_shared<wxImage>(path);
		mImage[imageName] = newImage;
		return newImage;
	}
}

/**
 * Draw the game
 * @param dc The device context to draw on
 */
void Game::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
	//
	// Automatic Scaling
	//
	auto scaleX = double(width) / double(Width);
	auto scaleY = double(height) / double(Height);
	mScale = std::min(scaleX, scaleY);

	if(mShrinked)
	{
		mScale *= ShrinkScale;
	}
	mXOffset = (width - Width * mScale) / 2;
	mYOffset = (height - Height * mScale) / 2;

	graphics->PushState();

	graphics->Translate(mXOffset, mYOffset);
	graphics->Scale(mScale, mScale);

	if(!mShrinked)
	{
		graphics->Clip(0, 0, Game::Width, Game::Height);
	}

	// From here on you are drawing virtual pixels
	graphics->SetBrush(*wxWHITE_BRUSH);
	graphics->DrawRectangle(0,0,Width,Height);


	for (auto item : mItems)
	{
		item->Draw(graphics);
	}
	mScoreBoard.OnDraw(graphics, width, height);





	if (mState == L"Start")
	//if (mElapsed <= 2)
	{
		if (mWhatLevel == 0)
		{
			mLevel0.DrawTitle(graphics, Width, Height);
		}
		if (mWhatLevel == 1)
		{
			mLevel1.DrawTitle(graphics, Width, Height);
		}
		if (mWhatLevel == 2)
		{
			mLevel2.DrawTitle(graphics, Width, Height);
		}
		if (mWhatLevel == 3)
		{
			mLevel3.DrawTitle(graphics, Width, Height);
		}
	}

	if (mState == L"End")
	{
		//	Leaderboard leaderboard;
		//	leaderboard.OnDraw(graphics, width, height);


		mLeaderboard.OnDraw(graphics, width, height);
	}

	graphics->PopState();
}


/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Game::Update(double elapsed, long totalTime)
{
	mElapsed += elapsed;
	for (auto item : mItems)
	{
		item->Update(elapsed, mElapsed);
		if (item->GetDel())
		{
//			auto loc = find(begin(mItems), end(mItems), item);
//			if (loc != end(mItems))
//			{
//				mItems.erase(loc);
//			}
			item->SetLocation(-1000,-1000);
			item->SetSpeed(0);
			double missed = mScoreBoard.GetMissed();
			missed++;
			mScoreBoard.SetMissed(missed);
			item->SetDel(false);
		}
	}
	if (mElapsed < levelStartDuration)
	{
		mState = L"Start";
	}
	if (mLeaderboard.GetActive())
	{
		if (mElapsed >= levelStartDuration && mElapsed < levelTotalDuration)
		{
			mState = L"Playing";
		}
		if (mElapsed > levelTotalDuration && mState != L"End")
		{
			mState = L"End";
			int score = mScoreBoard.GetScore();
			mLeaderboard.AssessPlayerScore(score);
		}
	}
	else
	{
		if (mElapsed >= levelStartDuration)
		{
			mState = L"Playing";
		}
	}

	if (mWhatLevel == 0)
	{
		mLevel0.Update(elapsed);
	}
	else if (mWhatLevel == 1)
	{
		mLevel1.Update(elapsed);
	}
	if (mWhatLevel == 2)
	{
		mLevel2.Update(elapsed);
	}
	if (mWhatLevel == 3)
	{
		mLevel3.Update(elapsed);
	}
}



/**
 * Test an x,y click location to see if it clicked
 * on some item in the game.
 * @param x X location in pixels
 * @param y Y location in pixels
 * @returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<Item> Game::HitTest(int x, int y)
{
	for (auto i = mItems.rbegin(); i != mItems.rend();  i++)
	{
		if ((*i)->HitTest(x, y))
		{
			return *i;
		}
	}

	return  nullptr;
}

/**
 * Load level
 * @param level the level number
 */
void Game::LoadLevel(int level)
{
	Clear();

	mWhatLevel = level;
	if (level == 0)
	{
		mElapsed = 0;
		mLevel0.Clear();
		mLevel0.Load(L"levels/level0.xml", this);
		SetLevel(mLevel0.GetLevel());
		mScoreBoard.Reset();
		mLeaderboard.SetActive(false);
	}
	if (level == 1)
	{
		mElapsed = 0;
		mLevel1.Clear();
		mLevel1.Load(L"levels/level1.xml", this);
		SetLevel(mLevel1.GetLevel());
		mScoreBoard.Reset();
		mLeaderboard.SetActive(false);
	}
	if (level == 2)
	{
		mElapsed = 0;
		mLevel2.Clear();
		mLevel2.Load(L"levels/level2.xml", this);
		SetLevel(mLevel2.GetLevel());
		mScoreBoard.Reset();
		mLeaderboard.SetActive(false);
	}
	if (level == 3)
	{
		mElapsed = 0;
		mLevel3.Clear();
		mLevel3.Load(L"levels/level3.xml", this);
		SetLevel(mLevel3.GetLevel());
		mScoreBoard.Reset();
		mLeaderboard.SetActive(true);

	}

}

/**
 * Clear the game data
 * Deletes all known items in the game
*/
void Game::Clear()
{
	mItems.erase(mItems.begin(), mItems.end());
}

/**
* @param filename The filename of the file to save the game to
*/
void Game::Save(const wxString &filename)
{
	wxXmlDocument xmlDoc;

	auto root = new wxXmlNode(wxXML_ELEMENT_NODE, L"game");
	xmlDoc.SetRoot(root);

	for (auto item : mItems)
	{
		item->XmlSave(root);
	}

	if(!xmlDoc.Save(filename, wxXML_NO_INDENTATION))
	{
		wxMessageBox(L"Write to XML failed");
		return;
	}
}


/**
 * Add an item to the game
 * @param item New item to add
 */
void Game::Add(std::shared_ptr<Item> item)
{
    mItems.push_back(item);
}

/**
* Handle a mouse click
* @param x X location clicked on
* @param y Y location clicked on
*/
void Game::OnLeftDown(int x, int y)
{
	double oX = (x - mXOffset) / mScale;
	double oY = (y - mYOffset) / mScale;

	auto item = Game::HitTest(oX, oY);
	if(item != nullptr)
	{
		std::string what_item = item->GetType();
		if(what_item == "Bug")
		{
			int add = 1;
			IncreaseFix(add);
		}

		if(what_item == "Feature")
		{
			int add = 1;
			IncreaseOops(add);
		}
		if(what_item == "DoublePointsBug")
		{
			int add = 2;
			IncreaseFix(add);
		}
	}

}

void Game::IncreaseFix(int add)
{
	double fixed = mScoreBoard.GetFixed();
	fixed += add;
	mScoreBoard.SetFixed(fixed);
}
void Game::IncreaseOops(int add)
{
	double oops = mScoreBoard.GetOops();
	oops += add;
	mScoreBoard.SetOops(oops);
}
