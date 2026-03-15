cmake_minimum_required (VERSION 3.14)
project (ST-2)

enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -g")

if(APPLE AND CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
	execute_process(
		COMMAND xcrun --show-sdk-path
		OUTPUT_VARIABLE SDK_PATH
		OUTPUT_STRIP_TRAILING_WHITESPACE)
	include_directories(SYSTEM "${SDK_PATH}/usr/include/c++/v1")
endif()


set(tool_dest "bin")
set(lib_dest "lib")
set(include_dest "include/")

add_subdirectory(src)
add_subdirectory(test)
