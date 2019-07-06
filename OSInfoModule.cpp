#include "OSInfoModule.hpp"
#include <sys/utsname.h>
#include <iostream>
#include <sstream>

OSInfoModule::OSInfoModule() {

}

OSInfoModule::~OSInfoModule() {

}

int OSInfoModule::GetOSVersionComponent(int component) {
    std::cout << std::endl;
    std::cout << "*************** OS INFO MODULE ****************" << std::endl;
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

MType OSInfoModule::getInfo() {
	struct utsname name;
    uname(&name);
	std::stringstream ss;
	ss << "System Version: " << name.sysname 
		<< std::endl << "Kernel Version: " 
		<< name.release << std::endl
		<< "OS version: " << GetOSVersionComponent(1)
		<< "." << GetOSVersionComponent(2)
		<< "." << GetOSVersionComponent(3)
		<< std::endl;

	return ss.str();
}


