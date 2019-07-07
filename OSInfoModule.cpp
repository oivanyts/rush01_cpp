#include "OSInfoModule.hpp"
#include <sys/utsname.h>
#include <iostream>
#include <sstream>

OSInfoModule::OSInfoModule() {
getInfo();
}

OSInfoModule::~OSInfoModule() {

}


OSInfoModule::OSInfoModule(const OSInfoModule &copy) {
    *this = copy;
}

OSInfoModule & OSInfoModule::operator=(const OSInfoModule&) {
    return *this;
}

std::string OSInfoModule::getSys() const {
    return this-> _sysName;
}

std::string OSInfoModule::getRelease(){
    return this-> _releaseName;
}

int OSInfoModule::getOSVersion1() const {
    return this->_OSVersion1;
}

int OSInfoModule::getOSVersion2() const {
    return this->_OSVersion2;
}

int OSInfoModule::getOSVersion3() const {
    return this->_OSVersion3;
}

// int main() 
// {
//   cout << "Enter grades : ";
//   string grades;
//   getline(cin, grades);
//   cout << "Grades are : " << grades << endl;
//   return 0;
// }

int OSInfoModule::GetOSVersionComponent(int component) {
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
    std::cout << std::endl;
    std::cout << "*************** OS INFO MODULE ****************" << std::endl;
    struct utsname name;
    uname(&name);

    this->_releaseName = name.release;
    this->_sysName = name.sysname;
    this->_OSVersion1 = GetOSVersionComponent(1);
    this->_OSVersion2 = GetOSVersionComponent(2);
    this->_OSVersion3 = GetOSVersionComponent(3);

    std::stringstream ss;
    ss << "System Version: " << _sysName 
        << std::endl << "Kernel Version: " 
        << _releaseName << std::endl
        << "OS version: " << _OSVersion1
        << "." << _OSVersion2
        << "." << _OSVersion3
        << std::endl;

    return ss.str();
}


