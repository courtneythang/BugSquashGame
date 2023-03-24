/**
 * @file Item.cpp
 * @author Parker Morgan
 * @author Courtney Thang
 */

#include "pch.h"
#include "Item.h"
#include "Game.h"

#include <string>


using namespace std;

/**
 * Constructor
 * @param game The game this item is a member of
 * @param filename that the item is taking the image of
 */
Item::Item(Game *game) : mGame(game)
{

}

/**
 * Destructor
 */
Item::~Item()
{

}


/**
 * Draw this item
 * @param dc Device context to draw on
 */
void Item::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
	int wid = mItemImage->GetWidth();
	int hit = mItemImage->GetHeight();

	graphics->DrawBitmap(mItemBitmap,
						 int(GetX() - wid / 2),
						 int(GetY() - hit / 2), wid, hit);
}

/**
 * Test to see if we hit this object with a mouse.
 * @param x X position to test
 * @param y Y position to test
 * @return true if hit.
 */
bool Item::HitTest(int x, int y)
{
	double width = mItemImage->GetWidth();
	double height = mItemImage->GetHeight();

	double testX = x - GetX() + width / 2;
	double testY = y - GetY() + height / 2;

	if (testX < 0 || testY < 0 || testX >= width || testY >= height)
	{
		return false;
	}

	return !mItemImage->IsTransparent((int)testX, (int)testY);
}

/**
* Load the attributes for an item node.
 *
 * This is the base class version that loads the attributes
 * common to all items.
 *
 * @param node the Xml node we are loading the item from
*/
void Item::XmlLoad(wxXmlNode *node)
{
	node->GetAttribute(L"x",L"0").ToDouble(&mX);
	node->GetAttribute(L"y",L"0").ToDouble(&mY);
}

/**
 * Save this item to an XML node
 * @param node The parent node we are going to be a child of
 * @return wxXmlNode that we saved the item into
 */
wxXmlNode *Item::XmlSave(wxXmlNode *node)
{
	auto itemNode = new wxXmlNode(wxXML_ELEMENT_NODE, L"item");
	node->AddChild(itemNode);

	itemNode->AddAttribute(L"x", wxString::FromDouble(mX));
	itemNode->AddAttribute(L"y", wxString::FromDouble(mY));


	return itemNode;
}
