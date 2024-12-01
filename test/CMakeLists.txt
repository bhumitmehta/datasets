cmake_minimum_required(VERSION 3.14...3.22)

project(DatasetTests LANGUAGES CXX)

# ---- Options ----

option(ENABLE_TEST_COVERAGE "Enable test coverage" OFF)

# ---- Import tools ----

include(../cmake/tools.cmake)

# ---- Dependencies ----

include(../cmake/CPM.cmake)

# Add doctest for testing
CPMAddPackage("gh:doctest/doctest@2.4.9")
CPMAddPackage("gh:TheLartians/Format.cmake@1.7.3")

# Add the dataset library for testing
CPMAddPackage(NAME Dataset SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/..)

# ---- Create test binary ----

file(GLOB sources CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)
add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME} doctest::doctest Dataset)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)

# Enable compiler warnings for the test target
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Wpedantic -Wextra -Werror)
elseif(MSVC)
  target_compile_options(${PROJECT_NAME} PUBLIC /W4 /WX)
  target_compile_definitions(${PROJECT_NAME} PUBLIC DOCTEST_CONFIG_USE_STD_HEADERS)
endif()

# ---- Enable testing ----

enable_testing()

# Automatically discover and register tests with doctest
include(${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake)
doctest_discover_tests(${PROJECT_NAME})

# ---- Code coverage ----

if(ENABLE_TEST_COVERAGE)
  target_compile_options(${PROJECT_NAME} PUBLIC -O0 -g -fprofile-arcs -ftest-coverage)
  target_link_options(${PROJECT_NAME} PUBLIC -fprofile-arcs -ftest-coverage)
endif()
