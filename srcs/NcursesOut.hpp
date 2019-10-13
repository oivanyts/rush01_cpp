#ifndef NCURSESOUT_HPP
#define NCURSESOUT_HPP
#include "CPUModule.hpp"
#include "DateTimeModule.hpp"
#include "HostnameModule.hpp"
#include "NetworkModule.hpp"
#include "RAMModule.hpp"
#include "OSInfoModule.hpp"
#include "Common.hpp"

#include "IMonitorDisplay.hpp"

# include <iostream>
# include <ctime>
# include <sstream>
# include <string>
# include <vector>
# include <ncurses.h>


class NcursesOut : public IMonitorDisplay {
	public:
        NcursesOut();
		NcursesOut(const NcursesOut &copy);
		NcursesOut &operator = (const NcursesOut &over);
		~NcursesOut();
		std::string getDateTime() const ;
		std::string getRamTotal() const ;
		std::string getHostStr() const;
		std::string getOsStr() ; //
		std::string getCpuModel() const;
		std::string getNet() const;
		float getCpuIdle() const;

		void 	printOut();
private:
        int			y_wmax;
		int 		x_wmax;
		WINDOW*		mainWin;
		void 	printStatic();
		void 	printRam();
};

#endif