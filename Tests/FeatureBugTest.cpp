/**
 * @file FeatureBugTest.cpp
 * @author Kaijia Joanna Zhan
 * @author Flora Pieters
 */

 #include <pch.h>
#include <Feature.h>
#include <Game.h>

#include "gtest/gtest.h"

TEST(Feature, Construct){
    Game game;

    Feature fbug(&game);
}

TEST(Feature, HitTest) {
// Create a bug to test
    Game game;
    game.Clear();

    std::shared_ptr<Item> fbug = std::make_shared<Feature>(&game);
    fbug->SetLocation(100, 200);
    game.Add(fbug);

    // Center of the bug should be a true
    ASSERT_TRUE(fbug->HitTest(100, 200));

    // Left of the bug
    ASSERT_FALSE(fbug->HitTest(10, 200));

    // Right of the bug
    ASSERT_FALSE(fbug->HitTest(200, 200));

    // Above the bug
    ASSERT_FALSE(fbug->HitTest(100, 0));

    // Below the bug
    ASSERT_FALSE(fbug->HitTest(100, 300));

    // On a bug transparent pixel
    ASSERT_FALSE(fbug->HitTest(100 - 125/2 + 17, 200 - 117/2 + 16));

}
