cmake_minimum_required(VERSION 3.10)
project(ST-2)

set(CMAKE_CXX_STANDARD 11)

include_directories(../include)

set(src circle.cpp tasks.cpp)

set(headers ../include/circle.h ../include/tasks.h)

add_library(${PROJECT_NAME} SHARED
  ${src}
  ${headers})

target_include_directories(${PROJECT_NAME}
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
         ${CMAKE_CURRENT_SOURCE_DIR}/../include)

target_link_libraries(${PROJECT_NAME}
  pthread)

add_executable(${PROJECT_NAME}.info main.cpp)
target_include_directories(${PROJECT_NAME}.info
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
         ${CMAKE_CURRENT_SOURCE_DIR}/../include)
target_link_libraries(${PROJECT_NAME}.info
  ${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION "${lib_dest}"
    ARCHIVE DESTINATION "${lib_dest}"
    COMPONENT library)
install(TARGETS ${PROJECT_NAME}.info
        RUNTIME DESTINATION "${tool_dest}"
    COMPONENT library)
install(FILES ${headers} DESTINATION "${include_dest}")