#include <gzc/util/serialize/Serialize.hpp>

#include <iomanip>
#include <iostream>
#include <fstream>
#include <filesystem>

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
    if( t == nullptr )
    {
        return false;
    }
    std::ofstream file;
    file.open( std::filesystem::path( get_file_name() ), std::ios::out | std::ios::binary );
    do
    {
        file.close();
    }
    while( file.is_open() );
    return false;
}

template< class T>
T Serialize::load( const std::string_view& file_name ) const
{
    std::ifstream file;
    file.open( std::filesystem::path( file_name ), std::ios::in );
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
