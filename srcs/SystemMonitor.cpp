#include "SystemMonitor.hpp"

#include "Common.hpp"
#include "NcursesOut.hpp"
#include "IMonitorDisplay.hpp"

SystemMonitor::SystemMonitor()
    : mMonitorDisplay( NULL )
{

}
SystemMonitor::~SystemMonitor()
{
    delete mMonitorDisplay;
}
SystemMonitor::SystemMonitor( const SystemMonitor& src )
{
    *this = src;
}
SystemMonitor& SystemMonitor::operator=( const SystemMonitor& src )
{
    mMonitorDisplay = src.mMonitorDisplay;

    return *this;
}
void SystemMonitor::run( eDisplayTarget target )
{
    init( target );

    if ( mMonitorDisplay )
    {
        Command command = UNKNOWN;

        while ( command != EXIT )
        {
            mMonitorDisplay->printOut();
            
            command = mMonitorDisplay->getInput();
        }
    }
}
void SystemMonitor::init( eDisplayTarget target )
{
    switch ( target )
    {
    case TERMINAL_WND:
        mMonitorDisplay = new NcursesOut();
        break;
    case GRAPHIC_WND:
        std::cout << "GRAPHIC DISPLAY MODE NOT IMPLEMENTED" << std::endl;
        break;
    default:
        break;
    }
}
