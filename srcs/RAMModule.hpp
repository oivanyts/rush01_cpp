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

		long getFreeMemory() const;
		long getUsedMemoty() const;
		long getUTotalMemory() const;
		
	private:
		long _free_memory;
		long _used_memory;
		long _total_memory;
};

#endif
