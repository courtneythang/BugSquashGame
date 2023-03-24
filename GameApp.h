/**
 * @file GameApp.h
 * @author Courtney Thang
 *
 *
 */

#ifndef PROJECT1__GAMEAPP_H
#define PROJECT1__GAMEAPP_H

#include <wx/wx.h>

/**
 * Main application class
 */
class GameApp : public wxApp
{
private:

public:
	/// OnInit function initialize
	bool OnInit() override;
};

#endif //PROJECT1__GAMEAPP_H
