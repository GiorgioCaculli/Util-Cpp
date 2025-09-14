#include <gzc/util/resource_bundle/ResourceBundle.hpp>
#include <utility>

using namespace gzc::util::resource_bundle;

ResourceBundle::ResourceBundle( std::filesystem::path  file_path, const std::locale& locale )
    : _file_path( std::move( file_path ) )
    , _locale( locale )
{
}

ResourceBundle::ResourceBundle()
    : ResourceBundle( std::filesystem::current_path(), std::locale( "en_US.UTF-8" ) )
{
}

ResourceBundle::~ResourceBundle() = default;

std::string ResourceBundle::get_string( const std::string_view& key ) const
{
    std::string value;
    for ( const auto & [ k, v ] : _keys_values )
    {
        if ( key == k )
        {
            value = v;
        }
    }
    return value;
}
