/**
 * @file Game.h
 * @author rmpal
 * @author Courtney Thang
 * @author Kaijia Joanna Zhan
 * @author Parker Morgan
 */


#ifndef PROJECT1_GAMELIB_GAME_H
#define PROJECT1_GAMELIB_GAME_H

#include "Level.h"
#include "ScoreBoard.h"
#include "Leaderboard.h"

#include <memory>
#include <string>
#include <algorithm>
#include <random>
#include <unordered_map>

class Item;

class ScoreBoard;

/**
 * Class game that holds all of the items
 */
class Game
{
private:

	/// All of the items in our Game
	std::vector<std::shared_ptr<Item>> mItems;

	/// Unordered map for bug images
	std::unordered_map<std::wstring, std::shared_ptr<wxImage>> mImage;

	/// Resources directory
	std::wstring mResourcesDirectory;

	/// Game area in virtual pixels
	const static int Width = 1250;

	/// Game area height in virtual pixels
	const static int Height = 1000;

	/// Scale to shrink to when in shrink mode
	const double ShrinkScale = 0.75;

	/// boolean that sets window size
	bool mShrinked = false;

	double mXOffset = 0;

	double mYOffset = 0;

	double mScale = 0;

	int mWhatLevel = 0;

	/// XML for level 0
	Level mLevel0;

	/// XML for level 1
	Level mLevel1;

	/// XML for level 2
	Level mLevel2;

	/// XML for level 3
	Level mLevel3;

	///Random number generator
	std::mt19937 mRandom;

	/// Lable for score font size to use
	const int LabelSize = 40;

	/// The font color to use
	const wxColour FontColor = wxColour(0, 200, 200);

	/// Left score X location. The right score is
	/// the width minus this value.
	const int LeftScoreX = 150;

	/// Score Y location
	const int ScoreY = 20;

	/// Score label Y location
	const int ScoreLabelY = 100;

	double mElapsed = 0;

	/// the ScoreBoard
	ScoreBoard mScoreBoard;

	// the leaderboard
	Leaderboard mLeaderboard;

	std::wstring mState = L"Start";
public:

	/**
	 * Constructor
	 */
	Game();

	void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
	void Update(double elapsed, long totalTime);
	std::shared_ptr<Item> HitTest(int x, int y);

	void LoadLevel(int level);

	/// Initializing clearing the old data
	void Clear();

	void Save(const wxString &filename);

	/// Adds new bug to the game
	void Add(std::shared_ptr<Item> item);

	void SetLevel(std::vector<std::shared_ptr<Item>> levelItems) {mItems = levelItems;}

	double GetWidth() const { return Width; }

	double GetHeight() const { return Height; }

	/**
	* Get the random number generator
	* @return Pointer to the random number generator
	*/
	std::mt19937 &GetRandom() { return mRandom; }

	/// Getter for mShrinked
	bool GetShrink() const {return mShrinked;}

	void SetShrink(bool shrink) {mShrinked = shrink;}

	void OnLeftDown(int x, int y);

	std::shared_ptr<wxImage> SetImage(std::wstring imageName);

	void SetImagesDirectory(const std::wstring &dir);

	//void IncreaseMiss(int add);

	void IncreaseOops(int add);

	void IncreaseFix(int add);

	void SetState(wxString state) {mState = state;}

};

#endif //PROJECT1_GAMELIB_GAME_H
