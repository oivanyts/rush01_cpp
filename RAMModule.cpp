#include "RAMModule.hpp"
#include <iostream>
#include <sstream>
#include <mach/vm_statistics.h>
#include <mach/mach_types.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>

RAMModule::RAMModule() {

}

RAMModule::~RAMModule() {

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
        long long free_memory = (int64_t)vm_stats.free_count * (int64_t)page_size;

        long long used_memory = ((int64_t)vm_stats.active_count +
                                 (int64_t)vm_stats.inactive_count +
                                 (int64_t)vm_stats.wire_count) *  (int64_t)page_size;
        printf("free memory: %lld\nused memory: %lld\n", free_memory, used_memory);
    }
    return std::string("");
    	// long long total_memory = free_memory + used_memory;
    // printf("free memory: %lld\nused memory: %lld\n", free_memory, used_memory);
    // std::stringstream ss;
    // ss << "Free memory: " << free_memory << std::endl
    // 	<< "Used memoty: " << used_memory << std::endl;
    // 	// << "Total memoty: " << total_memory << std::endl;
    // return ss.str();
}