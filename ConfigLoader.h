#pragma once
#include <string>
#include <Poco/Util/IniFileConfiguration.h>


using Poco::Util::IniFileConfiguration;

class ConfigLoader {
    
public:

    static const IniFileConfiguration & getConfig();
    
    
};
