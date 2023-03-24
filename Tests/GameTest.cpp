/**
 * @file GameTest.cpp
 * @author joann
 * @author Courtney Thang
 */

#include <pch.h>
#include <Game.h>
#include <RedundancyFly.h>
#include <FatBug.h>
#include <Feature.h>
#include <GarbageBug.h>
#include <NullBug.h>
#include <regex>
#include <string>
#include <fstream>
#include <streambuf>
#include <wx/filename.h>

#include "gtest/gtest.h"

using namespace std;

const unsigned int RandomSeed = 1238197374;

class GameTest : public ::testing::Test
{
protected:
	/**
	 * Create a path to a place to put temporary files
	 */
	 wxString TempPath()
	{
		 // Create a temporary filename we can use
		auto path = wxFileName::GetTempDir() + L"/game";
		if(!wxFileName::DirExists(path))
		{
			wxFileName::Mkdir(path);
		}

		return path;
	}
	/**
	* Read a file into a wstring and return it.
	* @param filename Name of the file to read
	* @return File contents
	*/
	wstring ReadFile(const wxString &filename)
	{
		ifstream t(filename.ToStdString());
		wstring str((istreambuf_iterator<char>(t)),
					istreambuf_iterator<char>());

		return str;
	}

	/**
	* Test to ensure a game level xml file is empty
	*/
	void TestEmpty(wxString filename)
	{
		cout << "Temp file: " << filename << endl;

		auto xml = ReadFile(filename);
		cout << xml << endl;

		ASSERT_TRUE(regex_search(xml, wregex(L"<\\?xml.*\\?>")));
		ASSERT_TRUE(regex_search(xml, wregex(L"<game/>")));

	}

	/**
	*  Populate a game with three redundancy flies
	*/
	void PopulateFly(Game *game)
	{
		game->GetRandom().seed(RandomSeed);

		auto fly1 = make_shared<RedundancyFly>(game);
		game->Add(fly1);
		fly1->SetLocation(100, 200);

	}

	void TestFly(wxString filename)
	{
		cout << "Temp file: " << filename << endl;

		auto xml = ReadFile(filename);
		cout << xml << endl;

		// Ensure the positions are correct
		ASSERT_TRUE(regex_search(xml, wregex(L"<game><item x=\"625\" y=\"500\"/><item x=\"-100\" y=\"200\" type=\"garbage\"/><item x=\"-100\" y=\"300\" type=\"garbage\"/><item x=\"300\" y=\"500\" type=\"redundancyfly\"/><item x=\"-100\" y=\"600\" type=\"garbage\"/><item x=\"100\" y=\"200\" type=\"redundancyfly\"/></game>")));

	}
	void SaveBugs(wxString filename)
	{
		cout << "Temp file: " << filename << endl;

		auto xml = ReadFile(filename);
		cout << xml << endl;

		ASSERT_TRUE(regex_search(xml, wregex(L"<game><item x=\"625\" y=\"500\"/><item x=\"-100\" y=\"200\" type=\"garbage\"/><item x=\"-100\" y=\"300\" type=\"garbage\"/><item x=\"300\" y=\"500\" type=\"redundancyfly\"/><item x=\"-100\" y=\"600\" type=\"garbage\"/></game>")));
	}

};

TEST_F(GameTest, Construct)
{
	Game game;
}

TEST_F(GameTest, Clear)
{
	// Create a path to temporary files
	auto path = TempPath();

	// Create a game
	Game game;

	// Populate it
	PopulateFly(&game);

	// Clear the items in the game
	game.Clear();

	// First test, saving an empty game
	auto file1 = path + L"/test1.game";

	// Save the file
	game.Save(file1);

	// Test to see if it is empty
	TestEmpty(file1);

}

TEST_F(GameTest, Load)
{
	auto path = TempPath();

	Game game;
	game.GetRandom().seed(RandomSeed);

	auto file1 = path + L"/test1.game";
	game.Save(file1);

	// Loads level 0
	game.LoadLevel(0);
	game.Save(file1);

	auto file2 = path + L"/test2.game";
	game.Save(file2);

	SaveBugs(file1);

}

TEST_F(GameTest, Save) {
	// Create a path to temporary files
	auto path = TempPath();

	// Create a game
	Game game;

	//
	// First test, saving an empty game
	//
	auto file1 = path + L"/test1.game";
	game.Save(file1);

	//TestEmpty(file1);

	PopulateFly(&game);

	auto file2 = path + L"/test2.game";
	game.Save(file2);

	TestFly(file2);
}
