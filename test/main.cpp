#include <gzc/util/logger/Logger.hpp>

#include <sstream>

using namespace gzc::util;

int main( int argc, char* argv[ ] )
{
    logger::Logger logger( "main", "logger.log", true );

    std::stringstream ss;

    ss << "Calling: ";

    for ( int i = 0; i < argc; i++ )
    {
        ss << argv[ i ] << " ";
    }
    logger.info( ss.str() );

    if ( argc <= 1 )
    {
        logger.debug( "Parameter missing" );
        return -1;
    }

    logger.trace( "Closing Program..." );

    return 0;
}
