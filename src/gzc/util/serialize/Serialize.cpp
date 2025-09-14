#include <gzc/util/serialize/Serialize.hpp>

using namespace gzc::util::serialize;

Serialize::Serialize( const std::string& file_name )
    : _file_name( file_name )
{
}

Serialize::Serialize()
    : Serialize( "default.data" )
{
}

Serialize::Serialize( const Serialize & serialize )
    : Serialize( serialize.get_file_name() )
{
}

Serialize& Serialize::operator=( const Serialize& serialize )
{
    if( this != &serialize )
    {
        _file_name = serialize._file_name;
    }
    return *this;
}

Serialize::~Serialize()
= default;

std::string Serialize::get_file_name() const
{
    return _file_name;
}
