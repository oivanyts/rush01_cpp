#include "IMonitorDisplay.hpp"


IMonitorDisplay::IMonitorDisplay() {

}
std::string IMonitorDisplay::getHostStr() const {
    return ("Host name : " + _pHost.getHost());
}

std::string IMonitorDisplay::getOsStr() { // add  const
    return (_pOs.getInfo());
}

std::string IMonitorDisplay::getCpuModel()  const{
    return (_pCpu.getModel());
}

std::string IMonitorDisplay::getRamTotal() const {
    return (std::to_string(_pRam.getUTotalMemory()));
}

std::string IMonitorDisplay::getDateTime() const {
    return (_pDate.getDateTime() + "\n" +_pDate.getTime());
}

std::string IMonitorDisplay::getNet() const {
	return ("NET: " + _pNet.getNet());
}

float IMonitorDisplay::getCpuIdle() const {
	return _pCpu.getIdleCpu();
}

void IMonitorDisplay::updateInfo() {
	_pOs.getInfo();
	_pHost.getInfo();
	_pDate.getInfo();
	_pCpu.getInfo();
	_pRam.getInfo();
	_pNet.getInfo();
}
