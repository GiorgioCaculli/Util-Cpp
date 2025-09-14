#ifndef GZC_UTIL_LOGGER_WARNING_HPP
#define GZC_UTIL_LOGGER_WARNING_HPP

#include <gzc/util/logger/Logger.hpp>

namespace gzc::util::logger
{
    class LoggerWarning : public Logger
    {
    public:
        explicit LoggerWarning( const std::string& id, const std::string& file_name, bool debug );
        LoggerWarning();
        LoggerWarning( const LoggerWarning& l );
        LoggerWarning& operator=( const LoggerWarning& l );
        ~LoggerWarning();
    };
}

#endif //GZC_UTIL_LOGGER_WARNING_HPP
