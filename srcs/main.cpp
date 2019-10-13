#include <iostream>
#include "HostnameModule.hpp"
#include "OSInfoModule.hpp"
#include "DateTimeModule.hpp"
#include "CPUModule.hpp"
#include "RAMModule.hpp"
#include "NetworkModule.hpp"
#include "NcursesOut.hpp"
#include "IMonitorDisplay.hpp"
#include "Common.hpp"
#include "QTOut.hpp"

#include <unistd.h>
#include <sys/types.h>
#include <iostream>
#include <sys/param.h>
#include <sys/sysctl.h>
#include <ncurses.h>

int main() {
	IMonitorDisplay *visualMode = new NcursesOut();
	bool isNcurses = true;
	Command command;
	while (true) {
		visualMode->printOut();
		command = visualMode->getInput();
		if (command == SPACE) {
			// delete(visualMode);
			if (isNcurses) {
				// visualMode = new QTOut();
//				std::cout << "Call graphical" << std::endl;
				isNcurses = false;
			}
			else {
				visualMode = new NcursesOut();
				isNcurses = true;
			}
		}
		else if (command == EXIT) {
			delete(visualMode);
			break;
		}
	}

	return 0;
}