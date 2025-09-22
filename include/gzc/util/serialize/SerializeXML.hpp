#ifndef SERIALIZE_XML_HPP
#define SERIALIZE_XML_HPP

#include <gzc/util/serialize/Serialize.hpp>

namespace gzc::util::serialize
{
    class SerializeXML : public Serialize
    {
        explicit SerializeXML( const std::string_view& file_name );
        SerializeXML();
        SerializeXML( const SerializeXML& s );
        SerializeXML& operator=( const SerializeXML& s );
        ~SerializeXML() override;
    };
}

#endif //SERIALIZE_XML_HPP