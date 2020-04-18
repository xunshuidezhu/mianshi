/*练习mysql数据库的查询*/
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
    query = "select * from student";
    /*查询，成功则返回0*/
    flag = mysql_real_query(&mysql, query, (unsigned int)strlen(query));
    if (flag) {
        printf("Query failed!\n");
        return 0;
    } else {
        printf("[%s] made...\n", query);
    }

    /*mysql_store_result讲全部的查询结果读取到客户端*/
    res = mysql_store_result(&mysql);
    /*mysql_fetch_row检索结果集的下一行*/
    while (row = mysql_fetch_row(res)) {
        /*mysql_num_fields返回结果集中的字段数目*/
        for (t = 0; t < mysql_num_fields(res); t++) {
            printf("%s\t", row[t]);
        }
        printf("\n");
    }
    mysql_close(&mysql);
    return 0;
}
