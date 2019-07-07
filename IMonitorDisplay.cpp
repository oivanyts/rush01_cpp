#include "IMonitorDisplay.hpp"


IMonitorDisplay::IMonitorDisplay() {

}

IMonitorDisplay::IMonitorDisplay(const IMonitorDisplay &copy) {
    *this = copy;
}

IMonitorDisplay &IMonitorDisplay::operator = (const IMonitorDisplay &over)
{
	_pOs = over._pOs;
	_pHost = over._pHost;
	_pDate = over._pDate;
	_pCpu = over._pCpu;
	_pRam = over._pRam;
	_pNet = over._pNet;
    return (*this);
}
//std::string IMonitorDisplay::getHostStr() const {
//    return (_pHost.getHost() +" HERE" + _pHost.getUser());
//}
//
//std::string IMonitorDisplay::getOsStr() { // add  const
//    return (_pOs.getInfo());
//}
//
//std::string IMonitorDisplay::getCpuModel()  const{
//    return (_pCpu.getModel());
//}
//
//std::string IMonitorDisplay::getRamTotal() const {
//    return (std::to_string(_pRam.getUTotalMemory()));
//}
//
//std::string IMonitorDisplay::getDateTime() const {
//    return (_pDate.getDateTime() + "\n" +_pDate.getTime());
//}
//
//std::string IMonitorDisplay::getNet() const {
//	return ("NET: " + _pNet.getNet());
//}
//
//float IMonitorDisplay::getCpuIdle() const {
//	return _pCpu.getIdleCpu();
//}

Command   IMonitorDisplay::getInput() {
	int g = getch();
	switch (g) {
		case ' ':
			return SPACE;
		case 'q':
			return EXIT;
		default:
			return UNKNOWN;
	}
	return UNKNOWN;
}

void IMonitorDisplay::updateInfo() {
	_pOs.getInfo();
	_pHost.getInfo();
	_pDate.getInfo();
	_pCpu.getInfo();
	_pRam.getInfo();
	_pNet.getInfo();
}
