#include <gzc/util/db/Database.hpp>

using namespace gzc::util::db;

Database::Database( const std::string_view& username, const std::string_view& password, const std::string_view& database, const std::string_view& host, unsigned short port )
: _username( username ), _password( password ), _database( database ), _host( host ), _port( port )
{
}

Database::Database()
: Database( "root", "password", "database", "localhost", 3306 )
{
}

Database::Database( const Database& other )
: Database( other.get_username(), other.get_password(), other.get_database(), other.get_host(), other.get_port() )
{
}

Database& Database::operator=( const Database& other )
{
    if( this != &other )
    {
        _username = other.get_username();
        _password = other.get_password();
        _database = other.get_database();
        _host = other.get_host();
        _port = other.get_port();
    }
    return *this;
}

Database::~Database()
=default;

bool Database::init()
{
    return false;
}

bool Database::start()
{
    return false;
}

bool Database::finish()
{
    return false;
}

std::string_view Database::get_username() const
{
    return _username;
}

std::string_view Database::get_password() const
{
    return _password;
}

std::string_view Database::get_database() const
{
    return _database;
}

std::string_view Database::get_host() const
{
    return _host;
}

unsigned short Database::get_port() const
{
    return _port;
}

void Database::set_username( const std::string_view& username )
{
    _username = username;
}

void Database::set_password( const std::string_view& password )
{
    _password = password;
}

void Database::set_database( const std::string_view& database )
{
    _database = database;
}

void Database::set_host( const std::string_view& host )
{
    _host = host;
}

void Database::set_port( unsigned short port )
{
    _port = port;
}