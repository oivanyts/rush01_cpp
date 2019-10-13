#ifndef IMONITORMODULE_HPP
#define IMONITORMODULE_HPP
#include <string>

typedef std::string MType;

class IMonitorModule {
	public:
		virtual ~IMonitorModule() {}
		virtual MType getInfo() = 0;
};

#endif