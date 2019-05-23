#include "UserManager.h"
#include "ConfigLoader.h"
#include <Poco/Data/MySQL/Connector.h>

#include <Poco/Data/SessionFactory.h>
#include <Poco/Format.h>


using namespace Poco::Data::MySQL;
using namespace Poco::Data::Keywords;
using namespace std;
using Poco::Data::Session;
using Poco::Data::Statement;





UserManager::UserManager()
{
Connector::registerConnector();
    
}

User UserManager::GetUser(std::string name)
{
  static string dbhost = ConfigLoader::getConfig().getString("DbConnection.host");
  static string dbuser = ConfigLoader::getConfig().getString("DbConnection.user");
  static string dbpw = ConfigLoader::getConfig().getString("DbConnection.password");
  User user;
  std::string connectString=Poco::format("host=%s;user=%s;password=%s;compress=true;auto-reconnect=false",dbhost,dbuser,dbpw);
  std::string match(name);
  Session session(Poco::Data::SessionFactory::instance().create(Connector::KEY, connectString ));
  Statement userSelect(session);
  userSelect << "Select id,name,main_id,pw from login_server.users WHERE name=?",
                into(user.id),
                into(user.name),
                into(user.main_id),
                into(user.pw),
                use(match),
                now;
 return user;   
}

