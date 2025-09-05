#ifndef UTIL_RESOURCE_BUNDLE_HPP
#define UTIL_RESOURCE_BUNDLE_HPP

#include <filesystem>
#include <string>
#include <locale>
#include <vector>

namespace gzc::util::resource_bundle
{
    class ResourceBundle
    {
    private:
        std::filesystem::path _file_path;
        std::locale _locale;
        std::vector< std::pair< std::string, std::string > > _keys_values;
    public:
            ResourceBundle( std::filesystem::path  file_path, const std::locale& locale );
        ResourceBundle();
        ~ResourceBundle();
        [[nodiscard]] std::string get_string( const std::string& key ) const;
    };
}

#endif //UTIL_RESOURCE_BUNDLE_HPP
