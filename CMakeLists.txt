cmake_minimum_required(VERSION 3.10)

# lib setup
set(PROJECT_LIB_NAME_STR Algorithms_lib)
project(${PROJECT_LIB_NAME_STR} CXX)

set(CMAKE_CXX_STANDARD 17)  
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -g -Wno-deprecated -pthread")

# add static library
add_library(${PROJECT_LIB_NAME_STR} STATIC
    "${PROJECT_SOURCE_DIR}/src/array_and_strings.cpp"
    "${PROJECT_SOURCE_DIR}/src/linked_lists.cpp"
    "${PROJECT_SOURCE_DIR}/src/trees_and_graphs.cpp"
    "${PROJECT_SOURCE_DIR}/src/simple_graph.cpp")
target_include_directories(${PROJECT_LIB_NAME_STR} PRIVATE "${PROJECT_SOURCE_DIR}/include")

# exec setup
set(PROJECT_EXEC_NAME_STR Algorithms_exec)
project(${PROJECT_EXEC_NAME_STR} CXX)

set(CMAKE_CXX_STANDARD 17)  
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -g -Wno-deprecated -pthread")

# add the executable    
add_executable(${PROJECT_EXEC_NAME_STR} "${PROJECT_SOURCE_DIR}/main.cpp"
    "${PROJECT_SOURCE_DIR}/src/permutation.cpp")
target_include_directories(${PROJECT_EXEC_NAME_STR} PRIVATE "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(${PROJECT_EXEC_NAME_STR} ${PROJECT_LIB_NAME_STR})

#------------------
#  Gtest
#------------------

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

#------------------
# /Gtest
#------------------

# test setup
enable_testing()
set(PROJECT_TEST_NAME ${PROJECT_LIB_NAME_STR}_test)
file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})
target_include_directories(${PROJECT_TEST_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(${PROJECT_TEST_NAME} gtest_main ${PROJECT_LIB_NAME_STR})
add_test(array_and_strings_tests ${PROJECT_TEST_NAME})
add_test(linked_lists_tests ${PROJECT_TEST_NAME})
add_test(trees_and_graphs_tests ${PROJECT_TEST_NAME})