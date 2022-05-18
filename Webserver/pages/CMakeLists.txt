cmake_minimum_required(VERSION 3.21)
project(webserv)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(webserv
        src/Config_parser/Location.hpp
        src/main.cpp
        src/Config_parser/ParseConf.cpp
        src/Config_parser/ParseConf.hpp
        src/Config_parser/Server.hpp
        src/Config_parser/readConfig.cpp
        src/Container.hpp
        src/Container.cpp
        src/ListeningSocket.hpp
        src/ListeningSocket.cpp
        src/Request.hpp
        src/Response.hpp
        src/Request.cpp
        src/Response.cpp
        src/Webserv.hpp
        src/ServSockets.hpp
        src/ServSockets.cpp
        src/CGI.hpp
        src/CGI.cpp
        pages/cgi-bin/b.c
        )
