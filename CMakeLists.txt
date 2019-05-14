cmake_minimum_required(VERSION 3.0)

project(login_server)

add_executable(login_server main.cpp)

install(TARGETS login_server RUNTIME DESTINATION bin)
