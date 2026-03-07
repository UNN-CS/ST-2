set(header_path "${${PROJECT_NAME}_SOURCE_DIR}/include")
set(headers
  ${header_path}/circle.h
  ${header_path}/tasks.h)
set(srcs
  circle.cpp
  tasks.cpp)

add_library(${PROJECT_NAME} STATIC
  ${headers}
  ${srcs})

target_include_directories(${PROJECT_NAME}
  PUBLIC
    ${${PROJECT_NAME}_SOURCE_DIR}/include)

install(TARGETS ${PROJECT_NAME}
  LIBRARY DESTINATION "${lib_dest}"
  ARCHIVE DESTINATION "${lib_dest}"
  COMPONENT library)

install(FILES ${headers} DESTINATION "${include_dest}")
