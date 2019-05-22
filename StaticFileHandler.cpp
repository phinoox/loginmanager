
#include <Poco/Util/ServerApplication.h>
#include <Poco/Net/HTMLForm.h>
#include <Poco/JSON/JSON.h>
#include <Poco/JSON/Parser.h>
#include <fstream>

#include "StaticFileHandler.h"
#include "UserManager.h"
#include "HTemplate.h"

using namespace Poco::JSON;
using namespace Poco::Net;
using namespace std;

void StaticFileHandler::handleRequest(HTTPServerRequest &request, HTTPServerResponse &response)
{
    string filename = "../content" + request.getURI();
    Poco::Util::Application &app = Poco::Util::Application::instance();
    app.logger().information("File Request from %s", request.clientAddress().toString());
    ifstream ifs(filename, ios::binary | ios::ate);
    ifstream::pos_type pos = ifs.tellg();

    std::vector<char>  result(pos);

    ifs.seekg(0, ios::beg);
    ifs.read(&result[0], pos);


    response.setChunkedTransferEncoding(true);
    response.sendBuffer(result.data(),result.size()*sizeof(char));



}


