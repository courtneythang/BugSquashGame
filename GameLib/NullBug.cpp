/**
 * @file NullBug.cpp
 * @author Kaijia Joanna Zhan
 * @author Flora Pieters
 * @author Courtney Thang
 *
 * Source file for NullBug
 */

#include "pch.h"
#include <string>
#include "BugCollection.h"
#include "NullBug.h"
using namespace std;

/// The bug sprite image
const std::wstring NullBugSpriteImageName = L"images/scarlet-gray-bug.png";

/// The splat image
const std::wstring NullBugSplatImageName = L"images/scarlet-gray-splat.png";

/// Number of sprite images
const int NullBugNumSpriteImages = 6;

/**
 * Constructor
 * @param game Game this bug is a member of
 */
NullBug::NullBug(Game *game) : BugCollection(game,NullBugSpriteImageName)
{
	BugCollection::BugSetImage(NullBugSpriteImageName, NullBugNumSpriteImages, NullBugSplatImageName);
}

/**
 * Test to see if we hit this object with a mouse.
 * @param x X position to test
 * @param y Y position to test
 * @return true if hit.
 */
bool NullBug::HitTest(int x, int y)
{
	double dx = x - GetX();
	double dy = y - GetY();

	return sqrt(dx * dx + dy * dy) < GetHitRange();
}

void NullBug::SingleClick(int x, int y)
{

}
