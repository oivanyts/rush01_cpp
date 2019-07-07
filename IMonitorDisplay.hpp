#ifndef IMONITORDISPLAY_HPP
#define IMONITORDISPLAY_HPP

#include <string>
#include <iostream>
# include <ctime>
# include <sstream>
# include <string>
# include <vector>
# include <ncurses.h>
#include "DateTimeModule.hpp"
#include "HostnameModule.hpp"
#include "NetworkModule.hpp"
#include "RAMModule.hpp"
#include "OSInfoModule.hpp"
#include "CPUModule.hpp"
#include "Common.hpp"

class IMonitorDisplay {
public:
    IMonitorDisplay();
	Command    getInput() ;
	void updateInfo();
	IMonitorDisplay(const IMonitorDisplay &copy);
	IMonitorDisplay &operator = (const IMonitorDisplay &over);

	virtual std::string getHostStr() const = 0;
	virtual std::string getOsStr() = 0 ;
	virtual std::string getCpuModel() const = 0;
	virtual std::string getDateTime() const = 0;
	virtual std::string getRamTotal() const = 0;
	virtual std::string getNet() const  = 0;
	virtual float getCpuIdle() const  = 0;
	virtual ~IMonitorDisplay() {}
	virtual void 	printOut() {};
protected:
    OSInfoModule _pOs;
    HostnameModule _pHost;
    DateTimeModule _pDate;
    CPUModule _pCpu;
    RAMModule _pRam;
	NetworkModule _pNet;

};

#endif // IMONITORDISPLAY_HPP
