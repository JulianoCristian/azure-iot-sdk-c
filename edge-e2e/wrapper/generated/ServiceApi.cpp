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

#include "ServiceApi.h"
#include "ServiceGlue.h"

ServiceGlue service_glue;

namespace io {
namespace swagger {
namespace server {
namespace api {

ServiceApi::ServiceApi() {
	std::shared_ptr<ServiceApiServiceConnectResource> spServiceApiServiceConnectResource = std::make_shared<ServiceApiServiceConnectResource>();
	this->publish(spServiceApiServiceConnectResource);
	
	std::shared_ptr<ServiceApiServiceConnectionIdDeviceMethodDeviceIdResource> spServiceApiServiceConnectionIdDeviceMethodDeviceIdResource = std::make_shared<ServiceApiServiceConnectionIdDeviceMethodDeviceIdResource>();
	this->publish(spServiceApiServiceConnectionIdDeviceMethodDeviceIdResource);
	
	std::shared_ptr<ServiceApiServiceConnectionIdDisconnectResource> spServiceApiServiceConnectionIdDisconnectResource = std::make_shared<ServiceApiServiceConnectionIdDisconnectResource>();
	this->publish(spServiceApiServiceConnectionIdDisconnectResource);
	
	std::shared_ptr<ServiceApiServiceConnectionIdModuleMethodDeviceIdModuleIdResource> spServiceApiServiceConnectionIdModuleMethodDeviceIdModuleIdResource = std::make_shared<ServiceApiServiceConnectionIdModuleMethodDeviceIdModuleIdResource>();
	this->publish(spServiceApiServiceConnectionIdModuleMethodDeviceIdModuleIdResource);
	
}

ServiceApi::~ServiceApi() {}

void ServiceApi::startService(int const& port) {
	std::shared_ptr<restbed::Settings> settings = std::make_shared<restbed::Settings>();
	settings->set_port(port);
	settings->set_root("");
	
	this->start(settings);
}

void ServiceApi::stopService() {
	this->stop();
}

ServiceApiServiceConnectResource::ServiceApiServiceConnectResource()
{
	this->set_path("/service/connect/");
	this->set_method_handler("PUT",
		std::bind(&ServiceApiServiceConnectResource::PUT_method_handler, this,
			std::placeholders::_1));
}

ServiceApiServiceConnectResource::~ServiceApiServiceConnectResource()
{
}

void ServiceApiServiceConnectResource::PUT_method_handler(const std::shared_ptr<restbed::Session> session) {

	const auto request = session->get_request();
	const std::string connectionString = request->get_query_parameter("connectionString", "");
	string result = service_glue.Connect(connectionString);
	session->close(200, result, { {"Connection", "close"} });
}



ServiceApiServiceConnectionIdDeviceMethodDeviceIdResource::ServiceApiServiceConnectionIdDeviceMethodDeviceIdResource()
{
	this->set_path("/service/{connectionId: .*}/deviceMethod/{deviceId: .*}/");
	this->set_method_handler("PUT",
		std::bind(&ServiceApiServiceConnectionIdDeviceMethodDeviceIdResource::PUT_method_handler, this,
			std::placeholders::_1));
}

ServiceApiServiceConnectionIdDeviceMethodDeviceIdResource::~ServiceApiServiceConnectionIdDeviceMethodDeviceIdResource()
{
}

void ServiceApiServiceConnectionIdDeviceMethodDeviceIdResource::PUT_method_handler(const std::shared_ptr<restbed::Session> session) {

	const auto request = session->get_request();
	// Body params are present, therefore we have to fetch them
	int content_length = request->get_header("Content-Length", 0);
	session->fetch(content_length,
		[ this ]( const std::shared_ptr<restbed::Session> session, const restbed::Bytes & body )
		{
			const auto request = session->get_request();
			std::string requestBody = restbed::String::format("%.*s\n", ( int ) body.size( ), body.data( ));
			const std::string connectionId = request->get_path_parameter("connectionId", "");
			const std::string deviceId = request->get_path_parameter("deviceId", "");
			string result = service_glue.InvokeDeviceMethod(connectionId, deviceId, requestBody);
			session->close(200, result, { {"Connection", "close"} });
		});
}



ServiceApiServiceConnectionIdDisconnectResource::ServiceApiServiceConnectionIdDisconnectResource()
{
	this->set_path("/service/{connectionId: .*}/disconnect//");
	this->set_method_handler("PUT",
		std::bind(&ServiceApiServiceConnectionIdDisconnectResource::PUT_method_handler, this,
			std::placeholders::_1));
}

ServiceApiServiceConnectionIdDisconnectResource::~ServiceApiServiceConnectionIdDisconnectResource()
{
}

void ServiceApiServiceConnectionIdDisconnectResource::PUT_method_handler(const std::shared_ptr<restbed::Session> session) {

	const auto request = session->get_request();
	const std::string connectionId = request->get_path_parameter("connectionId", "");
	service_glue.Disconnect(connectionId);
	session->close(200, "OK", { {"Connection", "close"} });
}



ServiceApiServiceConnectionIdModuleMethodDeviceIdModuleIdResource::ServiceApiServiceConnectionIdModuleMethodDeviceIdModuleIdResource()
{
	this->set_path("/service/{connectionId: .*}/moduleMethod/{deviceId: .*}/{moduleId: .*}/");
	this->set_method_handler("PUT",
		std::bind(&ServiceApiServiceConnectionIdModuleMethodDeviceIdModuleIdResource::PUT_method_handler, this,
			std::placeholders::_1));
}

ServiceApiServiceConnectionIdModuleMethodDeviceIdModuleIdResource::~ServiceApiServiceConnectionIdModuleMethodDeviceIdModuleIdResource()
{
}

void ServiceApiServiceConnectionIdModuleMethodDeviceIdModuleIdResource::PUT_method_handler(const std::shared_ptr<restbed::Session> session) {

	const auto request = session->get_request();
	// Body params are present, therefore we have to fetch them
	int content_length = request->get_header("Content-Length", 0);
	session->fetch(content_length,
		[ this ]( const std::shared_ptr<restbed::Session> session, const restbed::Bytes & body )
		{
			const auto request = session->get_request();
			std::string requestBody = restbed::String::format("%.*s\n", ( int ) body.size( ), body.data( ));
			const std::string connectionId = request->get_path_parameter("connectionId", "");
			const std::string deviceId = request->get_path_parameter("deviceId", "");
			const std::string moduleId = request->get_path_parameter("moduleId", "");
			string result = service_glue.InvokeModuleMethod(connectionId, deviceId, moduleId, requestBody);
			session->close(200, result, { {"Connection", "close"} });
		});
}




}
}
}
}

