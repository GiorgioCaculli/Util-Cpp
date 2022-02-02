#ifndef LIBUTIL_CPP_SERIALIZE_HPP
#define LIBUTIL_CPP_SERIALIZE_HPP

#include <string>

namespace gzc
{
    namespace util
    {
        class Serialize
        {
        private:
            std::string _file_name;
        public:
            explicit Serialize( std::string file_name );

            ~Serialize();
        };
    }
}

#endif //LIBUTIL_CPP_SERIALIZE_HPP
