#ifndef CPUMODULE_HPP
#define CPUMODULE_HPP

#include <stdint.h>
#include "IMonitorModule.hpp"

class CPUModule : public IMonitorModule {
	public:
		CPUModule();
		CPUModule(const CPUModule &copy);
		CPUModule& operator=(const CPUModule&);
		~CPUModule();

		std::string getModel() const;
		uint64_t hatHW() const;
        int getCore() const;
		std::string getActivity() const;
		float getIdleCpu() const;

		MType getInfo();

	protected:
		uint64_t _hw;
        int _core;
		char	_activity[4096];

        std::string _modelReal;
		float 	_idleCPU;
};

#endif
