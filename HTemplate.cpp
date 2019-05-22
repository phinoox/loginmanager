#include "HTemplate.h"
#include "ConfigLoader.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <Poco/RegularExpression.h>
#include <Poco/String.h>

using namespace std;

using Poco::replace;

struct CachedTemplate {
    std::vector<std::string> lines;
    std::map<std::string, std::vector<int>> entries;

    CachedTemplate()
    {
    }

    CachedTemplate(string filename)
    {
        ifstream inputFile(filename);
        if (!inputFile.is_open())
            return;
        string line;

        Poco::RegularExpression keyword("\\[\\[\\w*\\]\\]");
        while (getline(inputFile, line)) {
            lines.push_back(line);
            Poco::RegularExpression::MatchVec matches;
            if (keyword.match(line, 0, matches) > 0) {
                for (auto match : matches) {
                    string keyT = line.substr(match.offset + 2, match.length - 4);

                    entries[keyT].push_back(lines.size() - 1);
                }
            }
        }
        inputFile.close();
    }
};

static map<string, CachedTemplate> cachedTemplates;

HTemplate::HTemplate(std::string filename)
{
    bool caching = ConfigLoader::getConfig().getBool("Templates.caching", false);
    if (caching) {
        if (cachedTemplates.count(filename) == 0)
            cachedTemplates[filename] = CachedTemplate(filename);
        cached = new CachedTemplate(cachedTemplates[filename]);
    } else {
        cached = new CachedTemplate(filename);
    }


}

HTemplate::~HTemplate()
{
    if (cached != nullptr)
        delete cached;

}

void HTemplate::setValue(std::string key, std::string value)
{
    if (cached->entries.count(key) == 0)
        return;
    string keyT = "[[" + key + "]]";
    for (int index : cached->entries[key]) {
        cached->lines[index] = replace(cached->lines[index], keyT, value);
    }

}

std::string HTemplate::write()
{
    stringstream content("");
    for (string line : cached->lines) {

        content << line << "\n";
    }
    return content.str();
}

