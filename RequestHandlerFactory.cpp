#include "RequestHandlerFactory.h"
#include "LoginRequestHandler.h"
#include "AdminRequestHandler.h"

Poco::Net::HTTPRequestHandler * RequestHandlerFactory::createRequestHandler(const Poco::Net::HTTPServerRequest& req)
{
    if(req.getURI()=="/admin")
        return new AdminRequestHandler;
    return new LoginRequestHandler;
}

