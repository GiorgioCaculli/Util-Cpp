#include <gzc/util/logger/Logger.hpp>

#include <boost/date_time/posix_time/posix_time_types.hpp>

#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/support/date_time.hpp>

#include <iostream>

using namespace gzc::util::logger;

namespace logging = boost::log;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace keywords = boost::log::keywords;

/**
 * Logger's constructor with a specific filename
 * \param id The logger's unique I
 * \param file_name The logger's custom filename
 * \param debug Check if debug flag is enabled
 */
Logger::Logger( const std::string& id, const std::string& file_name, const bool debug )
    : _id( id )
      , _file_name( file_name )
      , _debug( debug )
{
    init( _file_name );
}

Logger::Logger()
    :Logger( "default", "default.log", false )
{
}

Logger::Logger( const Logger& logger )
    : Logger( logger.get_id(), logger.get_file_name(), false )
{
}

Logger& Logger::operator=(const Logger& logger )
{
    if ( &logger != this )
    {
        _id = logger.get_id();
        _file_name = logger.get_file_name();
    }
    return *this;
}

/**
 * Upon destruction of the logger, print out its identifier
 */
Logger::~Logger()
{
    std::cout << "Logger ID: " << _id << " File Name: " << _file_name << std::endl;
}

void Logger::init( const std::string_view& file_name )
{
    try
    {
        logging::add_file_log
        (
            keywords::file_name = file_name,
            keywords::format =
            expr::stream
            << expr::attr< unsigned int >( "LineID" )
            << " [" << expr::format_date_time< boost::posix_time::ptime >( "TimeStamp", "%Y-%m-%d %H:%M:%S" )
            << "]: <" << logging::trivial::severity
            << "> " << expr::smessage
        );
        logging::add_common_attributes();
    } catch ( std::exception& e )
    {
        std::cerr << e.what() << std::endl;
    }
}

/**
 * Function that will append the information requested throughout the execution of the program.
 * \param level The severity level
 * \param log_message The message to append
 */
void Logger::log( const Level level, const std::string& log_message ) const
{
    try
    {
        const char* message = log_message.c_str();

        logging::trivial::severity_level lvl;

        switch ( level )
        {
            using enum gzc::util::logger::Logger::Level;
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

        if ( _debug )
        {
            std::cout << message << std::endl;
        }
    } catch ( std::exception& e )
    {
        std::cerr << e.what() << std::endl;
    }
}

void Logger::trace( const std::string& log_message ) const
{
    log( Level::TRACE, log_message );
}

void Logger::debug( const std::string& log_message ) const
{
    log( Level::DEBUG, log_message );
}

void Logger::info( const std::string& log_message ) const
{
    log( Level::INFO, log_message );
}

void Logger::warning( const std::string& log_message ) const
{
    log( Level::WARNING, log_message );
}

void Logger::error( const std::string& log_message ) const
{
    log( Level::ERROR, log_message  );
}

void Logger::fatal( const std::string& log_message ) const
{
    log( Level::FATAL, log_message );
}

/**
 * Getter for the logger's unique identifier.
 * \return The ID
 */
std::string Logger::get_id() const
{
    return _id;
}

/**
 * Getter for the logger's file name
 * \return The name of the logger.
 */
std::string Logger::get_file_name() const
{
    return _file_name;
}
