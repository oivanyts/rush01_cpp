#include "QTOut.hpp"

QTOut::QTOut(OSInfoModule &os, HostnameModule &host, DateTimeModule &dt, CPUModule &cpu, RAMModule &ram) {
	this->_os = os;
	this->_host = host;
	this->_dt = dt;
	this->_cpu = cpu;
	this->_ram = ram;
}

QTOut::~QTOut() {
	
}

