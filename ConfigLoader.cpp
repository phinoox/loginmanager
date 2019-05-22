#include "ConfigLoader.h"
#include <Poco/Util/Application.h>

using Poco::AutoPtr;


const Poco::Util::IniFileConfiguration & ConfigLoader::getConfig()
{
    Poco::Util::Application & app = Poco::Util::Application::instance();
    
static AutoPtr<IniFileConfiguration> config;
  if(config.isNull()){
    AutoPtr<IniFileConfiguration> conf(new IniFileConfiguration("../config/config.ini"));
    config = conf;
  }
  if(config.isNull())
      app.logger().information("could not load config");
  return *config;
    
}

