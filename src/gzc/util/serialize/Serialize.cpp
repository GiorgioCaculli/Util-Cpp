#include <gzc/util/serialize/Serialize.hpp>

using namespace gzc::util::serialize;

Serialize::Serialize( const std::string_view& file_name )
{
    set_file_name( file_name );
}

Serialize::Serialize()
    : Serialize( "default.dat" )
{
}

Serialize::Serialize( const Serialize& serialize )
    : Serialize( serialize.get_file_name() )
{
}

Serialize& Serialize::operator=( const Serialize& serialize )
{
    if( this != &serialize )
    {
        set_file_name( serialize.get_file_name() );
    }
    return *this;
}

Serialize::~Serialize()
= default;

template< class T>
bool Serialize::save( T t ) const
{
    return false;
}

template< class T>
T Serialize::load( const std::string_view& file_name ) const
{
    return nullptr;
}

std::string Serialize::get_file_name() const
{
    return _file_name;
}

void Serialize::set_file_name( const std::string_view& file_name )
{
    _file_name = file_name;
}
