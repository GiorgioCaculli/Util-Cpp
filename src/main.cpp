#include <iostream>

#include <gzc/util/logger/Logger.hpp>

#include <sstream>

using namespace gzc::util;

int main( int argc, char *argv[] )
{
    Logger logger( "main", "logger.log", true );

    std::stringstream ss;

    ss << "Calling: ";

    for( int i = 0; i < argc; i++ )
    {
        ss << argv[ i ] << " ";
    }
    logger.log( Logger::Level::INFO, ss.str() );

    if( argc <= 1 )
    {
        logger.log( Logger::Level::ERROR, "Parameter missing" );
        return -1;
    }

    logger.log( Logger::Level::INFO, "Closing Program..." );

    return 0;
}
