#pragma once
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPRequestHandler.h>

class RequestHandlerFactory: public Poco::Net::HTTPRequestHandlerFactory
{
    Poco::Net::HTTPRequestHandler* createRequestHandler ( const Poco::Net::HTTPServerRequest& req );
    
};
