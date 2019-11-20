cmake_minimum_required(VERSION 3.15)
project(ass1_splFlix)

set(CMAKE_CXX_STANDARD 11)

add_executable(ass1_splFlix src/main.cpp src/Action.cpp include/Action.h src/Session.cpp include/Session.h src/User.cpp include/User.h src/Watchable.cpp include/Watchable.h)