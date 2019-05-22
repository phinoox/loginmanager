#include "HTemplate.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <Poco/RegularExpression.h>
#include <Poco/String.h>

using namespace std;

using Poco::replace;

HTemplate::HTemplate(std::string filename)
{
    ifstream inputFile(filename);
    if (!inputFile.is_open())
        return;
    string line;
    
    Poco::RegularExpression keyword("\\[\\[\\w*\\]\\]");
    while (getline(inputFile, line)) {
        lines.push_back(line);
        Poco::RegularExpression::MatchVec matches;
        if (keyword.match(line,0,matches)>0) {
            for(auto match : matches){
           string keyT = line.substr(match.offset+2,match.length-4);
           
                entries[keyT].push_back(lines.size() - 1);
            }
        }
    }
    inputFile.close();


}

HTemplate::~HTemplate()
{


}

void HTemplate::setValue(std::string key, std::string value)
{
 if(entries.count(key)==0)
     return;
 string keyT = "[["+key+"]]";
 for(int index : entries[key]){
    lines[index]=replace(lines[index],keyT,value);   
 }

}

std::string HTemplate::write()
{
    stringstream content("");
    for (string line : lines) {

        content << line << "\n";
    }
    return content.str();
}

