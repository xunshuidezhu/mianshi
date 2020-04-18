#include "user.h"
#include "string.h"

#include <iostream>

User::User(std::string name, std::string password)
    : userName(name)
    , pwd(password)
{
    db = new DB("localhost", "root", "abcd5698298", "demo");
}

User::~User()
{
    delete db;    
}

int User::login(std::string name, std::string pwd)
{
    std::string sql = "select pwd from user where name = '" + name + "';";
    char* password = db->selectOne(sql.c_str());
    if (password == nullptr) {
        std::cout << "the user need regist" << std::endl;
        return 0;
    } else if (strcmp(pwd.c_str(), password)) {
        std::cout << "password is not correct, please try again" << std::endl;
        return 0;
    } else if (!strcmp(pwd.c_str(), password)) {
        std::cout << name << " login successfully" << std::endl;
    }
}

void User::regist(std::string name, std::string pwd)
{
    std::string sql = "insert into user(name, pwd) values ('lisi', 'asdasd')";
    db->insertOne(sql.c_str());
}



