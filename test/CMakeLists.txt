find_package(GTest CONFIG REQUIRED)
target_link_libraries(test GTest::gtest GTest::gtest_main)

add_executable(test test.cpp)
target_link_libraries(test GTest::GTest GTest::Main)
add_executable(${PROJECT_NAME}.test
  AllTests.cpp
  tests.cpp)
target_link_libraries(${PROJECT_NAME}.test
  ${PROJECT_NAME} gtest pthread)
target_compile_definitions(${PROJECT_NAME}.test 
  PRIVATE TEST_DIR="${CMAKE_CURRENT_LIST_DIR}/test")

install(TARGETS ${PROJECT_NAME}.test
        DESTINATION "${tool_dest}")
