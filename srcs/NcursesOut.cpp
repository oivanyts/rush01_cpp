#include "NcursesOut.hpp"

NcursesOut::NcursesOut()
{
    initscr();
    cbreak(); 
    noecho(); 
    curs_set(0);
    start_color();
    keypad(stdscr, TRUE); 
    nodelay(stdscr, TRUE); 
    scrollok(stdscr, FALSE);
    getmaxyx(stdscr, this->y_wmax, this->x_wmax);
    init_color(COLOR_GREEN, 0, 500, 0);
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    getmaxyx(stdscr, y_wmax, x_wmax);

    mainWin = newwin(this->y_wmax - 1, this->x_wmax - 1, 0, 0);
    printStatic();
}
NcursesOut::~NcursesOut()
{
    system ("reset");
    delwin(mainWin);
    endwin();
}
NcursesOut::NcursesOut(const NcursesOut &copy)
{
	*this = copy;
}
NcursesOut &NcursesOut::operator = (const NcursesOut &over)
{
    y_wmax = over.y_wmax;
    x_wmax = over.x_wmax;
    mainWin = over.mainWin;
    return (*this);
}
Command   NcursesOut::getInput()
{
	int g = getch();
	switch (g) {
		case ' ':
			return SPACE;
		case 'q':
			return EXIT;
		default:
			return UNKNOWN;
	}
	return UNKNOWN;
}
void NcursesOut::updateInfo()
{
	_pOs.getInfo();
	_pHost.getInfo();
	_pDate.getInfo();
	_pCpu.getInfo();
	_pRam.getInfo();
	_pNet.getInfo();
}
void    NcursesOut::printOut()
{
    werase(mainWin);
    printStatic();
    printRam();
}
void                NcursesOut::printStatic() {
    std::string tmp;
    int size = 25;

    this->_pHost.getInfo();
    this->_pOs.getInfo();

    tmp = this->_pHost.getHost();
    wattron(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 2, 1, "Host: ");
    wattroff(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 2, size, tmp.c_str());

    tmp = this->_pHost.getUser();
    wattron(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 4, 1, "User: ");
    wattroff(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 4, size, tmp.c_str());

    tmp = this->_pOs.getVersion();
    wattron(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 6, 1, "OS Version: ");
    wattroff(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 6, size, tmp.c_str());

    tmp = this->_pOs.getRelease();
    wattron(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 8, 1, "Kernel Version: ");
    wattroff(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 8, size, tmp.c_str());

    tmp = this->_pOs.getSys();
    wattron(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 10, 1, "System Version: ");
    wattroff(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 10, size, tmp.c_str());

    tmp = this->_pCpu.getModel();
    wattron(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 14, 1, "CPU : ");
    wattroff(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 14, size, tmp.c_str());

    wattron(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 16, 1, "CPU cores : ");
    wattroff(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 16, size, "%i", this->_pCpu.getCore());
}
void                    NcursesOut::printRam() {

    const float divider = 1000000000.0f;
    int size = 25;

    wattron(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 20, 1, "Total memory: ");
    wattroff(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 20, size, "%.2f GB", _pRam.getUTotalMemory() / divider );
    wattron(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 22, 1, "Used memory:");
    wattroff(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 22, size, "%.2f GB", _pRam.getUsedMemoty() / divider );
    wattron(mainWin, COLOR_PAIR(134));

    wattron(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 24, 1, "Free memory:");
    wattroff(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 24, size, "%.2f GB", _pRam.getFreeMemory() / divider );
    wattron(mainWin, COLOR_PAIR(134));

    wattron(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 12, 1, "Current date and time: ");
    wattroff(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 12, size, _pDate.getInfo().c_str());

    wattron(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 26, 1, "Network info: ");
    wattroff(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 26, size, _pNet.getNet().c_str());


    wattron(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 18, 1, "CPU Idle:");
    wattroff(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 18, size, "%.2f%%", _pCpu.getIdleCpu());
    wattron(mainWin, COLOR_PAIR(134));

    wrefresh(mainWin);
}
