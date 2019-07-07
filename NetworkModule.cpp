#include "NetworkModule.hpp"
#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sstream>

NetworkModule::NetworkModule() {
getInfo();
}

NetworkModule::~NetworkModule() {
	
}

NetworkModule::NetworkModule(const NetworkModule &copy) {
	*this = copy;
}

NetworkModule & NetworkModule::operator=(const NetworkModule &over) {
	_net = over._net;
	return *this;
}

std::string NetworkModule::getNet() const {
	return this->_net;
}

MType NetworkModule::getInfo() {
	char tmpBuf[256];
	std::string tmp;
	if (FILE * stream = popen("top -l 1 | grep Network", "r"))
	{
		fgets(tmpBuf, sizeof(tmpBuf), stream);
		pclose(stream);
	}
	else {
		throw std::runtime_error("Fail to get network module");
	}

	tmp = std::string(tmpBuf);
	this->_net = std::string(tmp);
	std::stringstream ss;
	ss << _net << std::endl;
	return ss.str();
}


