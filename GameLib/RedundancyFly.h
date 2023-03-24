/**
 * @file RedundancyFly.h
 * @author Courtney Thang
 * @author Parker Morgan
 *
 * Initializes the Redundancy Fly in the game
 */

#ifndef PROJECT1_GAMELIB_REDUNDANCYFLY_H
#define PROJECT1_GAMELIB_REDUNDANCYFLY_H

#include "Game.h"
#include "BugCollection.h"


#include "GameView.h"

/**
 * Initializes the Redundancy Fly in the game
 */
class RedundancyFly : public BugCollection
{
private:
	/// The underlying fly image
	std::unique_ptr<wxImage> mFlyBaseImage;
	/// The underlying fly left wing image
	std::unique_ptr<wxImage> mFlyLeftWingImage;
	/// The underlying fly right wing image
	std::unique_ptr<wxImage> mFlyRightWingImage;
	/// The underlying fly top image
	std::unique_ptr<wxImage> mFlyTopImage;
	/// The underlying fly splat image
	std::unique_ptr<wxImage> mFlySplat;
	/// The bitmap we can display for this fly
	wxGraphicsBitmap mFlyBaseBitmap;

	wxGraphicsBitmap mFlyLeftWingBitmap;

	wxGraphicsBitmap mFlyRightWingBitmap;

	wxGraphicsBitmap mFlyTopBitmap;

	wxGraphicsBitmap mFlySplatBitmap;

	/// Wing flapping period in seconds
	const double WingPeriod = 0.2;

/// Starting rotation angle for wings in radians
	const double WingRotateStart = 0.0;

/// End rotation angle for wings in radians
	const double WingRotateEnd = 1.5;

/// How many sets of wings does this bug have?
	const int NumberOfSetsOfWings = 4;

/// Number of virtual pixels between each of the wing sets
	const int WingSetXOffset = 12;

/// X position relative to center of bug for the first (back) wing set
	const int FirstWingSetX = -36;

/// Y position relative to center of bug for the right wings. The negative
/// of this is the Y position for the left wings.
	const int WingSetY = 5;
	//How to get mAquarium type variable for HitTest
	//RedundancyFly  mRedundancyFly;

public:
	/// Default constructor (disabled)
	RedundancyFly() = delete;

	/// Copy constructor (disabled)
	RedundancyFly(const RedundancyFly &) = delete;

	/// Assignment operator
	void operator=(const RedundancyFly &) = delete;

	RedundancyFly(Game *game);

	void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

	wxXmlNode* XmlSave(wxXmlNode* node) override;

	bool HitTest(int x, int y) override;

	void MultiplyBug(wxMouseEvent &event);

	void SingleClick(int x, int y) override;
};

#endif //PROJECT1_GAMELIB_REDUNDANCYFLY_H
