#ifndef SERIALIZEJSON_HPP
#define SERIALIZEJSON_HPP

#include <gzc/util/serialize/Serialize.hpp>

namespace gzc::util::serialize
{
    class SerializeJSON : public Serialize
    {
        explicit SerializeJSON( const std::string& name );
        SerializeJSON();
        SerializeJSON( const SerializeJSON& s );
        SerializeJSON& operator=( const SerializeJSON& s );
        ~SerializeJSON();
    };
}

#endif //SERIALIZEJSON_HPP
