/**
 * @file FatBugTest.cpp
 * @author Kaijia Joanna Zhan
 * @author Joanna Rodriguez Zamarron
 */

#include <pch.h>
#include <FatBug.h>
#include <Game.h>

#include "gtest/gtest.h"

TEST(FatBugTest, Construct){
	Game game;

	FatBug fatBug(&game);
}

TEST(FatBugTest, HitTest) {
// Create a bug to test
	Game game;
	game.Clear();

	std::shared_ptr<Item> fatBug = std::make_shared<FatBug>(&game);
	fatBug->SetLocation(100, 200);
	game.Add(fatBug);

	// Center of the bug should be a true
	ASSERT_TRUE(fatBug->HitTest(100, 200));

	// Left of the bug
	ASSERT_FALSE(fatBug->HitTest(10, 200));

	// Right of the bug
	ASSERT_FALSE(fatBug->HitTest(200, 200));

	// Above the bug
	ASSERT_FALSE(fatBug->HitTest(100, 0));

	// Below the bug
	ASSERT_FALSE(fatBug->HitTest(100, 300));

	// On a bug transparent pixel
	ASSERT_FALSE(fatBug->HitTest(100 - 125/2 + 17, 200 - 117/2 + 16));

}

TEST(FatBugTest, DoubleClickTest1)
{
// Create a bug to test
	Game game;
	game.Clear();

	auto fatBug = std::make_shared<FatBug>(&game);

	game.Add(fatBug);

	// Set some locations
	fatBug->SetLocation(200, 250);

//	// Double-click on FatBug:
//	fatBug->DoubleClick(200, 250);
//
//	// Ensure the FatBug did not move
//	ASSERT_NEAR(200, fatBug->GetX(), 0.01);
//	ASSERT_NEAR(250, fatBug->GetY(), 0.01);

}