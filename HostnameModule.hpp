#ifndef HOSTNAMEMODULE_HPP
#define HOSTNAMEMODULE_HPP
#include "IMonitorModule.hpp"

class HostnameModule : public IMonitorModule {
	public:
		HostnameModule();
		~HostnameModule();
		HostnameModule(const HostnameModule &copy);
		HostnameModule &operator = (const HostnameModule &over);

        std::string getHost() const;
		std::string getUser();

		MType getInfo();

	private:
		std::string _nameHost;
		std::string _nameLogin;
};

#endif

