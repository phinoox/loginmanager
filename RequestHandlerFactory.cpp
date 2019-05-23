#include "RequestHandlerFactory.h"
#include "LoginRequestHandler.h"
#include "AdminRequestHandler.h"
#include "StaticFileHandler.h"
#include <Poco/File.h>

Poco::Net::HTTPRequestHandler * RequestHandlerFactory::createRequestHandler(const Poco::Net::HTTPServerRequest& req)
{
    std::size_t pos = req.getURI().find_first_of('?');
    
    std::string url = pos==std::string::npos?req.getURI():req.getURI().substr(0,pos);
    Poco::File file("../content"+url);
    if(file.exists())
        return new StaticFileHandler;
    if(url=="/admin")
        return new AdminRequestHandler;
    return new LoginRequestHandler;
}

