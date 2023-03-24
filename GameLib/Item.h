/**
 * @file Item.h
 * @author Parker Morgan
 * @author Joanna Rodriguez
 * @author Courtney Thang
 *
 * Base class for any item in our game.
 */

#ifndef PROJECT1_GAMELIB_ITEM_H
#define PROJECT1_GAMELIB_ITEM_H

#include <wx/graphics.h>
#include "Game.h"


class Game;

/**
 * Base class for any item in our game.
 */
class Item {
private:
	/// The game the item is contained in
	Game *mGame;

	/// Underlying Image
	std::unique_ptr<wxImage> mItemImage;

	/// The bitmap that can be displayed for the item
	wxGraphicsBitmap mItemBitmap;

	// Item location in the game
	double  mX = 0;     ///< X location for the center of the item
	double  mY = 0;     ///< Y location for the center of the item

	double mSpeed = 0;

	int mItemHitRange = 50;

	bool mToDel = false;

protected:
	Item(Game *game);

public:
	virtual ~Item();

	/// Default constructor (disabled)
	Item() = delete;

	/// Copy constructor (disabled)
	Item(const Item &) = delete;

	/// Assignment operator
	void operator=(const Item &) = delete;

	/**
	 * The X location of the item
	 * @return X location in pixels
	 */
	double GetX() const { return mX; }

	/**
	 * The Y location of the item
	 * @return Y location in pixels
	 */
	double GetY() const { return mY; }

	/**
	 * Set the item location
	 * @param x X location in pixels
	 * @param y Y location in pixels
	 */
	void SetLocation(double x, double y) { mX = x; mY = y; }

	virtual void SetSpeed(double speed) {}

	double GetSpeed() { return mSpeed; }

	/**
	 * Draw this item
	 * @param dc Device context to draw on
	 */
	virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) = 0;

	virtual void Update(double elapsed, long totalTime) {}

	virtual bool HitTest(int x, int y);

	virtual void XmlLoad(wxXmlNode *node);

	virtual wxXmlNode *XmlSave(wxXmlNode *node);

	double GetHitRange() { return mItemHitRange; }

	virtual void SetDel(bool del) {mToDel = del;}

	bool GetDel() {return mToDel;}

	virtual void SetStartTime(double startTime) {}

	/**
	 * Handle a double-click on an item
	 * @param x X location in the aquarium of the double-click
	 * @param y Y location in the aquarium of the double-click
	 */
	virtual void DoubleClick(int x, int y) {}

	Game * GetGame() { return mGame; }

	virtual void SingleClick(int x, int y) {}

	virtual std::string GetType() {return "Item";}

};

#endif //PROJECT1_GAMELIB_ITEM_H
