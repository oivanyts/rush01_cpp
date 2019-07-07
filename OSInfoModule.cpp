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

OSInfoModule & OSInfoModule::operator=(const OSInfoModule &over) {
    _releaseName = over._releaseName;
    _sysName = over._sysName;
    _version = over._version;
    return *this;
}

std::string OSInfoModule::getSys() const {
    return this-> _sysName;
}

std::string OSInfoModule::getRelease() const{
    return this-> _releaseName;
}

std::string OSInfoModule::getVersion() const {
    return this->_version;
}


std::string OSInfoModule::GetOSVersionComponent() {
    char cmd[64] ;
    if (FILE * stream = popen("sw_vers -productVersion", "r"))
    {
        fgets(cmd, sizeof(cmd), stream);
        pclose(stream);
    }
    return std::string(cmd);
}

MType OSInfoModule::getInfo() {
    struct utsname name;
    uname(&name);

    this->_releaseName = name.release;
    this->_sysName = name.sysname;
    this->_version = GetOSVersionComponent();

    std::stringstream ss;
     ss << "System Version: " << _sysName 
        << std::endl << "Kernel Version: " 
        << _releaseName << std::endl
        << "OS version: " << _version
        << std::endl;

    return ss.str();
}


