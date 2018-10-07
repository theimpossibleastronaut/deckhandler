cmake_minimum_required(VERSION 3.2)

set(PROJECT_NAME deckhandler)

OPTION(TYPE_SHARED "Build shared library instead of static" OFF)

if(TYPE_SHARED)
  set(BUILD_SHARED_LIBS ON)
endif()

set(CMAKE_CC_FLAGS "-Wall")

add_library(${PROJECT_NAME} deckhandler.c)
