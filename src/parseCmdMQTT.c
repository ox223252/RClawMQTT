#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdint.h>

// /
// └── Roboclaw
//     └── R2O / O2R
//         └── set / get
//             ├── Codeur
//             │   ├── Left
//             │   │   └── Value
//             │   └── Right
//             │       └── Value
//             └── Motor
//                 ├── Left
//                 │   ├── Acc
//                 │   ├── D
//                 │   ├── I
//                 │   ├── P
//                 │   ├── QPPS
//                 │   └── Speed
//                 │       ├── order
//                 │       └── value
//                 └── Right
//                     ├── Acc
//                     ├── D
//                     ├── I
//                     ├── P
//                     ├── QPPS
//                     └── Speed
//                         ├── order
//                         └── value

uint32_t getIdFrom ( const char * str )
{
	uint32_t rt = 0;
	if ( rt++, !strcmp( str, "/roboclaw/r2o/set/codeur/m1/value" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/r2o/set/codeur/m2/value" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/r2o/set/motor/m1" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/r2o/set/motor/m1/acc" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/r2o/set/motor/m1/d" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/r2o/set/motor/m1/i" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/r2o/set/motor/m1/p" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/r2o/set/motor/m1/qpps" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/r2o/set/motor/m1/speed/order" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/r2o/set/motor/m1/speed/value" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/r2o/set/motor/m2" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/r2o/set/motor/m2/acc" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/r2o/set/motor/m2/d" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/r2o/set/motor/m2/i" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/r2o/set/motor/m2/p" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/r2o/set/motor/m2/qpps" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/r2o/set/motor/m2/speed/order" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/r2o/set/motor/m2/speed/value" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/o2r/set/codeur/m1/value" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/o2r/set/codeur/m1/value" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/o2r/set/motor/m1/acc" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/o2r/set/motor/m1/d" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/o2r/set/motor/m1/i" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/o2r/set/motor/m1/p" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/o2r/set/motor/m1/qpps" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/o2r/set/motor/m1/speed/order" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/o2r/set/motor/m1/speed/value" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/o2r/set/motor/m2/acc" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/o2r/set/motor/m2/d" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/o2r/set/motor/m2/i" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/o2r/set/motor/m2/p" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/o2r/set/motor/m2/qpps" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/o2r/set/motor/m2/speed/order" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/o2r/set/motor/m2/speed/value" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/r2o/get/codeur/m1/value" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/r2o/get/codeur/m2/value" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/r2o/get/motor/m1/acc" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/r2o/get/motor/m1/d" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/r2o/get/motor/m1/i" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/r2o/get/motor/m1/p" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/r2o/get/motor/m1/qpps" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/r2o/get/motor/m1/speed/order" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/r2o/get/motor/m1/speed/value" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/r2o/get/motor/m2/acc" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/r2o/get/motor/m2/d" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/r2o/get/motor/m2/i" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/r2o/get/motor/m2/p" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/r2o/get/motor/m2/qpps" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/r2o/get/motor/m2/speed/order" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/r2o/get/motor/m2/speed/value" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/o2r/get/codeur/m1/value" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/o2r/get/codeur/m2/value" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/o2r/get/motor/m1/acc" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/o2r/get/motor/m1/d" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/o2r/get/motor/m1/i" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/o2r/get/motor/m1/p" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/o2r/get/motor/m1/qpps" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/o2r/get/motor/m1/speed/order" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/o2r/get/motor/m1/speed/value" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/o2r/get/motor/m2/acc" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/o2r/get/motor/m2/d" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/o2r/get/motor/m2/i" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/o2r/get/motor/m2/p" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/o2r/get/motor/m2/qpps" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/o2r/get/motor/m2/speed/order" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/o2r/get/motor/m2/speed/value" ) )
	{
		return ( rt );
	}
	else if ( rt++, !strcmp( str, "/roboclaw/o2r/verify/cmd/length" ) )
	{
		return ( rt );
	}
	return ( 0 );
}

