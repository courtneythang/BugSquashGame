/**
 * @file Level.h
 * @author Courtney Thang
 *
 * Initializes the level base class where all levels are derived from.
 *
 */

#ifndef PROJECT1_GAMELIB_LEVEL_H
#define PROJECT1_GAMELIB_LEVEL_H

#include <random>
class Laptop;

class Game;
class Item;

/**
 * Initializes the level base class where all levels are derived from.
 */
class Level
{
private:

	/// Ask if this needs to be initialized to something
	Game* mGame;

	/// All of the items in level
	std::vector<std::shared_ptr<Item>> mLevelItems;

	///Random number generator
	std::mt19937 mRandom;

	double mTimeLoaded;

	std::string mLevelName;

	double mCurrentTime;

	std::wstring mProgramName;

public:

	/// Constructor
	Level();

	void Load(const wxString &filename, Game * game);
	void XmlItem(wxXmlNode *node, Game * game,std::shared_ptr<Laptop> parent);

	/**
	 * Getter for mLevelItems
	 * @return mLevelItems
	 */
	std::vector<std::shared_ptr<Item>> GetLevel() { return mLevelItems; }

	/**
	* Get the random number generator
	* @return Pointer to the random number generator
	*/
	std::mt19937 &GetRandom() { return mRandom; }

	void Clear();

	//

	void Update(double elapsed);

	void DrawTitle(std::shared_ptr<wxGraphicsContext> graphics, int wid, int height);


};

#endif //PROJECT1_GAMELIB_LEVEL_H
