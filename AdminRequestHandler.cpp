#include <Poco/Util/ServerApplication.h>
#include <Poco/Net/HTMLForm.h>
#include <Poco/JSON/JSON.h>
#include <Poco/JSON/Parser.h>
#include <Poco/HMACEngine.h>
#include <Poco/SHA1Engine.h>

#include <ostream>
#include <map>
#include "AdminRequestHandler.h"
#include "UserManager.h"
#include "HTemplate.h"
#include "CryptoUtil.h"

using namespace Poco::JSON;
using namespace Poco::Net;
using Poco::DigestEngine;
using Poco::HMACEngine;
using Poco::SHA1Engine;


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
    HTemplate tmpl("../templates/admin.html");
    if(params.count("user")>0){
     User user =UserManager::getInstance().GetUser(params["user"]);
     tmpl.setValue("label","Phinoox login Server");
     if(user.secret=="")
         user.secret=generateSecrete();
     tmpl.setValue("secret",user.secret);
     
    }
    response.setChunkedTransferEncoding(true);

    
    response.send() << tmpl.write();



}


