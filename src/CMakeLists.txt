
set(header_path "${CMAKE_SOURCE_DIR}/include")
set(header ${header_path}/circle.h)
set(src
  circle.cpp
  tasks.cpp
)

add_library(${PROJECT_NAME} STATIC
  ${src}
 "tasks.cpp")

target_include_directories(${PROJECT_NAME}
  PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

add_executable(${PROJECT_NAME}.info main.cpp "tasks.cpp")

target_include_directories(${PROJECT_NAME}.info
  PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}.info
  ${PROJECT_NAME})


install(TARGETS ${PROJECT_NAME}
  LIBRARY DESTINATION "${lib_dest}"
  ARCHIVE DESTINATION "${lib_dest}"
  COMPONENT library)

install(TARGETS ${PROJECT_NAME}.info
  RUNTIME DESTINATION "${tool_dest}"
  COMPONENT library)

install(FILES ${header}
  DESTINATION ${include_dest})
