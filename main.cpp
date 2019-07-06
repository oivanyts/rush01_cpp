#include <iostream>
#include "HostnameModule.hpp"
#include "OSInfoModule.hpp"
#include "DateTimeModule.hpp"
#include "CPUModule.hpp"
#include "RAMModule.hpp"

int main() {
	HostnameModule hostnameModule;
	OSInfoModule osInfoModule;
	DateTimeModule dateTimeModule;
	CPUModule cpuModule;
	RAMModule ramModule;

	std::cout << hostnameModule.getInfo() << std::endl;
	std::cout << osInfoModule.getInfo() << std::endl;
	std::cout << dateTimeModule.getInfo() << std::endl;
	std::cout << cpuModule.getInfo() << std::endl;
	std::cout << ramModule.getInfo() << std::endl;

	return 0;
}