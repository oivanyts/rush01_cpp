#include <iostream>

#include "Common.hpp"
#include "NcursesOut.hpp"
#include "IMonitorDisplay.hpp"

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