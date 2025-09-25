#ifndef GZC_UTIL_NET_SERVER_HPP
#define GZC_UTIL_NET_SERVER_HPP

#include <cstring>
#include <string_view>
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

namespace gzc::util::net
{
    class Server
    {
    private:
        int _socket = 0;
        struct sockaddr_in _address;
        unsigned short _port;
    public:
        explicit Server( unsigned short port );
        Server();
        ~Server();
        Server( const Server& other );
        Server& operator=( const Server& other );
        bool start() const;
        bool receive( char buffer[ 1024 ] ) const;
        bool transmit( const char buffer[ 1024 ] ) const;
        bool finish() const;
        int get_socket() const;
        struct sockaddr_in get_address() const;
        unsigned short get_port() const;
    };
}

#endif // GZC_UTIL_NET_SERVER_HPP