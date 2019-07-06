#ifndef CPUMODULE_HPP
#define CPUMODULE_HPP
#include "IMonitorModule.hpp"

class CPUModule : public IMonitorModule {
	public:
		CPUModule();
		CPUModule(const CPUModule &copy);
		CPUModule& operator=(const CPUModule&);
		~CPUModule();

		char getModel() const;
		uint64_t hatHW() const;
		uint64_t getCore() const;
		char getActivity() const;

		MType getInfo();

	private:
		char _model[1024];
		uint64_t _hw;
		uint64_t _core;
		char	_activity[4096];

};

#endif
