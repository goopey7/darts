cmake_minimum_required(VERSION 3.22.1)

project(darts)

file(GLOB SRC CONFIGURE_DEPENDS "*.h" "*.cpp")

add_executable(${PROJECT_NAME} ${SRC})
