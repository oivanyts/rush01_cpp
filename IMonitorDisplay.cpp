#include "IMonitorDisplay.hpp"


IMonitorDisplay::IMonitorDisplay() {

}
std::string IMonitorDisplay::getHostStr() const {
    return ("Host name : " + _pHost.getHost());
}

std::string IMonitorDisplay::getOsStr() { // add  const
    return ("Version " + _pOs.getInfo());
}

std::string IMonitorDisplay::getCpuModel()  const{
	return ("CPU: " + _pCpu.getModel());
}

std::string IMonitorDisplay::getDateTime() const {
    return (_pDate.getDateTime());
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
}
