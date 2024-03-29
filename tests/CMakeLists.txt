cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(tests)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(
  ${CMAKE_CURRENT_BINARY_DIR}/googletest-src
  ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
  EXCLUDE_FROM_ALL
)

include_directories(
    ${CMAKE_BINARY_DIR}/dist/include
)

set(SOURCES_CXX_FILES
  unit/url_test.cpp
  unit/server_test.cpp
  unit/message_test.cpp
  unit/request_test.cpp
  unit/response_test.cpp
  unit/client_test.cpp
)

add_executable(${PROJECT_NAME} main.cpp ${SOURCES_CXX_FILES})
target_link_libraries(${PROJECT_NAME} gtest http)
add_test(NAME ParserTest COMMAND ${PROJECT_NAME})
add_test(NAME OutputInterfaceTest COMMAND ${PROJECT_NAME})

set_tests_properties(${unit} PROPERTIES TIMEOUT 10)
