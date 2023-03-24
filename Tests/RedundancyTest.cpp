/**
 * @file RedundancyTest.cpp
 * @author Kaijia Joanna Zhan
 */



#include <pch.h>
#include "gtest/gtest.h"
#include <Game.h>
#include <RedundancyFly.h>

using namespace std;

TEST(RedundancyFlyTest, Construct){
	Game game;
	RedundancyFly item(&game);
}

TEST(RedundancyFlyTest, HitTest) {
	// Create a fish to test
	Game game;
	game.Clear();

	shared_ptr<Item> rfly = std::make_shared<RedundancyFly>(&game);
	rfly->SetLocation(100, 200);
	game.Add(rfly);



	// Center of the fish should be a true
	ASSERT_TRUE(rfly->HitTest(100, 200));

	// Left of the fish
	ASSERT_FALSE(rfly->HitTest(10, 200));

	// Right of the fish
	ASSERT_FALSE(rfly->HitTest(200, 200));

	// Above the fish
	ASSERT_FALSE(rfly->HitTest(100, 0));

	// Below the fish
	ASSERT_FALSE(rfly->HitTest(100, 300));

	// On a fish transparent pixel
	ASSERT_FALSE(rfly->HitTest(100 - 125/2 + 17, 200 - 117/2 + 16));
}