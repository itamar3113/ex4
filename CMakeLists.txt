# and is requires by CMake.
cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 11)

# Set <PROJNAME> to be your project name. We set CXX (C++) here as the target language.
project(ex4 VERSION 0.1.0 LANGUAGES CXX)

# If you want to see "under the hood" of CMake, uncomment this:
# set(CMAKE_VERBOSE_MAKEFILE ON)

# Define variables containing compiler flags for gcc
set(MTM_FLAGS_DEBUG "-std=c++11 --pedantic-errors -Wall -Werror")
set(MTM_FLAGS_RELEASE "${MTM_FLAGS_DEBUG} -DNDEBUG")

# Set the flags for gcc
set(CMAKE_CPP_FLAGS ${MTM_FLAGS_DEBUG})


# Add the names of your source files here
set(CPP_FILES main.cpp players/Player.cpp players/Ninja.cpp players/Healer.cpp players/Warrior.cpp utilities.cpp
        cards/BattleCard.cpp cards/BattleCard.h cards/Card.cpp cards/Gremlin.cpp cards/Witch.cpp cards/Dragon.cpp cards/Mana.cpp cards/Barfight.cpp)


add_executable(mtmchkin ${CPP_FILES})