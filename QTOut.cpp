#include "QTOut.hpp"

QTOut::QTOut()
{
}

QTOut::~QTOut()
{ }
//Command QTOut::getInput() {
//	return EXIT;
//}

std::string QTOut::getHostStr() const {
	return (_pHost.getHost() + "\n" + _pHost.getUser());
}

std::string QTOut::getOsStr() { // add  const
	return (_pOs.getInfo());
}

std::string QTOut::getCpuModel()  const{
    std::string tmp = std::to_string(_pCpu.hatHW() / 10000000.0);
    tmp.resize(3);
    return (_pCpu.getModel() + "\n" + std::to_string(_pCpu.getCore()) + "core * " + tmp);
}

std::string QTOut::getRamTotal() const {
	return (std::to_string(_pRam.getUTotalMemory()));
}

std::string QTOut::getDateTime() const {
	return (_pDate.getDateTime() + "\n" +_pDate.getTime());
}

std::string QTOut::getNet() const {
	return ("NET: " + _pNet.getNet());
}

float QTOut::getCpuIdle() const {
	return _pCpu.getIdleCpu();
}
Command QTOut::getInput() {
	return IMonitorDisplay::getInput();
}
