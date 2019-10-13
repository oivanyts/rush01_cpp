#include "DateTimeModule.hpp"
#include <iostream>
#include <ctime>

DateTimeModule::DateTimeModule() {
}

DateTimeModule::~DateTimeModule() {
	
}

DateTimeModule::DateTimeModule(DateTimeModule const &copy) {
	*this = copy;
}

DateTimeModule & DateTimeModule::operator=(DateTimeModule const &over) {
    _dt = over._dt;
    _time = over._time;
	return *this;
}

std::string DateTimeModule::getDateTime() const {
	return this->_dt;
}

std::string DateTimeModule::getTime() const {
    return this->_time;
}

MType DateTimeModule::getInfo() {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer,sizeof(buffer),"%d-%m-%Y",timeinfo);
    std::string tmp(buffer);
    _dt = tmp;
    strftime(buffer,sizeof(buffer),"%H:%M:%S",timeinfo);
    std::string tmp1(buffer);
    _time = tmp1;
    return tmp + " " + tmp1;
}

