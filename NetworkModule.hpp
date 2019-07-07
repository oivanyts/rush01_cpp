#ifndef NETWORKMODULE_HPP
#define NETWORKMODULE_HPP
#include "IMonitorModule.hpp"

class NetworkModule : public IMonitorModule {
	public:
		NetworkModule();
		NetworkModule(const NetworkModule &copy);
		NetworkModule & operator=(const NetworkModule &over);
		~NetworkModule();

		std::string getNet() const;

		MType getInfo();

	private:
		std::string _net;

};

#endif


