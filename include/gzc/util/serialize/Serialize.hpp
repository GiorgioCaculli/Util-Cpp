#ifndef GZC_UTIL_SERIALIZE_HPP
#define GZC_UTIL_SERIALIZE_HPP

#include <string>

namespace gzc::util::serialize
{
    class Serialize
    {
    private:
        std::string _file_name;

    public:
        explicit Serialize( const std::string& file_name );
        Serialize();
        Serialize( const Serialize & );
        Serialize& operator=( const Serialize& serialize);
        virtual ~Serialize() = 0;
        [[nodiscard]] std::string get_file_name() const;
    };
}


#endif //GZC_UTIL_SERIALIZE_HPP
