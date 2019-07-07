#ifndef QTOUT_HPP
#define QTOUT_HPP


#include "IMonitorDisplay.hpp"



class QTOut : public IMonitorDisplay {
public:
    QTOut();
    ~QTOut();
	void 	printOut() {};
	QTOut(const QTOut &copy);
	QTOut &operator = (const QTOut &over);
	std::string getHostStr() const;
	std::string getOsStr() ;
	std::string getCpuModel() const;
	std::string getDateTime() const;
	std::string getRamTotal() const;
	std::string getNet() const;

	float getCpuIdle() const;
	Command    getInput();
private:

};

#endif


