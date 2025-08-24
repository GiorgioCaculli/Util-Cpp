#ifndef LIBUTIL_CPP_SERIALIZE_HPP
#define LIBUTIL_CPP_SERIALIZE_HPP

#include <string>


namespace gzc::util::serialize
{
    class Serialize
    {
    private:
        std::string _file_name;

    public:
        explicit Serialize( std::string file_name );

        Serialize();

        Serialize( const Serialize & );

        Serialize& operator=( const Serialize& serialize);

        ~Serialize();

        [[nodiscard]] std::string get_file_name() const;
    };
}


#endif //LIBUTIL_CPP_SERIALIZE_HPP
