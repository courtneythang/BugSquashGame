/**
 * @file PlayingArea.cpp
 * @author joann
 */

#include "pch.h"
#include "PlayingArea.h"
#include "ScoreBoard.h"
#include <wx/graphics.h>

///**
// * Draw the game
// * @param dc The device context to draw on
// */
//void PlayingArea::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
//{
//	graphics->SetBrush(*wxWHITE_BRUSH);
//	graphics->DrawRectangle(0,0,Width,Height);
//
//	for (auto item : mItems)
//	{
//		item->Draw(graphics);
//	}
//	mScoreBoard.OnDraw(graphics, width, height);
//}