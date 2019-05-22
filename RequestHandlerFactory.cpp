#include "RequestHandlerFactory.h"
#include "LoginRequestHandler.h"
#include "AdminRequestHandler.h"
#include "StaticFileHandler.h"
#include <Poco/File.h>

Poco::Net::HTTPRequestHandler * RequestHandlerFactory::createRequestHandler(const Poco::Net::HTTPServerRequest& req)
{
    Poco::File file("../content"+req.getURI());
    if(file.exists())
        return new StaticFileHandler;
    if(req.getURI()=="/admin")
        return new AdminRequestHandler;
    return new LoginRequestHandler;
}

