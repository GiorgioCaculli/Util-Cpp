#include <gzc/util/serialize/SerializeJSON.hpp>

using namespace gzc::util::serialize;

SerializeJSON::SerializeJSON( const std::string_view& file_name )
: Serialize( file_name )
{
}

SerializeJSON::SerializeJSON()
: SerializeJSON( "data.json" )
{
}

SerializeJSON::SerializeJSON( const SerializeJSON& s )
: SerializeJSON( s.get_file_name() )
{
}

SerializeJSON& SerializeJSON::operator=( const SerializeJSON& s )
{
    if( this != &s )
    {
        Serialize::operator=( s );
    }
    return *this;
}

SerializeJSON::~SerializeJSON()
= default;
