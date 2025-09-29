#ifndef GZC_UTIL_SQL_DATABASE_HPP
#define GZC_UTIL_SQL_DATABASE_HPP

#include <string>
#include <string_view>

namespace gzc::util::db
{
    class Database
    {
    private:
        std::string _username;
        std::string _password;
        std::string _database;
        std::string _host;
        unsigned short _port;
    public:
        explicit Database( const std::string_view& username, const std::string_view& password, const std::string_view& database, const std::string_view& host, unsigned short port );
        Database();
        Database( const Database& other );
        Database& operator=( const Database& other );
        virtual ~Database() = 0;
        virtual bool init() = 0;
        virtual bool start() = 0;
        virtual bool finish() = 0;
        std::string_view get_username() const;
        std::string_view get_password() const;
        std::string_view get_database() const;
        std::string_view get_host() const;
        unsigned short get_port() const;
        void set_username( const std::string_view& username );
        void set_password( const std::string_view& password );
        void set_database( const std::string_view& database );
        void set_host( const std::string_view& host );
        void set_port( unsigned short port );
    };
}

#endif // GZC_UTIL_SQL_DATABASE_HPP