/**
 * @file ScoreBoard.h
 * @author joann
 *
 * Initializes the score board for the game
 */

#ifndef PROJECT1_GAMELIB_SCOREBOARD_H
#define PROJECT1_GAMELIB_SCOREBOARD_H

/**
* Initializes the score board for the game
*/


class ScoreBoard
{
private:
	///Bug fixed header for the game
	int mFixed = 0;

	///Bug oops header for the game
	int mOops = 0;

	///Bug missed header for the game
	int mMissed = 0;


    /// Game area in virtual pixels
    const static int Width = 1250;

    /// Game area height in virtual pixels
    const static int Height = 1000;

    /// Scale to shrink to when in shrink mode
    const double ShrinkScale = 0.75;

    /// boolean that sets window size
    bool mShrinked = true;

    double mXOffset = 0;

    double mYOffset = 0;

    double mScale = 0;

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

public:
    /**
	 * Get fixed score
	 * @return fixed score
	 */
    double GetFixed() const { return mFixed; }

	void SetFixed(double fixed) {mFixed = fixed;}

    /**
	 * Get oops
	 * @return oops number
	 */
    double GetOops() const { return mOops; }

	void SetOops(double oops) {mOops = oops;}

    /**
	 * Get missed
	 * @return missed number
	 */
    double GetMissed() const { return mMissed; }

	void SetMissed(double missed) {mMissed = missed;}

	void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

	void Reset();

	int GetScore() {return (mFixed - mOops);}

};

#endif //PROJECT1_GAMELIB_SCOREBOARD_H
