#ifndef RAMMODULE_HPP
#define RAMMODULE_HPP
#include "IMonitorModule.hpp"

class RAMModule : public IMonitorModule {
	public:
		RAMModule();
		~RAMModule();
		RAMModule(const RAMModule &copy);
		RAMModule& operator=(const RAMModule&);
		MType getInfo();

		long long getFreeMemory() const;
		long long getUsedMemoty() const;
		long long getUTotalMemory() const;
		
	private:
		long long _free_memory;
		long long _used_memory;
		long long _total_memory;
};

#endif
