#pragma once
#include <string>

struct User {
    int id;
    std::string name;
    std::string main_id;
    std::string pw;
};

class UserManager
{
private:
    static UserManager *instance;
    UserManager();
public:
    
    static UserManager &getInstance()
    {
       static UserManager instance;
        return instance;

    };
    User GetUser ( std::string name,std::string pw );

};
