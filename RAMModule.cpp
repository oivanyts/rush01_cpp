#include "RAMModule.hpp"
#include <iostream>
#include <sstream>
#include <mach/vm_statistics.h>
#include <mach/mach_types.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>
#include <sys/sysctl.h>

RAMModule::RAMModule() {
getInfo();
}

RAMModule::~RAMModule() {

}

RAMModule::RAMModule(const RAMModule &copy) {
    *this = copy;
}


RAMModule& RAMModule::operator=(const RAMModule&) {
    return *this;
}

long long RAMModule::getFreeMemory() const {
    return this->_free_memory;
}

long long RAMModule::getUsedMemoty() const {
    return this->_used_memory;
}

long long RAMModule::getUTotalMemory() const {
    return this->_total_memory;
}


MType RAMModule::getInfo() {
	std::cout << std::endl;
	std::cout << "*************** RAM MODULE ****************" << std::endl;
	vm_size_t page_size;
    mach_port_t mach_port;
    mach_msg_type_number_t count;
    vm_statistics64_data_t vm_stats;

    mach_port = mach_host_self();
    count = sizeof(vm_stats) / sizeof(natural_t);
    if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
        KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,
                                        (host_info64_t)&vm_stats, &count))
    {
        this->_free_memory = (int64_t)vm_stats.free_count * (int64_t)page_size;

         this->_used_memory = ((int64_t)vm_stats.active_count +
                                 (int64_t)vm_stats.inactive_count +
                                 (int64_t)vm_stats.wire_count) *  (int64_t)page_size;
         this->_total_memory = _free_memory + _used_memory;
    }

    std::stringstream ss;
    ss << "Free memory: " << _free_memory << std::endl
        << "Used memory: " << _used_memory << std::endl
        << "Total memory: " << _total_memory << std::endl;

    return ss.str();
}




