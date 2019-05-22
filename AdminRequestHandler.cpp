#include <Poco/Util/ServerApplication.h>
#include <Poco/Net/HTMLForm.h>
#include <Poco/JSON/JSON.h>
#include <Poco/JSON/Parser.h>
#include <ostream>

#include "AdminRequestHandler.h"
#include "UserManager.h"
#include "HTemplate.h"

using namespace Poco::JSON;
using namespace Poco::Net;
using namespace std;

void AdminRequestHandler::handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
{
    Poco::Util::Application & app = Poco::Util::Application::instance();
        app.logger().information("Request from %s", request.clientAddress().toString());

        response.setChunkedTransferEncoding(true);
        
        HTemplate tmpl("../content/admin.html");
        response.send() << tmpl.write();
            
    
    
}


