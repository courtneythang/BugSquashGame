/**
 * @file GarbageBug.cpp
 * @author Kaijia Joanna Zhan
 * @author Flora Pieters
 * @author Courtney Thang
 *
 * Source file for type GarbageBug
 */

#include "pch.h"
#include "GarbageBug.h"
#include "Game.h"
#include <string>
using namespace std;

/// The bug sprite image
const wstring GarbageBugSpriteImageName = L"images/blue-maize-bug.png";

/// The splat image
const wstring GarbageBugSplatImageName = L"images/blue-maize-splat.png";

/// Number of sprite images
const int GarbageBugNumSpriteImages = 5;

/**
 * Constructor
 * @param game Game this bug is a member of
 */
GarbageBug::GarbageBug(Game *game) : BugCollection(game, GarbageBugSpriteImageName)
{
	BugCollection::BugSetImage(GarbageBugSpriteImageName, GarbageBugNumSpriteImages, GarbageBugSplatImageName);
}

/**
 * Test to see if we hit this object with a mouse.
 * @param x X position to test
 * @param y Y position to test
 * @return true if hit.
 */
bool GarbageBug::HitTest(int x, int y)
{
	double dx = x - GetX();
	double dy = y - GetY();

	return sqrt(dx * dx + dy * dy) < GetHitRange();
}

void GarbageBug::SingleClick(int x, int y)
{

}
