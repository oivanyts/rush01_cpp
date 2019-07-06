// #include <sys/param.h>
// #include <sys/sysctl.h>
// #include <errno.h>
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>sysctlbyname

// struct osver {
//     int minor;
//     int sub;
// } ;
// typedef struct osver osxver ;
// void macosx_ver(char *darwinversion, osxver *osxversion ) ;
// char *osversionString(void) ;

// int main( int argc, char *argv[] )
// {
//     osxver foundver;
//     char *osverstr= NULL ;
//     osverstr=osversionString() ;
//     macosx_ver(osverstr, &foundver ) ;
//     printf("Mac os x version = 10.%d.%d\n",foundver.minor,foundver.sub );
//     free(osverstr);
//     return 0;
// }

// char *osversionString(void) {
//     int mib[2];
//     size_t len;
//     char *kernelVersion=NULL;
//     mib[0] = CTL_KERN;
//     mib[1] = KERN_OSRELEASE;

//     if (sysctl(mib, 2, NULL, &len, NULL, 0) < 0 ) {
//         fprintf(stderr,"%s: Error during sysctl probe call!\n",__PRETTY_FUNCTION__ );
//         fflush(stdout);
//         exit(4) ;
//     }

//     kernelVersion = (char*)malloc(len );
//     if (kernelVersion == NULL ) {
//         fprintf(stderr,"%s: Error during malloc!\n",__PRETTY_FUNCTION__ );
//         fflush(stdout);
//         exit(4) ;
//     }
//     if (sysctl(mib, 2, kernelVersion, &len, NULL, 0) < 0 ) {
//         fprintf(stderr,"%s: Error during sysctl get verstring call!\n",__PRETTY_FUNCTION__ );
//         fflush(stdout);
//         exit(4) ;
//     }

//     return kernelVersion ;
// }

// void macosx_ver(char *darwinversion, osxver *osxversion ) {
// /*
//     From the book Mac Os X and IOS Internals:
//     In version 10.1.1, Darwin (the core OS) was renumbered from v1.4.1 to 5.1,
//     and since then has followed the OS X numbers consistently by being four
//     numbers ahead of the minor version, and aligning its own minor with the
//     sub-version.
// */
//     char firstelm[2]= {0,0},secElm[2]={0,0};

//     if (strlen(darwinversion) < 5 ) {
//         fprintf(stderr,"%s: %s Can't possibly be a version string. Exiting\n",__PRETTY_FUNCTION__,darwinversion);
//         fflush(stdout);
//         exit(2);
//     }
//     char *s=darwinversion,*t=firstelm,*curdot=strchr(darwinversion,'.' );

//     while ( s != curdot )
//         *t++ = *s++;
//     t=secElm ;
//     curdot=strchr(++s,'.' );
//     while ( s != curdot )
//         *t++ = *s++;
//     int maj=0, min=0;
//     maj= (int)strtol(firstelm, (char **)NULL, 10);
//     if ( maj == 0 && errno == EINVAL ) {
//         fprintf(stderr,"%s Error during conversion of version string\n",__PRETTY_FUNCTION__);
//         fflush(stdout);
//         exit(4);
//     }

//     min=(int)strtol(secElm, (char **)NULL, 10);

//     if ( min  == 0 && errno == EINVAL ) {
//         fprintf(stderr,"%s: Error during conversion of version string\n",__PRETTY_FUNCTION__);
//         fflush(stdout);
//         exit(4);
//     }
//     osxversion->minor=maj-4;
//     osxversion->sub=min;
// }







// #include <stdio.h>

/*!
  @brief    Returns one component of the OS version
  @param    component  1=major, 2=minor, 3=bugfix
 */
// int GetOSVersionComponent(int component) {
//     char cmd[64] ;
//     sprintf(
//             cmd,
//             "sw_vers -productVersion | awk -F '.' '{print $%d}'",
//             component
//     ) ;
//     FILE* stdoutFile = popen(cmd, "r") ;

//     int answer = 0 ;
//     if (stdoutFile) {
//         char buff[16] ;
//         char *stdout = fgets(buff, sizeof(buff), stdoutFile) ;
//         pclose(stdoutFile) ;
//         sscanf(stdout, "%d", &answer) ;
//     }

//     return answer ;
// }

// #include <sys/utsname.h>
// #include <iostream>

// int main(int argc, const char * argv[]) {
//     printf(
//            "Your OS version is: %d.%d.%d\n",
//            GetOSVersionComponent(1),
//            GetOSVersionComponent(2),
//            GetOSVersionComponent(3)
//            ) ;
//     struct utsname name;
//     uname(&name);
//     std::cout << name.sysname << std::endl << name.release << std::endl << name.version << std::endl;

