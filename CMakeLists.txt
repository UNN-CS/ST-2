cmake_minimum_required (VERSION 3.10.2)
project (ST-2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -g")
set(gtest_force_shared_crt on)
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.0
)
FetchContent_MakeAvailable(googletest)

include_directories(${gtest_SOURCE_DIR}/include)
message(PROJECT_SOURCE_DIR="${gtest_SOURCE_DIR}/include")
include_directories(${${PROJECT_NAME}_SOURCE_DIR}/include)
set(header ${${PROJECT_NAME}_SOURCE_DIR}/include)

#add_library(gtest IMPORTED STATIC GLOBAL)

set(tool_dest "bin")
set(lib_dest "lib")
set(include_dest "include/")

add_subdirectory(src)
add_subdirectory(test)
