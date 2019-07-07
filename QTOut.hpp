#ifndef QTOUT_HPP
#define QTOUT_HPP


#include "IMonitorDisplay.hpp"



class QTOut : public IMonitorDisplay {
public:
    QTOut();
    ~QTOut();
    void updateInfo();
private:

};

#endif


