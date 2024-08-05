cmake_minimum_required(VERSION 3.27)
project(HW4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Events)
include_directories(Players)

add_executable(HW4
        Events/Balrog.cpp
        Events/Balrog.h
        Events/Event.h
        Events/Monster.cpp
        Events/Monster.h
        Events/Pack.cpp
        Events/Pack.h
        Events/PotionsMerchant.cpp
        Events/PotionsMerchant.h
        Events/Slime.cpp
        Events/Slime.h
        Events/Snail.cpp
        Events/Snail.h
        Events/SolarEclipse.cpp
        Events/SolarEclipse.h
        Players/Player.h
        main.cpp
        MatamStory.cpp
        MatamStory.h
        Utilities.cpp
        Utilities.h)
