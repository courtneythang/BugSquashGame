/**
 * @file DoublePointsBug.cpp
 * @author rmpal
 * @author Courtney Thang
 */


#include "pch.h"
#include <string>
#include "BugCollection.h"
#include "DoublePointsBug.h"
using namespace std;

/// The bug sprite image
const std::wstring DoublePointsBugSpriteImageName = L"images/scarlet-gray-bug.png";

/// The splat image
const std::wstring DoublePointsBugSplatImageName = L"images/scarlet-gray-splat.png";

/// Number of sprite images
const int NullBugNumSpriteImages = 6;

/**
 * Constructor
 * @param game Game this bug is a member of
 */
DoublePointsBug::DoublePointsBug(Game *game) : BugCollection(game,DoublePointsBugSpriteImageName)
{
	SetScale(0.5);
	BugCollection::BugSetImage(DoublePointsBugSpriteImageName, NullBugNumSpriteImages, DoublePointsBugSplatImageName);
}

/**
 * Test to see if we hit this object with a mouse.
 * @param x X position to test
 * @param y Y position to test
 * @return true if hit.
 */
bool DoublePointsBug::HitTest(int x, int y)
{
	double dx = x - GetX();
	double dy = y - GetY();

	return sqrt(dx * dx + dy * dy) < GetHitRange();
}

void DoublePointsBug::SingleClick(int x, int y)
{

}