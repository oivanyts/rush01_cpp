#include "NcursesOut.hpp"

NcursesOut::NcursesOut() {
    int x;
    int y;

//    this->_pOs = new OSInfoModule;
//    this->_pHost = new HostnameModule;
//    this->_pDate = new DateTimeModule;
//    this->_pCpu = new CPUModule;
//    this->_pRam = new RAMModule;
//    this->_pNet = new NetworkModule;


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
    getmaxyx(stdscr, y, x);

    this->y_wmax = y;
    this->x_wmax = x;
    mainWin = newwin(this->y_wmax - 1, this->x_wmax - 1, 0, 0);
    printStatic();
}

//NcursesOut::NcursesOut(const NcursesOut &copy)
//{
//	*this = copy;
//}

void NcursesOut::updateInfo() {
	_pOs.getInfo();
	_pHost.getInfo();
	_pDate.getInfo();
	_pCpu.getInfo();
	_pRam.getInfo();
    _pNet.getInfo();
}
std::string NcursesOut::getHostStr() const {
	return ("Host name : " + _pHost.getHost());
}
std::string NcursesOut::getOsStr()  {// const
	return ("Version " + _pOs.getInfo());
}
std::string NcursesOut::getCpuModel() const {
	return ("CPU: " + _pCpu.getModel());
}
std::string NcursesOut::getNet() const {
    return ("NET: " + _pNet.getNet());
}

void    NcursesOut::printOut() {
    while(true) {
        this->_pRam.getInfo();
        this->_pDate.getInfo();
        this->_pNet.getInfo();
        this->_pCpu.getInfo();

        printRam();
        printStatic();

        if (getch() == 'q') {
            delwin(mainWin);
            endwin();
            exit(0);
        }
    }

}

void                    NcursesOut::printRam() {
    int size = 25;

    wattron(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 22, 1, "Total memory: ");
    wattroff(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 22, size, "%llu MB", this->_pRam.getUTotalMemory());
    wattron(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 24, 1, "Used memory:");
    wattroff(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 24, size, "%llu MB", this->_pRam.getUsedMemoty());
    wattron(mainWin, COLOR_PAIR(134));

    wattron(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 26, 1, "Free memory:");
    wattroff(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 26, size, "%llu MB", this->_pRam.getFreeMemory());
    wattron(mainWin, COLOR_PAIR(134));

    std::string tmp = this->_pDate.getInfo();
    wattron(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 12, 1, "Current date and time: ");
    wattroff(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 12, size, tmp.c_str());

    tmp = this->_pNet.getNet();
    wattron(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 28, 1, "Network info: ");
    wattroff(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 28, size, tmp.c_str());


    wattron(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 20, 1, "CPU Idle:");
    wattroff(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 20, size, "%f", this->_pCpu.getIdleCpu());
    wattron(mainWin, COLOR_PAIR(134));

    wrefresh(mainWin);
    werase(mainWin);
}

void                NcursesOut::printStatic() {
    std::string tmp;
    int size = 25;

    this->_pHost.getInfo();
    this->_pOs.getInfo();

    tmp = this->_pHost.getHost();
    wattron(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 1, 1, "Host: ");
    wattroff(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 1, size, tmp.c_str());

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
    mvwprintw(mainWin, 14, 1, "CPU model: ");
    wattroff(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 14, size, tmp.c_str());

    tmp = std::to_string(this->_pCpu.hatHW());
    wattron(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 16, 1, "Clock speed:: ");
    wattroff(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 16, size, tmp.c_str());

    wattron(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 18, 1, "Count cores: ");
    wattroff(mainWin, COLOR_PAIR(1));
    mvwprintw(mainWin, 18, size, "%i", this->_pCpu.getCore());
}

NcursesOut::~NcursesOut() {
    system ("reset");
    delwin(mainWin);
    endwin();
}