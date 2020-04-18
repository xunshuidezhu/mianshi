#include "mysql.h"

#include <map>
#include <string>

class User {
private:
    std::string userName;
    std::string pwd;
    std::map<std::string, std::string> memcache;

    DB* db;

public:
    User(std::string, std::string);
    ~User();
    int login(std::string name, std::string pwd);
    void regist(std::string name, std::string pwd);
};