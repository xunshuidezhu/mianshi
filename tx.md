# 腾讯面经

## 算法

- 随机洗牌算法

  ```c++
  #include <cstdlib>
  #include <iostream>
  using namespace std;
   //取start到end之间的随机值
  int rand(int range_start, int range_end)
  {
  	srand((unsigned int)time(NULL));
  	return rand()%(range_end - range_start) + range_start;
  }
  
  void swap(int* a, int* b)
  {
  	int* temp;
  	*temp = *a;
  	*a = *b;
  	*b = *temp;
  }
  void shuffle(int a[], int len)
  {
  	int shuffle_key;
  	for(int i = 0; i< len; i++)
  	{
  		shuffle_key = rand(0, len);
  		swap(a[i], a[shuffle_key]);
  	}
  }
   
  int main(int argc, char *argv[])
  {
  	int a[8]={3, 5, 7, 2, 12, 1, 5, 6};
  	shuffle(a, 8);
  	for(int i = 0; i < 8; i++)
  	{
  		printf("%d", a[i]);
  	}
      system("PAUSE");
      return EXIT_SUCCESS;
  }
  ```
- 布隆过滤器:
	
	- k个哈希函数，得到k个值，去位图找，如果不都是１则一定不存在，如果是1不一定存在
## 操作系统

- 进程之间私有和共享的资源
  * 私有：地址空间，堆，全局变量，栈，寄存器
  * 共享：代码段（动态链接），进程目录，进程id，公共数据
  * 子进程复制父进程用户空间所有信息，复制内核空间绝大多数数据
- 线程之间私有和共享
  - 私有：线程栈，寄存器（每个线程有寄存器的副本），程序计数器（存放下一条指令所在单元），线程id
  - 共享：堆，地址空间，全局变量，静态变量，进程代码段，进程打开的文件描述符

## 网络

- TCP为什么是三次握手不是两次或者四次

  - 我将一次握手理解为序列号的从一端到一端的发送，server在收到client 的seq号后，既需要发送对client序列号的ack即（seq+1），还需要发送自己的seq

  - 为什么不是两次：

    socket是双向管道，因此两次握手只能保证client端正确获取server的序列号即建立从client到server的单向可靠通信，当client发送消息在网络中丢弃或者重传，server会再建立连接

  - 为什么不是四次：

    四次即server发送ack和seq拆成两次发送，这样会造成效率的浪费

- tcp可靠传输

  - 确认和超时重传
  - 流量控制
  - 拥塞控制
    + 慢启动
    + 拥塞避免
    + 快重传
    + 快恢复
  - 数据校验
  - 数据合理分片排序

- TIME_WAIT 2msl

  1.  等待client发送ack到达，如果没有收到这个ack,server要重传fin + ack，client重传ack，重新计时
  2. 防止已经失效的连接请求报文出现在本连接中．2msl会使本次连接的所有报文失效，不会出现在下次的连接中

- HTTP

  - 请求行
    1. 请求方法：get,post,put,delete,head
    2. 请求对应的URL地址：和请求头的Host:localhost:8888组成完整的URL请求
    3. 协议名称版本号：HTTP/1.1
  - 请求头
    + 属性名：属性值，服务端据此获取客户端信息，与缓存相关都存在此
  - 请求体
  - 响应行
    - 报文协议版本：HTTP/1.1
    - 状态码及状态描述：200 OK
  - 响应头
  - 响应体

- cookie

- HTTPS

  - HTTP安全问题：使用明文，内容可能被窃听

  - 不验证通信方身份，有可能伪装
  - 无法证明报文的完整性  
  - 让HTTP先和SSL通信，再由SSL和TCP通信，HTTPS使用了隧道进行通信
  - 加密：
  	- 对称密钥加密
  
## Redis
- 渐进式哈希:
  
  - 扩展或者收缩哈希表需要rehash，这个过程不是一次性完成，因为如果哈希表的键值对很大，服务器可能会停止服务
  - 让字典同时拥有两个哈希表
  - 维持一个索引计数器便来那个，从一个哈希表rehash到另一个哈希表，index+1
  - 此时对字典的增删改查发生在key所在的那个哈希表，先在第一个表查，没有就到第二个表
  - 都迁移完毕，index = -1
  
- RDB

  - save:阻塞当前进程直到全部持久化
  - bgsave:进行fork操作创建子进程,RDB由子进程完成，完成之后自动关闭，只阻塞在Fork阶段
    - 如果从节点执行全量复制，主节点自动执行bgsave，生成RDB文件，并发送给主节点

  - RDB是一个很紧凑的二进制文件适合全量复制和备份，还原很快，数据恢复快于AOF
  - 无法做到实时持久化

- AOF
  
- 记录每次写操作，重启时重新执行即可复原以达到持久化
  - 

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  
  
  
  


