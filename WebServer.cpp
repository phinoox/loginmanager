#include "WebServer.h"
#include "RequestHandlerFactory.h"
#include "HTemplate.h"

using namespace Poco;
using namespace Poco::Net;
using namespace Poco::Util;


void WebServer::Init(ServerApplication &self)
{
    loadConfiguration();
    ServerApplication::initialize(self);


}

int WebServer::main(const std::vector<std::string> &)
{
    UInt16 port = static_cast<UInt16>(config().getUInt("port", 8080));
    HTTPServer srv(new RequestHandlerFactory, port);
    srv.start();
    logger().information("HTTP Server started on port %hu.", port);
    waitForTerminationRequest();
    logger().information("Stopping HTTP Server...");
    srv.stop();

    return Application::EXIT_OK;
}

