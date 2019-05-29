#include <Poco/Util/ServerApplication.h>
#include <Poco/Net/HTMLForm.h>
#include <Poco/JSON/JSON.h>
#include <Poco/JSON/Parser.h>
#include <ostream>

#include "LoginRequestHandler.h"
#include "UserManager.h"


using namespace Poco::JSON;
using namespace Poco::Net;
using namespace std;

void LoginRequestHandler::handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
{
    Poco::Util::Application & app = Poco::Util::Application::instance();
        app.logger().information("Login Request from %s", request.clientAddress().toString());

        response.setChunkedTransferEncoding(true);
        response.setContentType("application/json");
        User user;
        if(request.getMethod()== HTTPServerRequest::HTTP_POST){
        HTMLForm form(request,request.stream());
        if(form.has("id")&&form.has("action")&&form.has("pw")){
        string name=form.get("id");
        string pw=form.get("pw");
        
        user=UserManager::getInstance().GetUser(name);
        }
        else
            app.logger().information("invalid request");
        }
        Object json;
        stringstream jsonstring;
        json.set("id",user.main_id);
        json.set("name",user.name);
        json.stringify(jsonstring);
        response.send() << jsonstring.str();
            
    
    
}

