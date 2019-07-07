#ifndef DATETIMEMODULE_HPP
#define DATETIMEMODULE_HPP
#include "IMonitorModule.hpp"

class DateTimeModule : public IMonitorModule {
	public:
		DateTimeModule();
		DateTimeModule(DateTimeModule const &copy);
		DateTimeModule &operator=(DateTimeModule const &over);
		~DateTimeModule();

		std::string getDateTime() const;
        std::string getTime() const;

		MType getInfo();
		
	private:
		std::string _dt;
        std::string _time;

};

#endif

