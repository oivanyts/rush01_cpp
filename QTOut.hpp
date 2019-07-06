#ifndef QTOUT_HPP
#define QTOUT_HPP
#include "CPUModule.hpp"
#include "DateTimeModule.hpp"
#include "HostnameModule.hpp"
#include "NetworkModule.hpp"
#include "RAMModule.hpp"
#include "OSInfoModule.hpp"



// class QTOut : public IMonitorDisplay {
class QTOut {
	public:
		QTOut(OSInfoModule &os, HostnameModule &host, DateTimeModule &dt, CPUModule &cpu, RAMModule &ram, NetworkModule &net);
		~QTOut();
//	private:
		OSInfoModule _os;
		HostnameModule _host;
		DateTimeModule _dt;
		CPUModule _cpu;
		RAMModule _ram;
		NetworkModule _net;
};

#endif


