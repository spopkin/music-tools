cmake_minimum_required(VERSION 2.8.12.2)
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build/) 

project(tuner)
file(GLOB tuner_SRC tuner/*.cpp tuner/*.cxx tuner/*.h)

add_executable(tuner tuner/tuner.cxx)



