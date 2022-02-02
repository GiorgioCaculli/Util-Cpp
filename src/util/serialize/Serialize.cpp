#include <gzc/util/serialize/Serialize.hpp>
#include <utility>

using namespace gzc::util;

Serialize::Serialize( std::string file_name )
        : _file_name( std::move( file_name ))
{
}

Serialize::~Serialize()
= default;
