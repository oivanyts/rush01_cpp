#ifndef IMONITORDISPLAY_HPP
#define IMONITORDISPLAY_HPP

#include <iostream>
#include "DateTimeModule.hpp"
#include "HostnameModule.hpp"
#include "NetworkModule.hpp"
#include "RAMModule.hpp"
#include "OSInfoModule.hpp"
#include "CPUModule.hpp"

class IMonitorDisplay
{
public:
    IMonitorDisplay();
    std::string getHostStr() const;
    std::string getOsStr() ;
    std::string getCpuModel() const;
    std::string getDateTime() const;
    std::string getRamTotal() const;

    float getCpuIdle() const ;
	void updateInfo();
    virtual ~IMonitorDisplay() {}

protected:
    OSInfoModule _pOs;
    HostnameModule _pHost;
    DateTimeModule _pDate;
    CPUModule _pCpu;
    RAMModule _pRam;

};

#endif // IMONITORDISPLAY_HPP
