cmake_minimum_required(VERSION 3.2)

set(PROJECT_NAME deckhandler)

set(TARGET "example-01")

OPTION(TYPE_SHARED "Build shared library instead of static" OFF)

if(TYPE_SHARED)
  set(BUILD_SHARED_LIBS ON)
endif()

set(CMAKE_CC_FLAGS "-Wall")
set(CMAKE_BUILD_TYPE "MinSizeRel" CACHE STRING "This statically specifies what build type (configuration) will be built in this build tree. Possible values are empty, Debug, Release, RelWithDebInfo and MinSizeRel.")

add_library(${PROJECT_NAME} deckhandler.c)

add_executable(${TARGET} example-01.c)
target_link_libraries(example-01 ${PROJECT_NAME})
