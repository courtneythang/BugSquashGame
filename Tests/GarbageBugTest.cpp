/**
 * @file GarbageBugTest.cpp
 * @author Kaijia Joanna Zhan
 * @author Courtney Thang
 */

#include <pch.h>
#include <GarbageBug.h>
#include <Game.h>

#include "gtest/gtest.h"

TEST(GarbageBugTest, Construct){
	Game game;

	GarbageBug gbug(&game);
}

TEST(GarbageBugTest, HitTest) {
// Create a bug to test
	Game game;
	game.Clear();

	std::shared_ptr<Item> gbug = std::make_shared<GarbageBug>(&game);
	gbug->SetLocation(100, 200);
	game.Add(gbug);

	// Center of the bug should be a true
	ASSERT_TRUE(gbug->HitTest(100, 200));

	// Left of the bug
	ASSERT_FALSE(gbug->HitTest(10, 200));

	// Right of the bug
	ASSERT_FALSE(gbug->HitTest(200, 200));

	// Above the bug
	ASSERT_FALSE(gbug->HitTest(100, 0));

	// Below the bug
	ASSERT_FALSE(gbug->HitTest(100, 300));

	// On a bug transparent pixel
	ASSERT_FALSE(gbug->HitTest(100 - 125/2 + 17, 200 - 117/2 + 16));

}