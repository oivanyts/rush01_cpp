#ifndef CPUMODULE_HPP
#define CPUMODULE_HPP
#include "IMonitorModule.hpp"

class CPUModule : public IMonitorModule {
	public:
		CPUModule();
		~CPUModule();
		MType getInfo();
};

#endif