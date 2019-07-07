#ifndef NCURSESOUT_HPP
#define NCURSESOUT_HPP
#include "CPUModule.hpp"
#include "DateTimeModule.hpp"
#include "HostnameModule.hpp"
#include "NetworkModule.hpp"
#include "RAMModule.hpp"
#include "OSInfoModule.hpp"

//#include "IMonitorDisplay.hpp"

# include <iostream>
# include <ctime>
# include <sstream>
# include <string>
# include <vector>
# include <ncurses.h>





// class NcursesOut : public IMonitorDisplay {
class NcursesOut {
	public:
        NcursesOut();
		~NcursesOut();
		void updateInfo();
		std::string getHostStr() const;
		std::string getOsStr() const;
		std::string getCpuModel() const;
		std::string getNet() const;
		float getCpuIdle() const;

		void 	printOut();
private:
        OSInfoModule *_pOs;
        HostnameModule *_pHost;
        DateTimeModule *_pDate;
        CPUModule *_pCpu;
        RAMModule *_pRam;
        NetworkModule *_pNet;

        int			y_wmax;
		int 		x_wmax;
		WINDOW*		mainWin;
		void 	printStatic();
		void 	printRam();
};

#endif