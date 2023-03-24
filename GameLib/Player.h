/**
 * @file Player.h
 * @author Parker Morgan
 *
 *
 */

#ifndef PROJECT1_GAMELIB_PLAYER_H
#define PROJECT1_GAMELIB_PLAYER_H

#include <wx/graphics.h>

/**
 * Class that is our Player
 */
class Player
{
private:
	wxString mName = "AAA";
	int mScore = 0;

public:
//	/// Default constructor (disabled)
//	Player() = delete;

//	/// Copy constructor (disabled)
//	Player(const Player &) = delete;

//	/// Assignment operator
//	void operator=(const Player &) = delete;

	void SetName(wxString name) {mName = name;}

	wxString GetName() {return mName;}

	void SetScore(int score) {mScore = score;}

	int GetScore() {return mScore;}

};

#endif //PROJECT1_GAMELIB_PLAYER_H
