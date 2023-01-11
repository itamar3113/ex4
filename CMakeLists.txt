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
set(CPP_FILES main.cpp Players/Player.cpp Players/Ninja.cpp Players/Healer.cpp Players/Warrior.cpp utilities.cpp
        Cards/BattleCard.cpp Cards/BattleCard.h Cards/Card.cpp Cards/Gremlin.cpp Cards/Witch.cpp Cards/Dragon.cpp
        Cards/Mana.cpp Cards/Barfight.cpp Cards/Well.cpp Cards/Treasure.cpp Cards/Merchant.cpp Exception.h Mtmchkin.cpp)


add_executable(mtmchkin ${CPP_FILES})