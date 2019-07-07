#ifndef OSINFOMODULE_HPP
#define OSINFOMODULE_HPP
#include "IMonitorModule.hpp"

class OSInfoModule : public IMonitorModule {
	public:
		OSInfoModule();
		~OSInfoModule();

		OSInfoModule(const OSInfoModule &copy);
		OSInfoModule& operator=(const OSInfoModule&);

        std::string getRelease() const;
		std::string getSys() const;
		std::string getVersion() const;


		MType getInfo();
		std::string GetOSVersionComponent();

	private:
		std::string _releaseName;
		std::string _sysName;
		std::string _version;
};

#endif

