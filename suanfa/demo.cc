#include <iostream>
#include <string>

#include "mysql/mysql.h"
#include <bits/stdc++.h>

using namespace std;

//全局变量声明
MYSQL mysql;
MYSQL_RES* res;
MYSQL_ROW row;
unsigned int num_fields;

//连接数据库
bool ConnectDatabase()
{
    //初始化数据库
    mysql_init(&mysql);

    //连接到MySQL server
    if ((mysql_real_connect(&mysql, "127.0.0.1", "root",
            "abcd5698298", "demo", 3306, NULL, 0))) {
        printf("Error connecting to database:%s\n", mysql_error(&mysql));
        return false;
    } else {
        printf("connected...\n");
        return true;
    }
}

//查询数据
void QueryData(std::string& query_sql_string)
{
    const char* query_buffer = query_sql_string.c_str();

    if(mysql_query(&mysql,query_buffer))
    {
        printf("Query failed(%s)\n", mysql_error(&mysql));
    }
    else
    {
        printf("Query success\n");

        res = mysql_store_result(&mysql);
        num_fields = mysql_num_fields(res);
        while ((row = mysql_fetch_row(res)) != NULL) {
            if (row[6] != NULL) {
                std::string temp_string = string(*row);
                // ConvertUTF8ToGBK(temp_string);
                std::cout << temp_string << std::endl;
            }
        }
        mysql_free_result(res); //释放内存
    }
}

int main()
{
    ConnectDatabase();
    std::string query_string = "select * from student;";
    QueryData(query_string);
    mysql_close(&mysql);
    return 0;
}
