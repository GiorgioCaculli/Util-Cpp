#include <gzc/util/db/DatabaseMariaDB.hpp>
#include <mariadb/conncpp/Driver.hpp>

#include <format>
#include <mariadb/conncpp/Exception.hpp>

using namespace gzc::util::db;

DatabaseMariaDB::DatabaseMariaDB( const std::string_view& username, const std::string_view& password, const std::string_view& database, const std::string_view& host, unsigned short port )
: Database( username, password, database, host, port )
{
}

DatabaseMariaDB::DatabaseMariaDB()
: DatabaseMariaDB( "root", "password", "database", "localhost", 3306 )
{
}

DatabaseMariaDB::DatabaseMariaDB( const DatabaseMariaDB& other )
: DatabaseMariaDB( other.get_username(), other.get_password(), other.get_database(), other.get_host(), other.get_port() )
{
}

DatabaseMariaDB& DatabaseMariaDB::operator=( const DatabaseMariaDB& other )
{
    if( this != &other )
    {
        Database::operator=( other );
    }
    return *this;
}

DatabaseMariaDB::~DatabaseMariaDB()
=default;

bool DatabaseMariaDB::init()
{
    try
    {
        _driver = std::make_shared< sql::Driver >( sql::mariadb::get_driver_instance() );
        _url = std::format("jdbc:mariadb://{}:{}/{}", std::string( get_host() ), std::to_string( get_port() ), std::string( get_database() ) );
        _properties = sql::Properties({
            { "user", std::string( get_username() ) },
            { "password", std::string( get_password() ) }
        } );
        return true;
    }
    catch ( const sql::SQLException& e )
    {
        // Logger Error
        return false;
    }
    return false;
}

bool DatabaseMariaDB::start()
{
    try
    {
        if ( _driver != nullptr )
        {
            _connection = std::make_shared< sql::Connection >( _driver->connect( _url, _properties ) );
            _statement = std::make_shared< sql::Statement >( _connection );
            _result_set = std::make_shared< sql::ResultSet >( _statement );
            if( _result_set != nullptr )
            {
                return true;
            }
        }
    }
    catch( const sql::SQLException& e )
    {
        // Logger Error
        return false;
    }
    catch( const std::exception& e )
    {
        // Logger Error
        return false;
    }
    return false;
}

bool DatabaseMariaDB::finish()
{
    if( _result_set != nullptr )
    {
        try
        {
            _result_set->close();
            _statement->close();
            _connection->close();
        }
        catch( const sql::SQLException& e )
        {
            // Logger Error
            return false;
        }
        return true;
    }
    return false;
}
