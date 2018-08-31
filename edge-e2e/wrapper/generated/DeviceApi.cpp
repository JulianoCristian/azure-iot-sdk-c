/**
 * IoT SDK Device & Client REST API
 * REST API definition for End-to-end testing of the Azure IoT SDKs.  All SDK APIs that are tested by our E2E tests need to be defined in this file.  This file takes some liberties with the API definitions.  In particular, response schemas are undefined, and error responses are also undefined.
 *
 * OpenAPI spec version: 1.0.0
 *
 *
 * NOTE: This class is auto generated by the swagger code generator 2.3.1.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */


#include <corvusoft/restbed/byte.hpp>
#include <corvusoft/restbed/string.hpp>
#include <corvusoft/restbed/settings.hpp>
#include <corvusoft/restbed/request.hpp>

#include "DeviceApi.h"
#include "DeviceGlue.h"

DeviceGlue device_glue;

namespace io {
namespace swagger {
namespace server {
namespace api {

DeviceApi::DeviceApi() {
	std::shared_ptr<DeviceApiDeviceConnectTransportTypeResource> spDeviceApiDeviceConnectTransportTypeResource = std::make_shared<DeviceApiDeviceConnectTransportTypeResource>();
	this->publish(spDeviceApiDeviceConnectTransportTypeResource);
	
	std::shared_ptr<DeviceApiDeviceConnectionIdDisconnectResource> spDeviceApiDeviceConnectionIdDisconnectResource = std::make_shared<DeviceApiDeviceConnectionIdDisconnectResource>();
	this->publish(spDeviceApiDeviceConnectionIdDisconnectResource);
	
	std::shared_ptr<DeviceApiDeviceConnectionIdEnableMethodsResource> spDeviceApiDeviceConnectionIdEnableMethodsResource = std::make_shared<DeviceApiDeviceConnectionIdEnableMethodsResource>();
	this->publish(spDeviceApiDeviceConnectionIdEnableMethodsResource);
	
	std::shared_ptr<DeviceApiDeviceConnectionIdRoundtripMethodCallMethodNameResource> spDeviceApiDeviceConnectionIdRoundtripMethodCallMethodNameResource = std::make_shared<DeviceApiDeviceConnectionIdRoundtripMethodCallMethodNameResource>();
	this->publish(spDeviceApiDeviceConnectionIdRoundtripMethodCallMethodNameResource);
	
}

DeviceApi::~DeviceApi() {}

void DeviceApi::startService(int const& port) {
	std::shared_ptr<restbed::Settings> settings = std::make_shared<restbed::Settings>();
	settings->set_port(port);
	settings->set_root("");

	this->start(settings);
}

void DeviceApi::stopService() {
	this->stop();
}

DeviceApiDeviceConnectTransportTypeResource::DeviceApiDeviceConnectTransportTypeResource()
{
	this->set_path("/device/connect/{transportType: .*}/");
	this->set_method_handler("PUT",
		std::bind(&DeviceApiDeviceConnectTransportTypeResource::PUT_method_handler, this,
			std::placeholders::_1));
}

DeviceApiDeviceConnectTransportTypeResource::~DeviceApiDeviceConnectTransportTypeResource()
{
}

void DeviceApiDeviceConnectTransportTypeResource::PUT_method_handler(const std::shared_ptr<restbed::Session> session) {
	const auto request = session->get_request();
	int content_length = request->get_header("Content-Length", 0);
	session->fetch(content_length,
		[ this ]( const std::shared_ptr<restbed::Session> session, const restbed::Bytes & body )
		{

			const auto request = session->get_request();
			std::string caCertificate = restbed::String::format("%.*s\n", ( int ) body.size( ), body.data( ));
			const std::string transportType = request->get_path_parameter("transportType", "");
			const std::string connectionString = request->get_query_parameter("connectionString", "");

			string ret = device_glue.Connect(transportType, connectionString, caCertificate);
			session->close(200, ret, { { "Connection", "close" } });
		});
}



DeviceApiDeviceConnectionIdDisconnectResource::DeviceApiDeviceConnectionIdDisconnectResource()
{
	this->set_path("/device/{connectionId: .*}/disconnect/");
	this->set_method_handler("PUT",
		std::bind(&DeviceApiDeviceConnectionIdDisconnectResource::PUT_method_handler, this,
			std::placeholders::_1));
}

DeviceApiDeviceConnectionIdDisconnectResource::~DeviceApiDeviceConnectionIdDisconnectResource()
{
}

void DeviceApiDeviceConnectionIdDisconnectResource::PUT_method_handler(const std::shared_ptr<restbed::Session> session) {
	const auto request = session->get_request();

	const std::string connectionId = request->get_path_parameter("connectionId", "");

	device_glue.Disconnect(connectionId);
	session->close(200, "OK", { { "Connection", "close" } });
}



DeviceApiDeviceConnectionIdEnableMethodsResource::DeviceApiDeviceConnectionIdEnableMethodsResource()
{
	this->set_path("/device/{connectionId: .*}/enableMethods/");
	this->set_method_handler("PUT",
		std::bind(&DeviceApiDeviceConnectionIdEnableMethodsResource::PUT_method_handler, this,
			std::placeholders::_1));
}

DeviceApiDeviceConnectionIdEnableMethodsResource::~DeviceApiDeviceConnectionIdEnableMethodsResource()
{
}

void DeviceApiDeviceConnectionIdEnableMethodsResource::PUT_method_handler(const std::shared_ptr<restbed::Session> session) {

	const auto request = session->get_request();

	const std::string connectionId = request->get_path_parameter("connectionId", "");
	device_glue.EnableMethods(connectionId);
	session->close(200, "OK", { {"Connection", "close"} });
}



DeviceApiDeviceConnectionIdRoundtripMethodCallMethodNameResource::DeviceApiDeviceConnectionIdRoundtripMethodCallMethodNameResource()
{
	this->set_path("/device/{connectionId: .*}/roundtripMethodCall/{methodName: .*}/");
	this->set_method_handler("PUT",
		std::bind(&DeviceApiDeviceConnectionIdRoundtripMethodCallMethodNameResource::PUT_method_handler, this,
			std::placeholders::_1));
}

DeviceApiDeviceConnectionIdRoundtripMethodCallMethodNameResource::~DeviceApiDeviceConnectionIdRoundtripMethodCallMethodNameResource()
{
}

void DeviceApiDeviceConnectionIdRoundtripMethodCallMethodNameResource::PUT_method_handler(const std::shared_ptr<restbed::Session> session) {
    const auto request = session->get_request();

    int content_length = request->get_header("Content-Length", 0);
    session->fetch(content_length,
        [this](const std::shared_ptr<restbed::Session> session, const restbed::Bytes & body)
    {

        const auto request = session->get_request();
        std::string requestBody = restbed::String::format("%.*s\n", (int)body.size(), body.data());
        const std::string connectionId = request->get_path_parameter("connectionId", "");
        const std::string methodName = request->get_path_parameter("methodName", "");

        device_glue.RoundTripMethodCall(connectionId, methodName, requestBody);

        session->close(200, "OK", { { "Connection", "close" } });
    });
}




}
}
}
}

