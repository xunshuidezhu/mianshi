#include <iostream>
#include <mysql/mysql.h>
#include <string.h>

using namespace std;

int main()
{
    MYSQL* db = new MYSQL();
    MYSQL_RES* res;
    MYSQL_ROW row;
    mysql_init(db);
    MYSQL* err;
    err = mysql_real_connect(db, "localhost", "root", "abcd5698298", "demo", 0, NULL, 0);
    if (!err) {
        cout << "fail to connect db !" << endl;
    } else {
        cout << "connect to db successfully!" << endl;
    }
    int flag;
    char* query = "select * from student ;";
    flag = mysql_real_query(db, query, (unsigned long)strlen(query));
    if (flag) {
        cout << "query [" << query << "] error!" << endl;
    } else {
        cout << "query [" << query << "] successfully!" << endl;
    }
    res = mysql_store_result(db);
    int fields = mysql_num_fields(res);
    while (row = mysql_fetch_row(res)) {
        for (int i = 0; i < fields; i++) {
            cout << row[i] << "  ";
        }
        cout << endl;
    }
    mysql_close(db);
    delete db;
    return 0;
}