#ifndef SERIALIZE_JSON_HPP
#define SERIALIZE_JSON_HPP

#include <gzc/util/serialize/Serialize.hpp>

#include <boost/json.hpp>

namespace gzc::util::serialize
{
    class SerializeJSON : public Serialize
    {
        explicit SerializeJSON( const std::string_view& file_name );
        SerializeJSON();
        SerializeJSON( const SerializeJSON& s );
        SerializeJSON& operator=( const SerializeJSON& s );
        ~SerializeJSON() override;
    };
}

#endif //SERIALIZE_JSON_HPP
