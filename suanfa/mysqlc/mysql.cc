#include "mysql.h"
#include <iostream>
#include <string.h>

DB::DB(const char* ip, const char* username, const char* pwd, const char* database)
{
    conn = new MYSQL;
    init(ip, username, pwd, database);
}

void DB::init(const char* ip, const char* username, const char* pwd, const char* database)
{
    mysql_init(conn);
    MYSQL* err;
    err = mysql_real_connect(conn, ip, username, pwd, database, 3306, NULL, 0);
    if (!err) {
        std::cout << "fail to connect db!" << std::endl;
    } else {
        std::cout << "connect to db correct!" << std::endl;
    }
}

DB::~DB()
{
    mysql_close(conn);
    delete conn;
}

char* DB::selectOne(const char* sql)
{
    int err = mysql_real_query(conn, sql, (unsigned long)strlen(sql));
    if (err) {
        std::cout << "query [" << sql << "] error !" << std::endl;
    } else {
        std::cout << "query [" << sql << "] successfully!" << std::endl;
    }
    res = mysql_store_result(conn);
    int fields = mysql_num_fields(res);
    row = mysql_fetch_row(res);
    if (row == nullptr) {
        return nullptr;
    }
    return row[0];
}

void DB::insertOne(const char* sql)
{
    int err = mysql_real_query(conn, sql, (unsigned long)strlen(sql));
    if (err) {
        std::cout << "insert data error!" << std::endl;
    } else {
        std::cout << "insert data correct!" << std::endl;
    }
}

/* int main()
{
    DB db("localhost", "root", "abcd5698298", "demo");
    char* id = db.selectOne("select id from student where name = 'XiaoBa'");
    db.insertOne("insert into student(name, sex, birth) values ('Wangba', 'man', '2001-01-01')");
    std::cout << id << std::endl;
} */