#ifndef OSINFOMODULE_HPP
#define OSINFOMODULE_HPP
#include "IMonitorModule.hpp"

class OSInfoModule : public IMonitorModule {
	public:
		OSInfoModule();
		~OSInfoModule();
		MType getInfo();
		int GetOSVersionComponent(int component);
};

#endif