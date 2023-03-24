/**
 * @file MainFrame.cpp
 * @author joann
 * @author Courtney Thang
 */

#include "pch.h"
#include "MainFrame.h"
#include "GameView.h"
#include "ids.h"

/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize()
{
	//Creates the frame
	Create(nullptr,wxID_ANY, L"BugSquash",wxDefaultPosition, wxSize(1250,1000 ));

	// Create a sizer that will lay out child windows vertically
	// one above each other
	auto sizer = new wxBoxSizer( wxVERTICAL );

	// Create the view class object as a child of MainFrame
	auto gameView = new GameView();
	gameView->Initialize(this);


	// Add it to the sizer
	sizer->Add(gameView,1, wxEXPAND | wxALL );

	// Set the sizer for this frame
	SetSizer( sizer );

	//Layout (place) the child windows
	Layout();

	auto menuBar = new wxMenuBar( );

	auto fileMenu = new wxMenu();
	auto levelMenu = new wxMenu();
	auto viewMenu = new wxMenu();
	auto helpMenu = new wxMenu();

	menuBar->Append(fileMenu, L"&File" );
	menuBar->Append(levelMenu, L"&Level" );
	menuBar->Append(viewMenu, L"&View" );

	menuBar->Append(helpMenu, L"&Help");

	//mGameView->AddMenus(this, menuBar, viewMenu);
	viewMenu->Append(IDM_VIEW, L"&Shrink", L"Enable Shrink", wxITEM_CHECK);
	Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnShrink, gameView, IDM_VIEW);
	Bind(wxEVT_UPDATE_UI, &GameView::OnShrinkUpdate, gameView, IDM_VIEW);

	levelMenu->Append(IDM_LEVEL0, "Open &Level 0", L"Open level file...");
	levelMenu->Append(IDM_LEVEL1, "Open &Level 1", L"Open level file...");
	levelMenu->Append(IDM_LEVEL2, "Open &Level 2", L"Open level file...");
	levelMenu->Append(IDM_LEVEL3, "Open &Level 3", L"Open level file...");

	fileMenu->Append(wxID_SAVEAS, "Save &As...\tCtrl-S", L"Save game as...");
	fileMenu->Append(wxID_EXIT, "E&xit\tAlt-X", "Quit this program");

	helpMenu->Append(wxID_ABOUT, "&About\tF1", "Show about dialog");

	SetMenuBar( menuBar );

	CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );

	Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
	Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnAbout, this, wxID_ABOUT);

}

/**
 * Exit menu option handlers
 * @param event
 */
void MainFrame::OnExit(wxCommandEvent& event)
{
	Close(true);
}

/**
 * About menu option handler
 * @param event
 */
void MainFrame::OnAbout(wxCommandEvent& event)
{
	wxMessageBox(L"Welcome to BugSquash! Squash all the bugs before they reach your program!",
				 L"About BugSquash",
				 wxOK,
				 this);
}

