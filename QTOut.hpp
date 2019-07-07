#ifndef QTOUT_HPP
#define QTOUT_HPP
#include "CPUModule.hpp"
#include "DateTimeModule.hpp"
#include "HostnameModule.hpp"
#include "NetworkModule.hpp"
#include "RAMModule.hpp"
#include "OSInfoModule.hpp"
//#include "IMonitorDisplay.hpp"



// class QTOut : public IMonitorDisplay {
class QTOut {
	public:
        QTOut();
		~QTOut();
		void updateInfo();
	std::string getHostStr() const;
	std::string getOsStr() const;
	std::string getCpuModel() const;
	float getCpuIdle() const;
private:
        OSInfoModule *_pOs;
        HostnameModule *_pHost;
        DateTimeModule *_pDate;
        CPUModule *_pCpu;
        RAMModule *_pRam;
};

#endif


