cmake_minimum_required(VERSION 3.6)
project(ProgrammingContestChallengeBook)

file(GLOB SRCS "*/*/*.cpp")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        ${SRCS})

add_executable(ProgrammingContestChallengeBook ${SOURCE_FILES})

