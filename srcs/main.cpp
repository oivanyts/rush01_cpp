#include "Common.hpp"
#include "SystemMonitor.hpp"

int main( int ac, char** av )
{
	SystemMonitor sysMonitor;
	eDisplayTarget displayTarget = TERMINAL_WND;

	if ( ac > 1 && static_cast< std::string >( av[ 1 ] ) == "-g" )
	{
		displayTarget = GRAPHIC_WND;
	}

	sysMonitor.run( displayTarget );

	return 0;
}