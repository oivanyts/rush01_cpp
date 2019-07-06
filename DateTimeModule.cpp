#include "DateTimeModule.hpp"
#include <iostream>
#include <ctime>

DateTimeModule::DateTimeModule() {
getInfo();
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
	std::cout << std::endl;
	std::cout << "*************** DATE/TIME MODULES ****************" << std::endl;
	time_t now = time(0);
   
   	char* _dt = ctime(&now);
	return std::string(_dt);
}

