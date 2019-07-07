#include "HostnameModule.hpp"
#include <unistd.h>
#include <iostream>
#include <sstream>

HostnameModule::HostnameModule() {
getInfo();
}

HostnameModule::HostnameModule(const HostnameModule &copy) {
    *this = copy;
}
HostnameModule::~HostnameModule() {

}

HostnameModule &HostnameModule::operator = (const HostnameModule &over)
{
    _nameHost = over._nameHost;
    _nameLogin = over._nameLogin;
    return (*this);
}

std::string HostnameModule::getHost() const {
	return this->_nameHost;
}

std::string HostnameModule::getUser() {
	return this->_nameLogin;
}

MType HostnameModule::getInfo() {
	std::cout << std::endl;
	std::cout << "*************** HOSTNAME MODULE ****************" << std::endl;
	char nameHost[_POSIX_HOST_NAME_MAX];
	// char *getlogin(void);
    // int getlogin_r(char *name, size_t namesize);
     // int gethostname(char *name, size_t len);
	int ihost = gethostname(nameHost, _POSIX_HOST_NAME_MAX);
	this->_nameHost = std::string(nameHost);
	this->_nameLogin = std::string(getlogin());
	if (ihost == -1)
		throw std::runtime_error("Fail to get hostname");

	std::stringstream ss;
	ss << "Hostname: " << _nameHost << std::endl
		<< "Username: " << _nameLogin << std::endl;
	return ss.str();
}
