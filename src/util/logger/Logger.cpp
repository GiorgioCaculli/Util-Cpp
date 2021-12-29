#include "Logger.hpp"

#include <boost/date_time/posix_time/posix_time_types.hpp>

#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/support/date_time.hpp>

#include <iostream>

using namespace util;
namespace logging = boost::log;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace sinks = boost::log::sinks;
namespace attrs = boost::log::attributes;
namespace keywords = boost::log::keywords;

/**
 * Logger's constructor with a specific filename
 * @param id The logger's unique I
 * @param file_name The logger's custom filename
 */
Logger::Logger( std::string id, std::string file_name, bool debug )
        : _id( std::move( id ) )
          , _file_name( std::move( file_name ) )
          , _debug( debug )
{
    init( _file_name );
}

/**
 * Upon destruction of the logger, print out its identifier
 */
Logger::~Logger()
{
    std::cout << "Logger ID: " << _id << " File Name: " << _file_name << std::endl;
}

void Logger::init( const std::string &file_name )
{
    logging::add_file_log
            (
                    keywords::file_name = file_name,
                    keywords::format =
                            (
                                    expr::stream
                                            << expr::attr< unsigned int >( "LineID" )
                                            << " ["<< expr::format_date_time< boost::posix_time::ptime >( "TimeStamp", "%Y-%m-%d %H:%M:%S" )
                                            << "]: <" << logging::trivial::severity
                                            << "> " << expr::smessage
                            )
            );
    logging::add_common_attributes();
}

/**
 * Function that will append the information requested throughout the execution of the program.
 * @param level The severity level
 * @param log_message The message to append
 */
void Logger::log( Logger::Level level, const std::string &log_message ) const
{
    const char *message = log_message.c_str();

    logging::trivial::severity_level lvl;

    switch ( level )
    {
        case TRACE:
            lvl = boost::log::trivial::trace;
            break;
        case DEBUG:
            lvl = boost::log::trivial::debug;
            break;
        case INFO:
            lvl = boost::log::trivial::info;
            break;
        case WARNING:
            lvl = boost::log::trivial::warning;
            break;
        case ERROR:
            lvl = boost::log::trivial::error;
            break;
        case FATAL:
            lvl = boost::log::trivial::fatal;
            break;
        default:
            lvl = boost::log::trivial::trace;
            break;
    }

    src::severity_logger< logging::trivial::severity_level > slg;

    BOOST_LOG_SEV( slg, lvl ) << message;

    if( _debug )
    {
        std::cout << message << std::endl;
    }
}

/**
 * Getter for the logger's unique identifier.
 * @return The ID
 */
std::string Logger::get_id() const
{
    return _id;
}

/**
 * Getter for the logger's file name
 * @return The name of the logger.
 */
std::string Logger::get_file_name() const
{
    return _file_name;
}
