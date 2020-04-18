// BoostTcpClient.cpp : 定义控制台应用程序的入口点。
//

#include "boost/asio.hpp"
#include <iostream>
using namespace boost::asio;

#define PORT 1111
#define IPV6
//#define IPV4

int main()
{
    // 所有asio类都需要io_service对象
    io_service iosev;
    // socket对象
    ip::tcp::socket socket(iosev);

    // 连接端点，这里使用了本机连接，可以修改IP地址测试远程连接
#ifdef IPV4
    ip::address_v4 address = ip::address_v4::from_string("127.0.0.1");
#endif

#ifdef IPV6
    //"0:0:0:0:0:0:0:1"为IPV6的本机回环地址，类似于"127.0.0.1"
    ip::address_v6 address = ip::address_v6::from_string("0:0:0:0:0:0:0:1");
#endif
    ip::tcp::endpoint ep(address, PORT);
    // 连接服务器
    boost::system::error_code ec;
    socket.connect(ep, ec);
    // 如果出错，打印出错信息
    if (ec) {
        std::cout << boost::system::system_error(ec).what() << std::endl;
        return -1;
    }

    //循环发送和接收数据
    for (int i = 0; i < 5; ++i) {
        //发送数据
        socket.write_some(buffer("hello"), ec);
        // 接收数据
        char buf[100];
        size_t len = socket.read_some(buffer(buf), ec);
        std::cout.write(buf, len);
        sleep(500);
    }
    //发送与服务端约定好的结束语,由服务端断链
    socket.write_some(buffer("bye"), ec);

    getchar();
    return 0;
}
