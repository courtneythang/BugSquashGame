/**
 * @file BugCollection.cpp
 * @author Rossi Palomba
 * @author Flora Pieters
 * @author Courtney Thang
 */

#include "pch.h"
#include "Laptop.h"
#include "BugCollection.h"
#include <iostream>
#include <cmath>

/*
 * Constructor
 */
BugCollection::BugCollection(Game *game, const std::wstring &filename) :
	Item(game)
{

}

void BugCollection::BugSetImage(std::wstring bugImage, int spriteNum, std::wstring splatImage)
{
	mBugImage = GetGame()->SetImage(bugImage);
	mBugSplatImage = GetGame()->SetImage(splatImage);

	mSpriteCount = spriteNum;
}

/**
 * Draw this bug
 * @param dc Device context to draw on
 */
void BugCollection::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{

	double wid = mBugImage->GetWidth();
	double hit = mBugImage->GetHeight();

	double spriteHit = hit/mSpriteCount;

	if(mBugBitmap.IsNull())
	{
		mBugBitmap = graphics->CreateBitmap(*mBugImage);

	}
	double angle = atan2(mLaptop->GetY()-GetY(), mLaptop->GetX()-GetX());

	graphics->PushState();
	graphics->Translate(GetX(),GetY());
	graphics->Scale(mScaling, mScaling);
	graphics->Rotate(angle);
	graphics->Clip(-wid/2,-spriteHit/2,wid,100);
	graphics->DrawBitmap(mBugBitmap, -wid/2, -mSprite - spriteHit/2, wid, hit);
	graphics->PopState();
}

/**
 * Handle updates in time of our bug
 *
 * This is called before we draw and allows us to
 * move our bug. We add our speed times the amount
 * of time that has elapsed.
 * @param elapsed Time elapsed since the class call
 */
void BugCollection::Update(double elapsed, long totalTime)
{

	double angle = atan2(mLaptop->GetY()-GetY(), mLaptop->GetX()-GetX());
	if (totalTime >= GetStartTime())
	{
		SetLocation(GetX() + mSpeedX * (elapsed) * cos(angle),
					GetY() + mSpeedY * (elapsed) * sin(angle));

	}
	if(sqrt((pow(mLaptop->GetX() - GetX(), 2)  + pow(mLaptop->GetY()-GetY(),2))) < 5)
	{
		SetDel(true);
	}

	double startTime = GetStartTime();

	if (totalTime < startTime)
	{
		mSprite = 100*mSpriteCount;
	}
	else
	{
		mSprite += 100;
		if (mSprite >= 100*mSpriteCount)
		{
			mSprite = 0;
		}
	}

}

/**
 * Load the attributes for an item node.
 *
 * This is the  base class version that loads the attributes
 * common to all items. Override this to load custom attributes
 * for specific items.
 *
 * @param node The Xml node we are loading the item from
 */
void BugCollection::XmlLoad(wxXmlNode *node)
{
	Item::XmlLoad(node);

//	node->GetAttribute(L"speedx", L"0").ToDouble(&mSpeedX);
//	node->GetAttribute(L"speedy", L"0").ToDouble(&mSpeedY);
}

void BugCollection::SetLaptop(std::shared_ptr<Laptop> laptop)
{
	mLaptop = laptop;
}
