#ifndef GZC_UTIL_SERIALIZE_HPP
#define GZC_UTIL_SERIALIZE_HPP

#include <string>
#include <string_view>

namespace gzc::util::serialize
{
    class Serialize
    {
    private:
        std::string _file_name;

    public:
        explicit Serialize( const std::string_view& file_name );
        Serialize();
        Serialize( const Serialize& serialize );
        Serialize& operator=( const Serialize& serialize);
        virtual ~Serialize() = 0;
        template< class T >
        bool save( T t ) const;
        template< class T>
        T load( const std::string_view& file_name ) const;
        [[nodiscard]] std::string get_file_name() const;
        void set_file_name( const std::string_view& file_name );
    };
}


#endif //GZC_UTIL_SERIALIZE_HPP
