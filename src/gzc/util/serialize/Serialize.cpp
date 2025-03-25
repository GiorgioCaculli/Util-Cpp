#include <gzc/util/serialize/Serialize.hpp>
#include <utility>

using namespace gzc::util::serialize;

Serialize::Serialize( std::string file_name )
    : _file_name( std::move( file_name ) )
{
}

Serialize::Serialize()
    : Serialize( "default.data" )
{
}

Serialize::~Serialize()
= default;
