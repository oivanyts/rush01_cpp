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

DateTimeModule & DateTimeModule::operator=(DateTimeModule const &) {
	return *this;
}

std::string DateTimeModule::getDateTime() const {
	return this->_dt;
}

MType DateTimeModule::getInfo() {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);
    std::string tmp(buffer);
    _dt = tmp;
    return tmp;
}

