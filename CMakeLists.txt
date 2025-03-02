cmake_minimum_required (VERSION 3.10.2)
project (ST-2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -g")

set(tool_dest "bin")
set(lib_dest "lib")
set(include_dest "include/")

set(SOURCE_FILES
    src/main.cpp
    src/circle.cpp
    src/tasks.cpp)

set(HEADER_FILES
    include/circle.h
    include/tasks.h)

include_directories(${CMAKE_SOURCE_DIR}/include)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)

add_executable(main ${SOURCE_FILES} ${HEADER_FILES})

set(TEST_SOURCE_FILES
    test/AllTests.cpp
    test/tests.cpp
    src/circle.cpp
    src/tasks.cpp)

add_executable(AllTests ${TEST_SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(AllTests gtest_main)

include(GoogleTest)
gtest_discover_tests(AllTests)
