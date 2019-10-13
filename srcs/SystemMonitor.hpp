#ifndef SYSTEMMONITOR_H
# define SYSTEMMONITOR_H

#include "Common.hpp"
#include "IMonitorDisplay.hpp"

class SystemMonitor
{

public:
    SystemMonitor();
    ~SystemMonitor();

    void run( eDisplayTarget target );

private:
    SystemMonitor( const SystemMonitor& src );
    SystemMonitor& operator=( const SystemMonitor& src );

    void init( eDisplayTarget target );


    IMonitorDisplay* mMonitorDisplay;
};

#endif