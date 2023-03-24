/**
 * @file MainFrame.h
 * @author joann
 * @author Courtney Thang
 *
 * The top-level (main) frame of the application
 */

#ifndef PROJECT1_GAMELIB_MAINFRAME_H
#define PROJECT1_GAMELIB_MAINFRAME_H

class GameView;
class Game;

#include <wx/wx.h>


/**
* The top-level (main) frame of the application
*/
class MainFrame : public wxFrame
{
private:
//	GameView *mGameView = nullptr;
	/// View class for our game
	//Game *mGame;

	///Command event for when the user wants to exit the game
	void OnExit(wxCommandEvent& event);

	///Command event for when the user wants to read about the game
	void OnAbout(wxCommandEvent& event);

	//void OnShrink(wxCommandEvent& event);

public:
	///creates the frame for our game
	void Initialize();
};

#endif //PROJECT1_GAMELIB_MAINFRAME_H
