/**
 * @file ScoreBoard.cpp
 * @author joann
 */

#include "pch.h"
#include "ScoreBoard.h"
#include <wx/graphics.h>

/**
 * Draw the game
 * @param dc The device context to draw on
 */
void ScoreBoard::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
//    //
//    // Automatic Scaling
//    //
//    auto scaleX = double(width) / double(Width);
//    auto scaleY = double(height) / double(Height);
//    mScale = std::min(scaleX, scaleY);
//
//    if(mShrinked)
//    {
//        mScale *= ShrinkScale;
//    }
//
//    mXOffset = (width - Width * mScale) / 2;
//    mYOffset = (height - Height * mScale) / 2;
//
//    graphics->PushState();
//
//    graphics->Translate(mXOffset, mYOffset);
//    graphics->Scale(mScale, mScale);
//
    wxFont font(LabelSize,
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_NORMAL);
    graphics->SetFont(font, wxColour(0,200,200));
//    graphics->SetTextForeground(FontColor);

    graphics->DrawText(L"Fixed",  // Text to draw
					   LeftScoreX,     // x coordinate for the left size of the text
                       ScoreLabelY);    // y coordinate for the top of the text

    graphics->DrawText(wxString::Format(wxT("%i"),mFixed),  // Text to draw
					   LeftScoreX + 50,     // x coordinate for the left size of the text
                       ScoreY);    // y coordinate for the top of the text

    graphics->DrawText(L"Missed",  // Text to draw
                       Width/2 - 60,     // x coordinate for the left size of the text
                       ScoreLabelY);    // y coordinate for the top of the text

    graphics->DrawText(wxString::Format(wxT("%i"),mMissed),  // Text to draw
                       Width/2 - 10,     // x coordinate for the left size of the text
                       ScoreY);    // y coordinate for the top of the text

    graphics->DrawText(L"Oops",  // Text to draw
                       Width - (LeftScoreX * 2),     // x coordinate for the left size of the text
                       ScoreLabelY);    // y coordinate for the top of the text

    graphics->DrawText(wxString::Format(wxT("%i"),mOops),  // Text to draw
					   Width - (LeftScoreX * 2) + 50,     // x coordinate for the left size of the text
                       ScoreY);    // y coordinate for the top of the text

    // need laptop and bug scaled
//    graphics->PopState();
}


void ScoreBoard::Reset()
{
	mFixed = 0;
	mOops = 0;
	mMissed = 0;
}
