#include <string.h>
#include <iostream>
#include "user.h"


using namespace std;

int main()
{
    User user("zhangsan", "123");
    user.login("zhangsan", "123");
    user.regist("www", "1");
    user.login("www", "1");
}