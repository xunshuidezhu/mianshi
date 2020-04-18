#include <boost/asio.hpp>
#include <chrono>
#include <iostream>
#include <thread>

void handler1(const boost::system::error_code& ec)
{
    std::cout << "5 s." << std::endl;
}

void handler2(const boost::system::error_code& ec)
{
    std::cout << "5 s." << std::endl;
}

boost::asio::io_service io_service;
boost::asio::io_service io;
void run()
{
    io_service.run();
}

void routine(const boost::system::error_code& ec)
{
    std::cout << "xxx" << std::endl;
}

int main()
{
    boost::asio::deadline_timer t(io, boost::posix_time::seconds(2));
    t.async_wait(routine);
    io.run();
    boost::asio::deadline_timer timer1(io_service, boost::posix_time::seconds(5));
    timer1.async_wait(handler1);
    boost::asio::deadline_timer timer2(io_service, boost::posix_time::seconds(5));
    timer2.async_wait(handler2);
    std::thread thread1(run);
    std::thread thread2(run);
    thread1.join();
    thread2.join();
}