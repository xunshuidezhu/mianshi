学习提纲

- 分布式事务，spring事务

- redis分布式锁，zookeeper分布式锁

- kafka

- cloud eureka hytrix

- concurthashmap hashmap hashtable

- hashmap 1.7 1.8

- 头插法是操作速度最快的，找到数组位置就直接找到插入位置了，但是课程里演示过， jdk8之前hashmap这种插入方法在并发场景下如果多个线程同时扩容会出现循环列表。 jdk8开始hashmap链表在节点长度达到8之后会变成红黑树，这样一来在数组后节点长 度不断增加时，遍历一次的次数就会少很多很多（否则每次要遍历所有），相比头插法 而言，尾插法操作额外的遍历消耗已经小很多了，也可以避免之前的循环列表问题。 （同时如果变成红黑树，也不可能做头插法了）

- # ConcurrentHashMap 1.7和1.8的区别

https://www.cnblogs.com/lezon1995/p/11219555.html

- equal hashcode 

- aqs 

- 线程池参数，四种线程池

- volatile sync renteelock

  - synchronized 竞争锁时会一直等待；ReentrantLock 可以尝试获取锁，并得到获取结果
  - synchronized 获取锁无法设置超时；ReentrantLock 可以设置获取锁的超时时间
  - synchronized 无法实现公平锁；ReentrantLock 可以满足公平锁，即先等待先获取到锁
  - synchronized 控制等待和唤醒需要结合加锁对象的 wait() 和  notify()、notifyAll()；ReentrantLock 控制等待和唤醒需要结合 Condition 的 await() 和  signal()、signalAll() 方法
  - synchronized 是 JVM 层面实现的；ReentrantLock 是 JDK 代码层面实现
  - synchronized 在加锁代码块执行完或者出现异常，自动释放锁；ReentrantLock 不会自动释放锁，需要在 finally{} 代码块显示释放

- http head内容　　　http1..1 http2.0  http长链接　tcp长链接　https加密证书怎么获取，客户端保存公还是私钥

- serverlet生命周期

- 动态代理　cglib

- 