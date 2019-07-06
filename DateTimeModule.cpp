#include "DateTimeModule.hpp"
#include <iostream>
#include <ctime>

DateTimeModule::DateTimeModule() {

}

DateTimeModule::~DateTimeModule() {
	
}

MType DateTimeModule::getInfo() {
	std::cout << std::endl;
	std::cout << "*************** DATE/TIME MODULES ****************" << std::endl;
	time_t now = time(0);
   
   char* dt = ctime(&now);
	return std::string(dt);
}