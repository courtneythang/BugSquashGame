/**
 * @file NullBugTest.cpp
 * @author Kaijia Joanna Zhan
 */

#include <pch.h>
#include <NullBug.h>
#include <Game.h>

#include "gtest/gtest.h"

//TEST(NullBugTest, Construct){
//	Game game;
//
//	NullBug gbug(&game);
//}
//
//TEST(NullBugTest, HitTest) {
//// Create a nullbug to test
//	Game game;
//	game.Clear();
//
//	std::shared_ptr<Item> gbug = std::make_shared<NullBug>(&game);
//	gbug->SetLocation(100, 200);
//	game.Add(gbug);
//
//
//	// Center of the nullbug should be a true
//	ASSERT_TRUE(gbug->HitTest(100, 200));
//
//	// Left of the nullbug
//	ASSERT_FALSE(gbug->HitTest(10, 200));
//
//	// Right of the nullbug
//	ASSERT_FALSE(gbug->HitTest(200, 200));
//
//	// Above the nullbug
//	ASSERT_FALSE(gbug->HitTest(100, 0));
//
//	// Below the nullbug
//	ASSERT_FALSE(gbug->HitTest(100, 300));
//
//	// On a nullbug transparent pixel
//	ASSERT_FALSE(gbug->HitTest(100 - 125/2 + 17, 200 - 117/2 + 16));
//
//}
