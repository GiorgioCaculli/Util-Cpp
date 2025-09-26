#include <gzc/util/net/Client.hpp>

using namespace gzc::util::net;

Client::Client( const std::string_view& username )
: _username( username )
{
    _socket = socket( AF_INET, SOCK_STREAM, 0 );
    _address.sin_family = AF_INET;
    _address.sin_addr.s_addr = INADDR_ANY;
    _address.sin_port = htons( _port );
}

Client::Client()
: Client( "gzc" )
{
}

Client::Client( const Client& other )
: Client( other.get_username() )
{
}

Client& Client::operator=( const Client& other )
{
    if( this != &other )
    {
        _username = other._username;
    }
    return *this;
}

bool Client::start() const
{
    if( _socket != -1 )
    {
        connect( _socket, ( struct sockaddr* )&_address, sizeof( _address ) );
        return true;
    }
    return false;
}

template< typename T >
bool Client::receive( T buffer ) const
{
    if( _socket != -1 )
    {
        recv( _socket, buffer, 1024, 0 );
        return true;
    }
    return false;
}

template< typename T >
bool Client::transmit( T buffer ) const
{
    if( _socket != -1 )
    {
        send( _socket, buffer, strlen( buffer ), 0 );
        return true;
    }
    return false;
}

bool Client::finish() const
{
    if( _socket != -1 )
    {
        close( _socket );
        return true;
    }
    return false;
}

int Client::get_socket() const
{
    return _socket;
}

struct sockaddr_in Client::get_address() const
{
    return _address;
}

unsigned short Client::get_port() const
{
    return _port;
}

std::string_view Client::get_username() const
{
    return _username;
} 
