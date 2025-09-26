#ifndef GZC_UTIL_NET_CLIENT_HPP
#define GZC_UTIL_NET_CLIENT_HPP

#include <cstring>
#include <string_view>
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <string_view>
namespace gzc::util::net
{
    class Client
    {
    private:
        std::string_view _username;
        int _socket = -1;
        struct sockaddr_in _address;
        unsigned short _port;
    public:
        explicit Client( const std::string_view& username );
        Client();
        Client( const Client& other );
        Client& operator=( const Client& other );
        virtual ~Client() = 0;
        bool start() const;
        template< typename T >
        bool receive( T buffer ) const;
        template< typename T >
        bool transmit( T buffer ) const;
        bool finish() const;
        int get_socket() const;
        struct sockaddr_in get_address() const;
        unsigned short get_port() const;
        std::string_view get_username() const;
    };
}

#endif // GZC_UTIL_NET_CLIENT_HPP