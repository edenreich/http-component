
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(webpage)

include_directories(
    ${CMAKE_BINARY_DIR}/dist/include
)

set(SOURCES_CXX_FILES
    main.cpp
)

add_executable(${PROJECT_NAME}
    ${SOURCES_CXX_FILES}
)

target_link_libraries(${PROJECT_NAME} http stdc++fs)

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)
