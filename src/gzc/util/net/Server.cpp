#include <gzc/util/net/Server.hpp>

using namespace gzc::util::net;

Server::Server( unsigned short port )
: _port( port )
{
    _socket = socket( AF_INET, SOCK_STREAM, 0 );
    _address.sin_family = AF_INET;
    _address.sin_addr.s_addr = INADDR_ANY;
    _address.sin_port = htons( _port );
}

Server::Server()
: Server( 8080 )
{
}

Server::Server( const Server& other )
=default;

Server& Server::operator=( const Server& other )
=default;

Server::~Server()
=default;

bool Server::start() const
{
    if( _socket != -1 )
    {
        bind( _socket, ( struct sockaddr* )&_address, sizeof( _address ) );
        listen( _socket, 3 );
        return true;
    }
    return false;
}

template< typename T >
bool Server::receive( T buffer ) const
{
    if( _socket != -1 )
    {
        recv( _socket, buffer, 1024, 0 );
        return true;
    }
    return false;
}

template< typename T >
bool Server::transmit( T buffer ) const
{
    if( _socket != -1 )
    {
        send( _socket, buffer, strlen( buffer ), 0 );
        return true;
    }
    return false;
}

bool Server::finish() const
{
    if( _socket != -1 )
    {
        close( _socket );
        return true;
    }
    return false;
}

int Server::get_socket() const
{
    return _socket;
}

struct sockaddr_in Server::get_address() const
{
    return _address;
}

unsigned short Server::get_port() const
{
    return _port;
}
