add_library(${PROJECT_NAME} SHARED
  ${CMAKE_CURRENT_SOURCE_DIR}/circle.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/tasks.cpp
)

target_include_directories(${PROJECT_NAME}
  PUBLIC ${CMAKE_SOURCE_DIR}/include
)

add_executable(${PROJECT_NAME}.info
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

target_link_libraries(${PROJECT_NAME}.info
  ${PROJECT_NAME}
)