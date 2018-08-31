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

/*
 * RegistryApi.h
 *
 * 
 */

#ifndef RegistryApi_H_
#define RegistryApi_H_


#include <memory>
#include <corvusoft/restbed/session.hpp>
#include <corvusoft/restbed/resource.hpp>
#include <corvusoft/restbed/service.hpp>

#include <string>

namespace io {
namespace swagger {
namespace server {
namespace api {

class  RegistryApi: public virtual restbed::Service
{
public:
	RegistryApi();
	~RegistryApi();
	void startService(int const& port);
	void stopService();
};


/// <summary>
/// Connect to registry
/// </summary>
/// <remarks>
/// Connect to the Azure IoTHub registry.  More specifically, the SDK saves the connection string that is passed in for future use.
/// </remarks>
class  RegistryApiRegistryConnectResource: public restbed::Resource
{
public:
	RegistryApiRegistryConnectResource();
    virtual ~RegistryApiRegistryConnectResource();
    void PUT_method_handler(const std::shared_ptr<restbed::Session> session);
};

/// <summary>
/// Disconnect from the registry
/// </summary>
/// <remarks>
/// Disconnects from the Azure IoTHub registry.  More specifically, closes all connections and cleans up all resources for the active connection
/// </remarks>
class  RegistryApiRegistryConnectionIdDisconnectResource: public restbed::Resource
{
public:
	RegistryApiRegistryConnectionIdDisconnectResource();
    virtual ~RegistryApiRegistryConnectionIdDisconnectResource();
    void PUT_method_handler(const std::shared_ptr<restbed::Session> session);
};

/// <summary>
/// gets the module twin for the given deviceid and moduleid
/// </summary>
/// <remarks>
/// 
/// </remarks>
class  RegistryApiRegistryConnectionIdModuleTwinDeviceIdModuleIdResource: public restbed::Resource
{
public:
	RegistryApiRegistryConnectionIdModuleTwinDeviceIdModuleIdResource();
    virtual ~RegistryApiRegistryConnectionIdModuleTwinDeviceIdModuleIdResource();
    void GET_method_handler(const std::shared_ptr<restbed::Session> session);
    void PATCH_method_handler(const std::shared_ptr<restbed::Session> session);
};


}
}
}
}

#endif /* RegistryApi_H_ */

