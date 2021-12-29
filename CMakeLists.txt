cmake_minimum_required(VERSION 3.21)
project(util)

set(CMAKE_CXX_STANDARD 11)

find_package(Boost COMPONENTS date_time filesystem locale log REQUIRED)

include_directories(${Boost_INCLUDE_DIR})

add_library(util_logger
        src/util/logger/Logger.cpp src/util/logger/Logger.hpp)

add_library(util_serialize
        src/util/serialize/Serialize.cpp src/util/serialize/Serialize.hpp)

add_executable(util src/main.cpp)

find_library(UTIL_LOGGER util_logger libs)
find_library(UTIL_SERIALIZE util_serialize libs)

target_link_libraries(util_logger ${Boost_LIBRARIES})
target_link_libraries(util_serialize ${Boost_LIBRARIES})
target_link_libraries(util ${UTIL_LOGGER} ${UTIL_SERIALIZE} ${Boost_LIBRARIES})
