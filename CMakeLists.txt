cmake_minimum_required(VERSION 3.21)
project(util VERSION 1.1.0 DESCRIPTION "GzC's Utilities")

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 11)
set(Boost_USE_STATIC_LIBS OFF)

find_package(Boost COMPONENTS date_time filesystem locale log unit_test_framework REQUIRED)

include_directories(${Boost_INCLUDE_DIR})

add_library(util_logger SHARED
        src/util/logger/Logger.cpp)
set_target_properties(util_logger PROPERTIES
        VERSION 1.1.0
        PUBLIC_HEADER include/gzc/util/logger/Logger.hpp)
target_include_directories(util_logger PRIVATE include)
target_link_libraries(util_logger ${Boost_LIBRARIES})
install(TARGETS util_logger
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIB}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

add_library(util_serialize SHARED
        src/util/serialize/Serialize.cpp)
set_target_properties(util_serialize PROPERTIES
        VERSION 1.1.0
        PUBLIC_HEADER include/gzc/util/serialize/Serialize.hpp)
target_include_directories(util_serialize PRIVATE include)
target_link_libraries(util_serialize ${Boost_LIBRARIES})
install(TARGETS util_serialize
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIB}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

add_executable(util src/main.cpp)
target_include_directories(util PRIVATE include)
target_link_libraries(util util_logger util_serialize ${Boost_LIBRARIES})
