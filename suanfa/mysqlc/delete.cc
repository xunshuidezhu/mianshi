/*练习mysql数据库的删除*/
#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>

int main()
{
    MYSQL mysql;
    MYSQL_RES* res;
    MYSQL_ROW row;
    char* query;
    int flag, t;
    mysql_init(&mysql);
    if (!mysql_real_connect(&mysql, "localhost", "root", "abcd5698298", "demo", 0, NULL, 0)) {
        printf("Failed to connect to Mysql!\n");
        return 0;
    } else {
        printf("Connected to Mysql successfully!\n");
    }
    query = "delete from student  where id=1";
    /*删除，成功则返回0*/
    flag = mysql_real_query(&mysql, query, (unsigned int)strlen(query));
    if (flag) {
        printf("Delete data failure!\n");
        return 0;
    } else {
        printf("Delete data success!\n");
    }

    mysql_close(&mysql);
    return 0;
}
