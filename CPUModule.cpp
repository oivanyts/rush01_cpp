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

CPUModule::CPUModule(const CPUModule &copy)
{
    *this = copy;
}
CPUModule& CPUModule::operator=(const CPUModule&rhs)
{
    _hw = rhs._hw;
    _core = rhs._core;
    return (*this);
}

MType CPUModule::getInfo() {
	std::cout << std::endl;
	std::cout << "*************** CPU MODULES ****************" << std::endl;
	// char _model[1024];
    size_t size = sizeof(_model);
    if (sysctlbyname("machdep.cpu.brand_string", &_model, &size, NULL, 0) < 0) {
        throw std::runtime_error("Fail to get CPU model");
    }

	// uint64_t _hw = 0;
    size = sizeof(_hw);

    if (sysctlbyname("hw.cpufrequency", &_hw, &size, NULL, 0) < 0)
    {
    	throw std::runtime_error("Fail to get clock speed");
    }

    // uint64_t core = 0;
    size = sizeof(_core);
    if (sysctlbyname("machdep.cpu.core_count", &_core, &size, NULL, 0) < 0)
    {
    	throw std::runtime_error("Fail to get count cores");
    }

    // char	_activity[4096];
	if (FILE * stream = popen("top -l 1 -n 0 -s 0 | grep CPU", "r"))
	{
		fgets(_activity, sizeof(_activity), stream);
	}
	else {
		throw std::runtime_error("Fail to get CPU activity");
	}

	std::stringstream ss;
	ss << "CPU model: " << _model << std::endl
		<< "Clock speed: " << _hw << std::endl
		<< "Count cores: " << _core << std::endl
		<< "CPU activity" << _activity << std::endl;
	return ss.str();
   
}
// sysctl -a
// sysctl hw.cpufrequency
