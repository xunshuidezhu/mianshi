#include <boost/asio.hpp>
#include <iostream>

void handler1(const boost::system::error_code& ec)
{
    std::cout << "5 s." << std::endl;
}

void handler2(const boost::system::error_code& ec)
{
    std::cout << "10 s." << std::endl;
}

int main()
{
    boost::asio::io_service io_service;
    boost::asio::deadline_timer timer1(io_service, boost::posix_time::seconds(5));
    timer1.async_wait(handler1);
    boost::asio::deadline_timer timer2(io_service, boost::posix_time::seconds(10));
    timer2.async_wait(handler2);
    io_service.run();
}