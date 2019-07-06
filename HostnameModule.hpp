#ifndef HOSTNAMEMODULE_HPP
#define HOSTNAMEMODULE_HPP
#include "IMonitorModule.hpp"

class HostnameModule : public IMonitorModule {
	public:
		HostnameModule();
		~HostnameModule();
		MType getInfo();
};

#endif