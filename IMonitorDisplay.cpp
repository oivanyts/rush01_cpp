#include "IMonitorDisplay.hpp"


IMonitorDisplay::IMonitorDisplay() {

}
std::string IMonitorDisplay::getHostStr() {
    return ("Host name : " + _pHost.getHost());
}
std::string IMonitorDisplay::getOsStr() {
	return ("Version " + _pOs.getInfo());
}
std::string IMonitorDisplay::getCpuModel()  {
	return ("CPU: " + _pCpu.getModel());
}
float IMonitorDisplay::getCpuIdle()  {
	return _pCpu.getIdleCpu();
}
void IMonitorDisplay::updateInfo() {
	_pOs.getInfo();
	_pHost.getInfo();
	_pDate.getInfo();
	_pCpu.getInfo();
	_pRam.getInfo();
}