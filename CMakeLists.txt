#
# cmake ..
# cmake -DUNIT_TESTING=1
# 
# CXXFLAGS="-fsanitize=address -fno-omit-frame-pointer -fsanitize=undefined -fsanitize=integer" \
# CFLAGS="-fsanitize=address -fno-omit-frame-pointer -fsanitize=undefined -fsanitize=integer" \
# CC=clang CXX=clang++ cmake -DUNIT_TESTING=1 ..
#

cmake_minimum_required(VERSION 2.6)
project(vfs-lib)

# Global variables
set(APPLICATION_NAME ${PROJECT_NAME})
set(APPLICATION_VERSION_MAJOR "0")
set(APPLICATION_VERSION_MINOR "1")
set(APPLICATION_VERSION "${APPLICATION_VERSION_MAJOR}.${APPLICATION_VERSION_MINOR}")

add_definitions("-Wall -Werror -Wpedantic -std=c11")

# Include library headers
include_directories("include")

if (UNIT_TESTING)
  add_subdirectory("tests")
endif (UNIT_TESTING)

# Make static library
add_library("vfs.${APPLICATION_VERSION}" STATIC lib/vfs.c)




#add_definitions("-Wall -Werror -Wpedantic -std=c11")
#ADD_DEFINITIONS("-Wall -Werror -Wpedantic -Wmissing-declarations -std=c11")
#SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../build/modules")
#set (VFS_LIB_VERSION_MAJOR 0)
#set (VFS_LIB_VERSION_MINOR 1)
#ADD_TEST(test_new test_new)




