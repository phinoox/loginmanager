
#pragma once
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>

class AdminRequestHandler : public Poco::Net::HTTPRequestHandler
{
    void handleRequest( Poco::Net::HTTPServerRequest & request, Poco::Net::HTTPServerResponse& response);
};
