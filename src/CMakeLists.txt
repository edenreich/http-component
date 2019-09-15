

project(http
VERSION 1.0.0
LANGUAGES C CXX
DESCRIPTION "An easy to use component for interacting with the http layer."
)

set(BUILD_SHARED_LIBS OFF)
set(DISTRIBUTE_DIR ${CMAKE_BINARY_DIR}/dist)

set(HEADERS_CXX_FILES_HTTP
    http/client.h
    http/server.h
)

set(HEADERS_CXX_FILES_HTTP_INTERFACES
    http/interfaces/client_interface.h
    http/interfaces/server_interface.h
)

set(HEADERS_CXX_FILES_HTTP_TYPES
    http/types/common.h
)

set(SOURCES_CXX_FILES_HTTP
    client.cpp
    server.cpp
)

add_library(${PROJECT_NAME}
    ${SOURCES_CXX_FILES_HTTP}
)

target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/http
)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/dist)
file(COPY http DESTINATION ${CMAKE_BINARY_DIR}/dist/include)

install(
    TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${DISTRIBUTE_DIR}/bin
    LIBRARY DESTINATION ${DISTRIBUTE_DIR}/lib
    ARCHIVE DESTINATION ${DISTRIBUTE_DIR}/lib
)

message("[INFO] - Distribution dir: " ${DISTRIBUTE_DIR})