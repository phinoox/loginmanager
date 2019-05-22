#pragma once
#include <string>
#include <map>
#include <vector>


struct CachedTemplate;

class HTemplate {
public:
    HTemplate(std::string filename);
    ~HTemplate();
    void setValue(std::string key,std::string value);
    std::string write();
private:
    CachedTemplate* cached;
   
};
