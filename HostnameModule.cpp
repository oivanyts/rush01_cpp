#include "HostnameModule.hpp"
#include <unistd.h>
#include <iostream>

HostnameModule::HostnameModule() {

}

HostnameModule::~HostnameModule() {

}

MType HostnameModule::getInfo() {
	std::cout << std::endl;
	std::cout << "*************** HOSTNAME MODULE ****************" << std::endl;
	char name[256];
	int i = gethostname(name, 256);
	if (i == -1)
		throw std::runtime_error("Fail to get hostname");
	return std::string(name);
}