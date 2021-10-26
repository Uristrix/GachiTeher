cmake_minimum_required(VERSION 3.16)
project(LessTeher)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(LessTeher main.cpp Menu.h Menu.cpp GachiTaker.h Hero.h Hero.cpp Level.h Move.h Interface.h  Interface.cpp Character.h Character.cpp Enemy.h  Enemy.cpp Dialogue.h Dialogue.cpp)

target_link_libraries(LessTeher sfml-graphics sfml-audio)
