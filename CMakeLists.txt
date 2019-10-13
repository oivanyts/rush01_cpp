cmake_minimum_required(VERSION 3.13)
project(ft_GKrellM)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

set(CMAKE_CXX_STANDARD 98)


add_executable(ft_GKrellM
        Common.hpp
        CPUModule.cpp
        CPUModule.hpp
        DateTimeModule.cpp
        DateTimeModule.hpp
        HostnameModule.cpp
        HostnameModule.hpp
        IMonitorDisplay.cpp
        IMonitorDisplay.hpp
        IMonitorModule.hpp
        main.cpp
        main1.cpp
        mainwindow.cpp
        mainwindow.hpp
        Makefile
        NcursesOut.cpp
        NcursesOut.hpp
        NetworkModule.cpp
        NetworkModule.hpp
        OSInfoModule.cpp
        OSInfoModule.hpp
        QTOut.cpp
        QTOut.hpp
        RAMModule.cpp
        RAMModule.hpp)
target_link_libraries( ${PROJECT_NAME} ncurses)