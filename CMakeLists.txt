cmake_minimum_required(VERSION 2.8.9)

include_directories(inc)

file(GLOB SOURCES "./src/*.cpp")

add_executable(blackjack ${SOURCES})