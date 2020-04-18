#include <bits/stdc++.h>

#include <boost/asio.hpp>

int main()
{
    boost::asio::ip::address addr = boost::asio::ip::address::from_string("127.0.0.1");
    boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address::from_string("127.0.0.1"), 8888);
    boost::asio::io_service io_service;
    boost::asio::ip::tcp::socket sock(io_service);
    sock.open(boost::asio::ip::tcp::v4());
    sock.connect(ep);
    sock.write_some(boost::asio::buffer("asdasd"));
}

