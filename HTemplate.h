#pragma once
#include <string>
#include <map>
#include <vector>

class HTemplate {
public:
    HTemplate(std::string filename);
    ~HTemplate();
    void setValue(std::string key,std::string value);
    std::string write();
private:
    std::vector<std::string> lines;
    std::map<std::string,std::vector<int>> entries;
};
