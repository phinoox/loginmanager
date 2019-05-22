#pragma once

#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Util/ServerApplication.h"
#include <iostream>

class WebServer : public Poco::Util::ServerApplication{
    
 public:
  void Init(Poco::Util::ServerApplication& self);
  int  main(const std::vector<std::string> & args) override;
    
};


POCO_SERVER_MAIN(WebServer)
