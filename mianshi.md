# 面试总结

## ​ 算法题

- 常用算法

  - 快慢指针
  - dfs bfs
  - 二分，注意边界
  - dp
  - 位运算，异或为主

- 链表有环,求入口点

- 原地翻转数组

- 反转链表

- 随机散列

- 堆排，桶排,快排，归并

- 不借助临时变量交换a, b

  ```c
  b = a - b;
  a = a - b;
  b = a + b
  ```

  ```c
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
  #利用 a ^ b ^ b = a;
  #注意 a != b
  ```

  

- 逆序对个数 一个大根堆一个小根堆

- BST倒数第k小节点 leetcode230　

- 海量数据处理，大数据日志找最多 https://blog.csdn.net/weixin_34161029/article/details/92441368

- 查找二叉树两个节点的公共父节点

- 两个链表的第一个公共节点

- 括号匹配

- top k　partition 或者大根堆小根堆

- 非递归前中后

- 判断两个链表是否相交

- 最长上升子序列

- 随机洗牌算法

  ```c
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

  

## **linux**

- 进程线程区别，进程间通信,各自特点

- 在Linux中，每个进程都有属于自己的进程控制块（PCB）和地址空间（Addr Space），并且都有一个与之对应的页表，负责将进程的虚拟地址与物理地址进行映射，通过内存管理单元（MMU）进行管理。两个不同的虚拟地址通过页表映射到物理空间的同一区域，它们所指向的这块区域即共享内存。

  共享内存的通信原理示意图：

  对于上图我的理解是：当两个进程通过页表将虚拟地址映射到物理地址时，在物理地址中有一块共同的内存区，即共享内存，这块内存可以被两个进程同时看到。这样当一个进程进行写操作，另一个进程读操作就可以实现进程间通信。但是，我们要确保一个进程在写的时候不能被读，因此我们使用信号量来实现同步与互斥。

  对于一个共享内存，实现采用的是引用计数的原理，当进程脱离共享存储区后，计数器减一，挂架成功时，计数器加一，只有当计数器变为零时，才能被删除。当进程终止时，它所附加的共享存储区都会自动脱离。

- 管道实现原理n

- 用户态　内核态

- linux调试多线程，多进程

- TLB是一种页表cache，是特殊的寄存器，减少一次访问内存

- 高并发，**epoll**工作模式，epoll和select比较，epoll遇到的问题

  - 

  - select, poll返回整个用户注册的事件集合，而且把句柄和事件注册到一起，所以每次索引文件就绪的时间复杂度是O(n)，而epoll把句柄和事件分开，注册到内核红黑树上，时间复杂读O(lgN)，将就绪事件放在链表上，通过回调唤醒，回调在epoll_ctl注册到句柄，用户太只需要拷贝就绪链表就可以，复杂度为O(1)
  - epoll适合注册很多句柄但是发生事件不多，如果注册句柄很少还频繁发生，会反复触发回调函数，回调的开销可能大于遍历的开销

  - 水平工作机制（LT）
    - 对于读，只要缓冲区不为空，返回就绪
    - 对于写，只要缓冲区不满，返回就绪
  - 边沿工作机制（ET）
    - 有不可读变为可读，缓冲区由空变为不空，缓冲区有新数据到达
    - 由不可写变为可写

- epoll的问题

  - ET应该是非阻塞的，如果是阻塞的读或写会因为没有后续事件而阻塞
  - EPOLLONESHOT，只触发一次，一个线程读取完Socket数据之后开始处理数据，这时候这个socket又来了数据，会唤醒另一个线程，epolloneshot保证唤醒一次
  - LT可以不立即处理，ET必须立即处理事件

- 自旋锁和读写锁,互斥锁，信号量，大内核索,屏障，cas

- fork vfork　fork父子进程执行顺序不一定，vfork先执行子进程，子进程在父进程的地址空间运行，不可以写，父子进程一样的虚拟内存和物理内存不需要拷贝页表，父进程阻塞等待子进程执行结束之后再执行．fork之后父子进程在没有写之前，共用一样的物理内存，但是不一样的虚拟内存，fork会复制父进程的页表．

- threadlocal

- 零拷贝　cpu不执行拷贝数据从一块到另一块的操作.

  - 一次网络io数据:
    1. 用户调用read，系统调用陷入到内核态（一次上下文切换）
    2. 向磁盘请求数据
    3. 通过DMA将磁盘数据读取到内核缓冲区
    4. read系统调用返回到用户态，数据从内核缓冲区拷贝到用户缓冲区（二次上下文切换）
    5. write系统调用，将数据写入到内核socket缓冲区（三次上下文切换）
    6. write系统调用返回（四次上下文切换）
    7. DMA将内核socket缓冲区拷贝到协议栈(四次数据拷贝)
  - 零拷贝过程：
    1. 第二次和第三次上下文切换和数据拷贝是多余的
    2. 用sendfile进行优化
    3. sendfile系统调用，进入内核态（一次上下文切换）
    4. 通过DMA将数据从磁盘读到内核缓冲区（１）
    5. 从内核缓冲区拷贝到socket缓冲区（２）
    6. sendfile返回，从内核态进入用户态（二次上下文切换）
    7. DMA将socket缓冲区数据拷贝到网络协议栈（３次数据拷贝）
  - 还可以用mmap省去用户和内核的拷贝，用户和内核共用设备内存

- 虚拟内存能否重叠：可以重叠，虚拟内存重叠，物理内存不一定重叠，虚拟内存在磁盘，页表在内存，TLB快表是寄存器，MMU是硬件，页表把虚拟内存转换为物理地址，当物理地址不在内存发生缺页

- unordered map   map

- copy on write写时拷贝，当fork之后，exec之前父子进程不同的进程地址空间但是共用一样的物理空间，exec之后代码段不一样，如果写但是不exec则数据段堆栈再分配空间并拷贝父进程

- **线程池负载 ****项目必问

- 判断内存泄漏，避免内存泄漏 重载operator new计数

- 为什么要有字节对齐

  1. CPU访问数据效率问题．还可以有效节省内存空间．假设处理器总是从内存中获取8个字节，地址必须是8的倍数。如果我们可以保证任何double将被对齐，使其地址是8的倍数，那么可以用一个内存操作读取或写入该值。否则，我们可能需要执行两次内存访问，因为对象可能被分成两个8字节的内存块。
  2. 另一方面，用于实现多媒体操作的一些SSE指令对于未对齐的数据将不能正确工作。

- 怎么控制字节对齐

  - #pragma pack(n)
  - 不能用memcmp比较，因为对齐填充的是随机值

- **时间轮，小根堆计时器**

- 虚拟内存和物理内存都是以页为单位,4k字节

- malloc, new，operator new, placement new brk sbrk mmap

- ldd 查看程序运行所需的共享库

- cut分割字符, grep, sed, awk

- 如何避免内存泄漏  RAII等，如何检测内存泄漏　重载operator new

- git

  ```git
  git add .
  git commit -m " "
  git checkout 更换分支
  git status -s状态
  git merge 合并分支
  git fetch　拉远程主机最新分支
  git pull = git fetch + git merge
  ```

- 线程共有和私有数据

  - 公有数据
    - 堆，进程地址空间，代码段，进程文件描述符，全局变量，静态变量
  - 私有数据
    - 线程栈．线程私有数据，寄存器，程序计数器，线程, __thread(thread_local c++11关键字)线程局部存储每个线程有一份独立实体相互不干扰

## 网络

- TCP四次挥手，为什么四次挥手

- time_wait

- TCP发大包出现情况，UDP会么　缓冲区小于包大小，粘包，　UDP不会粘包会丢失数据

- udp还是tcp选择：
  - tcp
    - 数据要求完整不能丢包，不许发生错误
    - 有限连接
  - udp
    - 大量连接，tcp会性能下降
    - 实时性，允许丢包, 游戏 直播
  
- 网络编程字节序问题出现的原因

- web安全攻击

- HTTP和HTTPS不同　HTTP + SSL

  - HTTP请求是明文传输，HTTPS传输的是密文

  - 对称加密　非对称加密

    - 非对称加密是加密和解密不用一把密钥

  - HTTPS过程

    1. 客户端向服务端发送HTTPS请求，连接到443端口
    2. 服务端保留两把密钥，公钥可以发送，自己保留私钥
    3. 服务端将公钥发给客户端
    4. 客户端收到公钥进行检查
       - 验证服务端发送的数字证书的合法性
    5. 客户端发起HTTPS第二个HTTP请求，将加密之后的客户端密钥发送给服务端

    6. 服务端用私钥进行解密，获取客户端密钥，用客户端密钥对数据进行加密
    7. 加密后的密文发送给客户端
    8. 客户端用密钥解密，得到数据

- arp协议, icmp协议

## 数据库

- 数据库查询优化方法

- 索引的实现

- 数据库范式

- linux指令

- 聚簇索引，非聚簇索引　

  - 聚簇索引，索引的顺序就是数据存放的顺序（物理顺序），只要索引是相邻的，那么对应的数据一定也是相邻地存放在磁盘上的。一张数据表只能有一个聚簇索引。（一个数据页中数据物理存储是有序的）

  - 非聚簇索引通过叶子节点指针找到数据页中的数据，所以非聚簇索引是逻辑顺序。

- 怎么添加索引　主键索引索引着数据，然后普通索引索引着主键ID值(这是在innodb中，但是如果是myisam中，主键索引和普通索引是没有区别的都是直接索引着数据)

  ```sql
  alter table `student` add primary key(`id`) #增加主键索引
  ALTER TABLE `table_name` ADD UNIQUE (`id`)#增加唯一索引
  ALTER TABLE `table_name` ADD INDEX index_name ( `id` )#增加普通索引
  ALTER TABLE `table_name` ADD INDEX index_name ( `column1`, `column2`, `column3` )#增加多列索引
  
  ```

- mysql主从同步

- mysql查找慢的原因，怎么优化

- 乐观锁，悲观锁

  - 乐观锁总是认为不会产生并发问题，每次去取数据不会认为有其他线程对数据进行修改，因此不会上锁，但是在更新时会判断其他线程在这之前有没有对数据进行修改，使用版本号或者CAS操作
  - 悲观锁，每次拿数据都认为别人会修改，所以每次拿数据都会上锁

- 脏读，不可重复读，幻读

  - 脏读：一个事务对数据库进行了修改，还未提交时，另一个事务对数据库读
  - 不可重复读：在一个事务内对一个数据多次读．在这个事务还未结束时，另一个事务对数据库进行了修改，两次读的数据可能是不一样的
  - 幻读：第一个事物对数据库表进行了处理，这时候第二个事务向数据库插入数据，第一个事务发现还有未修改的数据

- 隔离级别：

  - 读未提交:事务中的修改即使未提交，对其他事务也是可见的
  - 读已提交：一个事务只能读取已经提交的修改
  - 可重复读：保证在同一个事务中多次读取的数据是一样的
  - 可串行化：强制事务串行执行，不会出现一致性问题，需要加锁实现
  
- mvcc

  - 用于实现可提交读和可重复读，可串行化需要加锁不能用mvcc实现
  - 读读不互斥，读写再互斥
  - mvcc规定只能读取已经提交的快照
  - 系统版本号是一个递增的数字，每开始一个新的事务，系统版本号就会递增
  - 事物版本号，事务开始时的系统版本号
    - select
      1. 只查找版本早于当前事务版本号的行（行的系统版本号，小于或等于当前事务的系统版本号），可以保证事务读取的行，要么实在事务还是之前已经存在的要么是事务自身修改过的
      2. 行的删除版本号，要么未定义，要么大于当前事务版本号．事务读取到的行，在事务开始之前未删除
    - insert
      - 为插入的每一行数据吧保存当前的系统版本号作为行版本号
    - delete
      - 删除的每一行保存当前的系统版本号作为行的删除标志
    - update
      - 插入一行新数据，保存当前系统版本号作为新插入行的版本号

## 数据结构

- 哈希冲突
- 跳表

## C++

- 虚函数表，虚继承

- 指针，引用

- main函数执行之前：全局，静态变量完成初始化，arg argv参数传完毕，堆内存栈内存完成初始化，io初始化

  代码列子

  ```c++
  class Demo {
  public:
  	Demo()
      {
  		cout << "demo" << endl;
      }
  };
  int foo()
  {
      cout << "s" << endl;
      return 0;
  }
  
  int x = foo();
  Demo d;
  
  int main()
  {
      return 0;
  }
  ```

- 如何防止内存泄漏

- 静态库动态库,静态库　动态库的区别

  - ```makefile
    all:sum print lib main clean
    main:./main.cc ./lib/libxxx.a
    	g++ main.cc -I include -L lib -lxxx -o main.prog
    sum:./src/sum.cc ./include/sum.h
    	g++ -I include ./src/sum.cc -c -o sum
    print:./src/print.cc ./include/print.h
    	g++ -I include ./src/print.cc -c -o print
    lib:./sum.o ./print.o
    	ar rcs ./lib/libxxx.a ./sum.o ./print.o
    clean:
    	rm -f ./*.o
    
    ```
    
- 静态库是链接到可执行文件，程序运行时不需要静态库，但是源文件需要重新编译，做成静态库可执行文件体积大，不需要依赖静态库
  - 动态库在目标文件编译之后不需要链接，而是程序运行时动态链接，程序运行时需要动态库存在，因此源文件不需要重新编译，做成动态库可执行文件体积小，但是依赖动态库．在调用函数时，根据函数映射表找到函数
  
- vector内存分配，分配一个２倍大小数组，把原数组元素copy过去，所以元素引用不可以，因为内存可能发生变化　1.引用不满足值语义。值语义(value sematics)指的是对象的拷贝与原对象无关，就像拷贝 int 一样。
   2.就算可以你如何初始化，你不可能里面存放引用为空的引用。

- 两个.h同时定义一个static变量会怎样　如果有一个源文件引用两个头文件编译失败，如果是两个源文件分别引用一个，然后编译生产一个elf文件，则没有问题，如果不定义为Static则链接会出错报重定义

- static函数，static函数不能在本代码文件以外的代码文件使用，普通函数默认是extern的可以被别的代码文件使用，其他文件可以定义相同名字的函数 https://www.cnblogs.com/nzbbody/p/3413169.html

- 虚表，虚继承，虚指针，虚基类表指针，虚基类表	

- 虚表　每个类有一个虚表，每个对象有一个虚指针,虚表在数据段，虚函数在代码段https://blog.csdn.net/primeprime/article/details/80776625			

- 虚继承，虚基类类表，指针 虚基类表存的是虚基类相对子类的偏移，虚函数表存的是虚函数指针，虚继承维持一份拷贝，虚继承只有虚基类指针没有虚表指针，通过虚基类表找到基类虚表

- 重载重写多太　重载函数签名不同　多太：运行期，预编译期模板,函数重载

- 手写string类

- 单例双检查

  ```c++
  class Singlenton {
  private:
      Singlenton()
      {
      }
  
      Singlenton(const Singlenton&)
      {
      }
  
      Singlenton& operator=(const Singlenton&)
      {
      }
  
      mutex m;
  
  public:
      static Singlenton* single;
  
      Singlenton* getSingenton()
      {
          if (single != nullptr) {
              m.lock();
              if (single != nullptr) {
                  single = new Singlenton;
              }
              m.unlock();
          }
          return single;
      }
  };
  
  Singlenton* Singlenton::single;
  ```

- 深拷贝　浅拷贝

- memcpy, memmove,strcpy　手写

  - strcpy以'\0'结尾，memcpy memmove以num结尾
  - memmove可以解决内存覆盖，memcpy不可以

  ```c++
  char * strcpy(char * dest, const char * src) // 实现src到dest的复制
  {
  
  　　if ((src == NULL) || (dest == NULL)) //判断参数src和dest的有效性
  	{
  　　　　　　return NULL;
  
  　　}
  
  　　char *strdest = dest;        //保存目标字符串的首地址
  
  　　while ((*strDest++ = *strSrc++)!='\0'); //把src字符串的内容复制到dest下
  
  　　return strdest;
  
  }
  
  void *memcpy(void *memTo, const void *memFrom, size_t size)
  
  {
  
  　　if((memTo == NULL) || (memFrom == NULL)) //memTo和memFrom必须有效
  
           return NULL;
  
  　　char *tempFrom = (char *)memFrom;             //保存memFrom首地址
  
  　　char *tempTo = (char *)memTo;                  //保存memTo首地址      
  
  　　while(size -- > 0)                //循环size次，复制memFrom的值到memTo中
  
         　　*tempTo++ = *tempFrom++ ;  
  
  　　return memTo;
  
  }
  ```

- 析构函数不要抛出异常

  - 如果析构函数抛出异常，则异常点之后的程序不会执行，如果析构函数在异常点之后执行了某些必要的动作比如释放某些资源，则这些动作不会执行，会造成诸如资源泄漏的问题。
  - 通常如果发生异常会调用析构函数来释放资源，如果此时析构函数本身抛出异常，则前一个异常没有处理又来了新的异常
  
- 函数调用过程

   + 将参数从右向左入栈

   + 返回地址入栈，将当前代码区调用指令的下一条指令地址压入栈中，供函数返回时继续执行

   + 代码区跳转，执行调用函数

   + 栈帧调整

     - EBP(基址指针寄存器，内存里面存放一个指针)系统栈最上面的栈帧的底部，ESP栈顶寄存器内存里面存指针，指向系统栈最上面的栈帧的顶部

     - 保存当前栈帧状态值，以备后面恢复本栈帧使用(EBP入栈)
     - 将当前栈帧切换到新栈帧（将ESP装入EBP，更新栈帧底部）
     - 给新栈帧分配空间(把EBP减去所需空间大小，抬高栈顶)

- c++11特性

- 四种cast

   - const_cast 消除常量性
   - static_cast 
     - 没有运行时类型检查　无法保证安全性
     - 基本数据类型，或者non const -> const(const -> non const必须const cast)
     - 空指针转换为目标类型指针
     - 任何类型转为void
     - 子类指针转父类指针
   - dynamic_cast:只用于对象和引用，父类指针转换为子类指针,要求父类有虚函数
   - reinpreter_cast:指针引用函数指针算数类型成员指针，二进制拷贝．

- 智能指针

- 什么是循环引用，为什么weak_ptr可以解决循环引用

## 中间件

- protobuf原理

- gRpc原理
- Consul原理
- redis集群，三种启动方式
- 一致性哈希，虚拟哈希槽
- 数据倾斜
- 微服务，熔段，限流，api网关，go-micro

##　 智力题

- 对一批编号为1-100，全部开关朝上（开）的灯进行以下操作：凡是1的倍数反方向拨一次开关；2的倍数反方向又拨一次开关；3的倍数反方向又拨一次开关……问：最后为关熄状态的灯的编号是哪些？
- 赛马问题
- 有两根不均匀的香，烧完一根要1小时，怎么利用这两根香得到15分钟的时间？为什么这样是对的，能证明不
- 一个长方形(体)蛋糕中间有一个长方形(体)的空心位置，这个空心的长方形(体)是可见且贯穿的，怎么一刀分成平均的两份
- 鸡蛋掉落 leetcode887 二分法

