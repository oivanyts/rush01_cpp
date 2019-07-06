#include "CPUModule.hpp"
#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sstream>

CPUModule::CPUModule() {

}

CPUModule::~CPUModule() {
	
}

MType CPUModule::getInfo() {
	std::cout << std::endl;
	std::cout << "*************** CPU MODULES ****************" << std::endl;
	char buffer[1024];
    size_t size=sizeof(buffer);
    if (sysctlbyname("machdep.cpu.brand_string", &buffer, &size, NULL, 0) < 0) {
        throw std::runtime_error("Fail to get CPU model");
    }

	uint64_t freq = 0;
    size = sizeof(freq);

    if (sysctlbyname("hw.cpufrequency", &freq, &size, NULL, 0) < 0)
    {
    	throw std::runtime_error("Fail to get clock speed");
    }

    uint64_t core = 0;
    size = sizeof(core);
    if (sysctlbyname("machdep.cpu.core_count", &core, &size, NULL, 0) < 0)
    {
    	throw std::runtime_error("Fail to get count cores");
    }

    char	tmp[4096];
	if (FILE * stream = popen("top -l 1 -n 0 -s 0 | grep CPU", "r"))
	{
		fgets(tmp, sizeof(tmp), stream);
	}
	else {
		throw std::runtime_error("Fail to get CPU activity");
	}

	std::stringstream ss;
	ss << "CPU model: " << buffer << std::endl
		<< "Clock speed: " << freq << std::endl
		<< "Count cores: " << core << std::endl
		<< "CPU activity" << tmp << std::endl;
	return ss.str();
   
}
// sysctl -a
// sysctl hw.cpufrequency