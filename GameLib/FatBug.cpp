/**
 * @file FatBug.cpp
 * @author Courtney Thang
 * @author Kaijia Joanna Zhan
 * @author Parker Morgan
 */

#include "pch.h"
#include "FatBug.h"
#include "BugCollection.h"
#include <wx/event.h>
#include <string>

using namespace std;

/// The bug sprite image
const wstring GarbageBugSpriteImageName = L"images/blue-maize-bug.png";

/// The splat image
const wstring GarbageBugSplatImageName = L"images/blue-maize-splat.png";

/// Number of sprite images
const int GarbageBugNumSpriteImages = 5;

/// The bug sprite image
const std::wstring NullBugSpriteImageName = L"images/scarlet-gray-bug.png";

/// The splat image
const std::wstring NullBugSplatImageName = L"images/scarlet-gray-splat.png";

/// Number of sprite images
const int NullBugNumSpriteImages = 6;

/// The code to be displayed in the code window
//const wstring mCode = L"test!!";

/// The FatBug size modifier (25% larger than counterparts)
const double FatBugSize = 1.25;

/**
 * Constructor
 * @param game Game this bug is a member of
 */
FatBug::FatBug(Game *game, std::wstring bugType) : BugCollection(game, GarbageBugSpriteImageName)
{
	SetScale(1.25);
	if (bugType =="null")
	{
		BugCollection::BugSetImage(NullBugSpriteImageName, NullBugNumSpriteImages, NullBugSplatImageName);
	}
	else if (bugType == "garbage")
	{
		BugCollection::BugSetImage(GarbageBugSpriteImageName, GarbageBugNumSpriteImages, GarbageBugSplatImageName);
	}
}

/**
 * Test to see if we hit this object with a mouse.
 * @param x X position to test
 * @param y Y position to test
 * @return true if hit.
 */
bool FatBug::HitTest(int x, int y)
{
	double dx = x - GetX();
	double dy = y - GetY();

	return sqrt(dx * dx + dy * dy) < GetHitRange();
}


/// Function to open IDE window that displays code
void FatBug::OpenWindow(int x) // temp parameter
{
	//copied from fat bug page not sure how to implement
	//CodeDlg dlg(window, mCode);
	//dlg.ShowModal();
}

///Function to call OpenWindow if Fat Bug is double clicked

void FatBug::SingleClick(int x, int y)
{

}
