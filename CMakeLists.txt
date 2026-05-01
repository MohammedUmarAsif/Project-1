cmake_minimum_required(VERSION 3.16)
project(MidnightPrototype LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(midnight_prototype
  src/main.cpp
  src/Game.cpp
)

target_include_directories(midnight_prototype PRIVATE include)
