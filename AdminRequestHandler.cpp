#include <Poco/Util/ServerApplication.h>
#include <Poco/Net/HTMLForm.h>
#include <Poco/JSON/JSON.h>
#include <Poco/JSON/Parser.h>
#include <ostream>
#include <map>
#include "AdminRequestHandler.h"
#include "UserManager.h"
#include "HTemplate.h"

using namespace Poco::JSON;
using namespace Poco::Net;
using namespace std;

void AdminRequestHandler::handleRequest(HTTPServerRequest &request, HTTPServerResponse &response)
{
    Poco::Util::Application &app = Poco::Util::Application::instance();
    app.logger().information("Admin Request from %s", request.clientAddress().toString());
    std::size_t pos = request.getURI().find_first_of('?');

    std::string url = pos == std::string::npos ? request.getURI() : request.getURI().substr(0,pos);
    map<string, string> params;

    HTMLForm form(request);

    NameValueCollection::ConstIterator i = form.begin();

    while (i != form.end()) {

        params[i->first] = i->second;

        ++i;
    }
    
    if(params.count("user")>0){
     User user =UserManager::getInstance().GetUser(params["user"]);   
    }
    response.setChunkedTransferEncoding(true);

    HTemplate tmpl("../templates/admin.html");
    response.send() << tmpl.write();



}


