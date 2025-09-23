#ifndef GZC_UTIL_LOGGER_HPP
#define GZC_UTIL_LOGGER_HPP

#include <string>
#include <string_view>

namespace gzc::util::logger
{
    class Logger
    {
    private:
        enum class Level
        {
            TRACE, /** The lowest level of importance leaving nothing but the existence of the information */
            DEBUG, /** Debugging information meant for developers */
            INFO, /** Textual information meant for the user */
            WARNING, /** Warning information concerning the program's execution */
            ERROR, /** Critical information that requires patch fix */
            FATAL /** Priority level of logging that requires immediate fix */
        };
        std::string _id; /** The logger's unique ID */
        std::string _file_name; /** The logger's name */
        bool _debug;
        static void init( const std::string_view& file_name );
        void log( const Level& level, const std::string_view& log_message ) const;
    public:
        Logger( const std::string_view& id, const std::string_view& file_name, bool debug );
        Logger();
        Logger( const Logger& logger );
        Logger &operator=( const Logger& logger );
        ~Logger();
        void trace( const std::string_view& log_message ) const;
        void debug( const std::string_view& log_message ) const;
        void info( const std::string_view& log_message ) const;
        void warning( const std::string_view& log_message ) const;
        void error( const std::string_view& log_message ) const;
        void fatal( const std::string_view& log_message ) const;
        [[nodiscard]] std::string get_id() const;
        [[nodiscard]] std::string get_file_name() const;
    };
}


#endif //GZC_UTIL_LOGGER_HPP
