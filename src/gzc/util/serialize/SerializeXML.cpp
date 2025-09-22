#include <gzc/util/serialize/SerializeXML.hpp>

using namespace gzc::util::serialize;

SerializeXML::SerializeXML( const std::string_view& file_name )
: Serialize( file_name )
{
}

SerializeXML::SerializeXML()
: SerializeXML( "data.xml" )
{
}

SerializeXML::SerializeXML( const SerializeXML& s )
: SerializeXML( s.get_file_name() )
{
}

SerializeXML& SerializeXML::operator=( const SerializeXML& s )
{
    if( this != &s )
    {
        Serialize::operator=( s );
    }
    return *this;
}

SerializeXML::~SerializeXML()
= default;
