/**
 * @file GarbageBug.h
 * @author Kaijia Joanna Zhan
 * @author Flora Pieters
 *
 * Header for bug type Garbage Bug
 */

#ifndef PROJECT1_COPY_GAMELIB_GARBAGEBUG_H
#define PROJECT1_COPY_GAMELIB_GARBAGEBUG_H

#include "GameView.h"
#include "BugCollection.h"

/**
 * Class for type GarbageBug
 */

class GarbageBug : public BugCollection
{
private:


public:
	/// Default constructor (disabled)
	GarbageBug() = delete;

	/// Copy constructor (disabled)
	GarbageBug(const GarbageBug &) = delete;

	/// Assignment operator
	void operator=(const GarbageBug &) = delete;

	GarbageBug(Game* game);

	bool HitTest(int x, int y) override;

	void SingleClick(int x, int y) override;

};

#endif //PROJECT1_COPY_GAMELIB_GARBAGEBUG_H
