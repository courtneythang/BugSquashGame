project(GameLib)

set(SOURCE_FILES GarbageBug.cpp GarbageBug.h NullBug.cpp NullBug.h Feature.cpp Feature.h RedundancyFly.cpp RedundancyFly.h FatBug.cpp FatBug.h GameView.cpp GameView.h MainFrame.cpp MainFrame.h ScoreBoard.cpp ScoreBoard.h Level.cpp Level.h BugCollection.cpp BugCollection.h Game.h Game.cpp Item.cpp Item.h Player.cpp Player.h CodeWindow.cpp CodeWindow.cpp Laptop.cpp Laptop.h ids.h PlayingArea.cpp PlayingArea.h Leaderboard.cpp Leaderboard.h DoublePointsBug.cpp DoublePointsBug.h)

set(wxBUILD_PRECOMP OFF)
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)

include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
