project(IcSim)

cmake_minimum_required(VERSION 2.8.8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fPIC -Wno-deprecated")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

include(GNUInstallDirs)

add_executable(IcSim
    src/main.cpp
    src/chip_base.cpp
    src/chips/clock.cpp
    src/chips/constant_value.cpp
    src/chips/SN74LS00.cpp
    src/chips/SN74LS04.cpp
    src/chips/SN74LS20.cpp
    src/chips/SN74LS30.cpp
    src/chips/SN74LS161A.cpp
    src/chips/SN74HC163N.cpp
    src/chips/SN74HC373.cpp
)

target_include_directories(IcSim PUBLIC src)

install(TARGETS IcSim
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION bin
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/IcSim)
    
INSTALL (
    DIRECTORY ${CMAKE_SOURCE_DIR}/src/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/IcSim
    FILES_MATCHING PATTERN "*.h*")
