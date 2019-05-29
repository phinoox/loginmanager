#pragma once
#include <string>

struct User {
    int id;
    std::string name;
    std::string main_id;
    std::string pw;
    std::string secret;
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
    User GetUser ( std::__cxx11::string name );
    void SaveUser(User user);
};
