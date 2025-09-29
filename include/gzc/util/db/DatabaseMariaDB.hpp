#ifndef GZC_UTIL_SQL_DATABASE_MARIADB_HPP
#define GZC_UTIL_SQL_DATABASE_MARIADB_HPP

#include <gzc/util/db/Database.hpp>
#include <mariadb/conncpp.hpp>
#include <mariadb/conncpp/Properties.hpp>

namespace gzc::util::db
{
    class DatabaseMariaDB : public Database
    {
    private:
        std::shared_ptr< sql::Driver > _driver;
        sql::SQLString _url;
        sql::Properties _properties;
        std::shared_ptr< sql::Connection > _connection;
        std::shared_ptr< sql::Statement > _statement;
        std::shared_ptr< sql::ResultSet > _result_set;
    public:
        explicit DatabaseMariaDB( const std::string_view& username, const std::string_view& password, const std::string_view& database, const std::string_view& host, unsigned short port );
        DatabaseMariaDB();
        DatabaseMariaDB( const DatabaseMariaDB& other );
        DatabaseMariaDB& operator=( const DatabaseMariaDB& other );
        ~DatabaseMariaDB() override;
        bool init() override;
        bool start() override;
        bool finish() override;
    };
}

#endif // GZC_UTIL_SQL_DATABASE_MARIADB_HPP