//     return 0 ;
// }



















// #include <iostream>
// #include <stdio.h>
// #include <stdint.h>
// #include <sys/types.h>
// #include <sys/sysctl.h>

// void show_cpu_info(void)
// {
//     char buffer[1024];
//     size_t size=sizeof(buffer);
//     if (sysctlbyname("machdep.cpu.brand_string", &buffer, &size, NULL, 0) < 0) {
//         perror("sysctl");
//     }
//     std::cout << buffer << '\n';
// }

// int main() {
//   show_cpu_info();
// }














// #include <mach/mach_init.h>
// #include <mach/mach_error.h>
// #include <mach/mach_host.h>
// #include <mach/vm_map.h>
// #include <iostream>

// static unsigned long long _previousTotalTicks = 0;
// static unsigned long long _previousIdleTicks = 0;

// // Returns 1.0f for "CPU fully pinned", 0.0f for "CPU idle", or somewhere in between
// // You'll need to call this at regular intervals, since it measures the load between
// // the previous call and the current one.
// float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
// {
//   unsigned long long totalTicksSinceLastTime = totalTicks-_previousTotalTicks;
//   unsigned long long idleTicksSinceLastTime  = idleTicks-_previousIdleTicks;
//   float ret = 1.0f-((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime)/totalTicksSinceLastTime : 0);
//   _previousTotalTicks = totalTicks;
//   _previousIdleTicks  = idleTicks;
//   return ret;
// }

// float GetCPULoad()
// {
//    host_cpu_load_info_data_t cpuinfo;
//    mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
//    if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t)&cpuinfo, &count) == KERN_SUCCESS)
//    {
//       unsigned long long totalTicks = 0;
//       for(int i=0; i<CPU_STATE_MAX; i++) totalTicks += cpuinfo.cpu_ticks[i];
//       return CalculateCPULoad(cpuinfo.cpu_ticks[CPU_STATE_IDLE], totalTicks);
//    }
//    else return -1.0f;
// }





// int main() {
//   while(1){

//   }
//   std::cout << GetCPULoad() << std::endl;
// }




// #include <mach/vm_statistics.h>
// #include <mach/mach_types.h>
// #include <mach/mach_init.h>
// #include <mach/mach_host.h>

// int main(int argc, const char * argv[]) {
//     vm_size_t page_size;
//     mach_port_t mach_port;
//     mach_msg_type_number_t count;
//     vm_statistics64_data_t vm_stats;

//     mach_port = mach_host_self();
//     count = sizeof(vm_stats) / sizeof(natural_t);
//     if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
//         KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,
//                                         (host_info64_t)&vm_stats, &count))
//     {
//         long long free_memory = (int64_t)vm_stats.free_count * (int64_t)page_size;

//         long long used_memory = ((int64_t)vm_stats.active_count +
//                                  (int64_t)vm_stats.inactive_count +
//                                  (int64_t)vm_stats.wire_count) *  (int64_t)page_size;
//         printf("free memory: %lld\nused memory: %lld\n", free_memory, used_memory);
//     }

//     return 0;
// }



// #include <sys/types.h>
// #include <sys/sysctl.h>
// #include <iostream>

// int main() {
//   int mib[2];
//   int64_t physical_memory;
//   mib[0] = CTL_HW;
//   mib[1] = HW_MEMSIZE;
//   size_t length = sizeof(int64_t);
//   sysctl(mib, 2, &physical_memory, &length, NULL, 0);
//   std::cout << physical_memory / 1000000000 << "GB" << std::endl;
// }



























#include <stdio.h>

/*!
  @brief    Returns one component of the OS version
  @param    component  1=major, 2=minor, 3=bugfix
 */
int GetOSVersionComponent(int component) {
    char cmd[64] ;
    sprintf(
            cmd,
            "sw_vers -productVersion | awk -F '.' '{print $%d}'",
            component
    ) ;
    FILE* stdoutFile = popen(cmd, "r") ;

    int answer = 0 ;
    if (stdoutFile) {
        char buff[16] ;
        char *stdout = fgets(buff, sizeof(buff), stdoutFile) ;
        pclose(stdoutFile) ;
        sscanf(stdout, "%d", &answer) ;
    }

    return answer ;
}

int main(int argc, const char * argv[]) {
    printf(
           "Your OS version is: %d.%d.%d\n",
           GetOSVersionComponent(1),
           GetOSVersionComponent(2),
           GetOSVersionComponent(3)
           ) ;

    return 0 ;
}















