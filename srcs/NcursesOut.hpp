#ifndef NCURSESOUT_HPP
#define NCURSESOUT_HPP

#include "IMonitorDisplay.hpp"

#include "DateTimeModule.hpp"
#include "HostnameModule.hpp"
#include "NetworkModule.hpp"
#include "RAMModule.hpp"
#include "OSInfoModule.hpp"
#include "CPUModule.hpp"
#include "Common.hpp"

# include <iostream>
# include <ctime>
# include <sstream>
# include <string>
# include <vector>
# include <ncurses.h>


class NcursesOut : public IMonitorDisplay
{
public:
	NcursesOut();
	virtual ~NcursesOut();

	/* IMonitorDisplay */
	virtual Command getInput();
	virtual void updateInfo();
	virtual void printOut();

private:
	NcursesOut(const NcursesOut &copy);
	NcursesOut &operator = (const NcursesOut &over);

	void 	printStatic();
	void 	printRam();

	int			y_wmax;
	int 		x_wmax;
	WINDOW*		mainWin;
};

#endif