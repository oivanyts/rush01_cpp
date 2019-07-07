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
		int getOSVersion1() const;
		int getOSVersion2() const;
		int getOSVersion3() const;


		MType getInfo();
		int GetOSVersionComponent(int component);

	private:
		std::string _releaseName;
		std::string _sysName;
		int _OSVersion1;
		int _OSVersion2;
		int _OSVersion3;
};

#endif

