/**
 * @file PlayingArea.h
 * @author joann
 *
 *
 */
#include "ScoreBoard.h"

#include <memory>
#include <string>
#include <algorithm>
#include <random>

#ifndef PROJECT1_GAMELIB_PLAYINGAREA_H
#define PROJECT1_GAMELIB_PLAYINGAREA_H

class ScoreBoard;

class Item;

class PlayingArea
{
private:
	/// All of the items in our Game
	std::vector<std::shared_ptr<Item>> mItems;

	/// the ScoreBoard
	ScoreBoard mScoreBoard;

	/// Game area in virtual pixels
	const static int Width = 1250;

	/// Game area height in virtual pixels
	const static int Height = 1000;

public:
//	void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

};

#endif //PROJECT1_GAMELIB_PLAYINGAREA_H
