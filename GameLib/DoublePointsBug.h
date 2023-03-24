/**
 * @file DoublePointsBug.h
 * @author rmpal
 * @author Courtney Thang
 *
 */

#ifndef PROJECT1_GAMELIB_DOUBLEPOINTSBUG_H
#define PROJECT1_GAMELIB_DOUBLEPOINTSBUG_H

#include "BugCollection.h"

class DoublePointsBug : public BugCollection
{
private:

public:
	/// Default constructor (disabled)
	DoublePointsBug() = delete;

	/// Copy constructor (disabled)
	DoublePointsBug(const DoublePointsBug &) = delete;

	/// Assignment operator
	void operator=(const DoublePointsBug &) = delete;

	DoublePointsBug(Game *game);

	bool HitTest(int x, int y) override;

	void SingleClick(int x, int y) override;

	std::string GetType() override {return "DoublePointsBug";}

};

#endif //PROJECT1_GAMELIB_DOUBLEPOINTSBUG_H
