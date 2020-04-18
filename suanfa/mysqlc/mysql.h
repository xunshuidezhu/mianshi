#include <mysql/mysql.h>

class DB {
private:
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    void init(const char* ip, const char* username, const char* pwd, const char* database);

public:
    DB(const char* ip, const char* username, const char* pwd, const char* database);
    ~DB();
    char* selectOne(const char* sql);
    void insertOne(const char* sql);
};