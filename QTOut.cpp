#include "QTOut.hpp"

QTOut::QTOut()
{
    this->_pOs = new OSInfoModule;
    this->_pHost = new HostnameModule;
    this->_pDate = new DateTimeModule;
    this->_pCpu = new CPUModule;
    this->_pRam = new RAMModule;
}

QTOut::~QTOut()
{
    delete _pOs;
    delete _pHost;
    delete _pDate;
    delete _pCpu;
    delete _pRam;
}
void QTOut::updateInfo() {
	_pOs->getInfo();
	_pHost->getInfo();
	_pDate->getInfo();
	_pCpu->getInfo();
	_pRam->getInfo();
}
std::string QTOut::getHostStr() const {
	return ("Host name : " + _pHost->getHost());
}
std::string QTOut::getOsStr() const {
	return ("Version " + _pOs->getInfo());
}
std::string QTOut::getCpuModel() const {
	return ("CPU: " + _pCpu->getModel());
}
float QTOut::getCpuIdle() const {
	return _pCpu->getIdleCpu();
}
