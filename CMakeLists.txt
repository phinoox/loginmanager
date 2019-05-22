cmake_minimum_required(VERSION 3.0)

find_package(Poco REQUIRED Foundation Util Net JSON DataMySQL)

project(login_server)

set(SOURCES 
            WebServer.cpp
            WebServer.h
            RequestHandlerFactory.cpp
            RequestHandlerFactory.h
            LoginRequestHandler.h
            LoginRequestHandler.cpp
            UserManager.cpp
            UserManager.h
            ConfigLoader.h
            ConfigLoader.cpp
            HTemplate.h
            HTemplate.cpp
            AdminRequestHandler.h
            AdminRequestHandler.cpp)

add_executable(login_server ${SOURCES})
target_link_libraries(login_server Poco::Foundation Poco::Util Poco::Net Poco::JSON Poco::DataMySQL)

install(TARGETS login_server RUNTIME DESTINATION bin)
