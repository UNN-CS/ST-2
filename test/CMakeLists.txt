add_executable(${PROJECT_NAME}.test
  AllTests.cpp
  tests.cpp)

target_link_libraries(${PROJECT_NAME}.test
  ${PROJECT_NAME}
  GTest::gtest
  GTest::gtest_main)

target_include_directories(${PROJECT_NAME}.test
  PUBLIC
    ${${PROJECT_NAME}_SOURCE_DIR}/include)

target_compile_definitions(${PROJECT_NAME}.test
  PRIVATE TEST_DIR="${CMAKE_CURRENT_LIST_DIR}/test")

add_test(NAME ${PROJECT_NAME}.test COMMAND ${PROJECT_NAME}.test)

install(TARGETS ${PROJECT_NAME}.test
  DESTINATION "${tool_dest}")
