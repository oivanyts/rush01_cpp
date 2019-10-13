#ifndef IMONITORDISPLAY_HPP
#define IMONITORDISPLAY_HPP

#include "DateTimeModule.hpp"
#include "HostnameModule.hpp"
#include "NetworkModule.hpp"
#include "RAMModule.hpp"
#include "OSInfoModule.hpp"
#include "CPUModule.hpp"
#include "Common.hpp"

class IMonitorDisplay
{

public:
	virtual ~IMonitorDisplay() {}

	virtual Command getInput() = 0;
	virtual void updateInfo() = 0;
	virtual void printOut() = 0;

protected:
    OSInfoModule _pOs;
    HostnameModule _pHost;
    DateTimeModule _pDate;
    CPUModule _pCpu;
    RAMModule _pRam;
	NetworkModule _pNet;

};

#endif // IMONITORDISPLAY_HPP
