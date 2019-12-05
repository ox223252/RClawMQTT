#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdint.h>

static const char *_parseCmdMQTT_available[] = {
	"roboclaw/r2o/set/codeur/m1/value",
	"roboclaw/r2o/set/codeur/m2/value",
	"roboclaw/r2o/set/motor/m1/acc",
	"roboclaw/r2o/set/motor/m1/d",
	"roboclaw/r2o/set/motor/m1/i",
	"roboclaw/r2o/set/motor/m1/p",
	"roboclaw/r2o/set/motor/m1/qpps",
	"roboclaw/r2o/set/motor/m1/speed/order",
	"roboclaw/r2o/set/motor/m1/speed/value",
	"roboclaw/r2o/set/motor/m2/acc",
	"roboclaw/r2o/set/motor/m2/d",
	"roboclaw/r2o/set/motor/m2/i",
	"roboclaw/r2o/set/motor/m2/p",
	"roboclaw/r2o/set/motor/m2/qpps",
	"roboclaw/r2o/set/motor/m2/speed/order",
	"roboclaw/r2o/set/motor/m2/speed/value",
	"roboclaw/o2r/set/codeur/m1/value",
	"roboclaw/o2r/set/codeur/m2/value",
	"roboclaw/o2r/set/motor/m1/acc",
	"roboclaw/o2r/set/motor/m1/d",
	"roboclaw/o2r/set/motor/m1/i",
	"roboclaw/o2r/set/motor/m1/p",
	"roboclaw/o2r/set/motor/m1/qpps",
	"roboclaw/o2r/set/motor/m1/speed/order",
	"roboclaw/o2r/set/motor/m1/speed/value",
	"roboclaw/o2r/set/motor/m2/acc",
	"roboclaw/o2r/set/motor/m2/d",
	"roboclaw/o2r/set/motor/m2/i",
	"roboclaw/o2r/set/motor/m2/p",
	"roboclaw/o2r/set/motor/m2/qpps",
	"roboclaw/o2r/set/motor/m2/speed/order",
	"roboclaw/o2r/set/motor/m2/speed/value",
	"roboclaw/r2o/get/codeur/m1/value",
	"roboclaw/r2o/get/codeur/m2/value",
	"roboclaw/r2o/get/motor/m1/acc",
	"roboclaw/r2o/get/motor/m1/d",
	"roboclaw/r2o/get/motor/m1/i",
	"roboclaw/r2o/get/motor/m1/p",
	"roboclaw/r2o/get/motor/m1/qpps",
	"roboclaw/r2o/get/motor/m1/speed/order",
	"roboclaw/r2o/get/motor/m1/speed/value",
	"roboclaw/r2o/get/motor/m2/acc",
	"roboclaw/r2o/get/motor/m2/d",
	"roboclaw/r2o/get/motor/m2/i",
	"roboclaw/r2o/get/motor/m2/p",
	"roboclaw/r2o/get/motor/m2/qpps",
	"roboclaw/r2o/get/motor/m2/speed/order",
	"roboclaw/r2o/get/motor/m2/speed/value",
	"roboclaw/o2r/get/codeur/m1/value",
	"roboclaw/o2r/get/codeur/m2/value",
	"roboclaw/o2r/get/motor/m1/acc",
	"roboclaw/o2r/get/motor/m1/d",
	"roboclaw/o2r/get/motor/m1/i",
	"roboclaw/o2r/get/motor/m1/p",
	"roboclaw/o2r/get/motor/m1/qpps",
	"roboclaw/o2r/get/motor/m1/speed/order",
	"roboclaw/o2r/get/motor/m1/speed/value",
	"roboclaw/o2r/get/motor/m2/acc",
	"roboclaw/o2r/get/motor/m2/d",
	"roboclaw/o2r/get/motor/m2/i",
	"roboclaw/o2r/get/motor/m2/p",
	"roboclaw/o2r/get/motor/m2/qpps",
	"roboclaw/o2r/get/motor/m2/speed/order",
	"roboclaw/o2r/get/motor/m2/speed/value",
	"roboclaw/o2r/verify/cmd/length",
	NULL
};

uint32_t getIdFrom ( const char * str )
{
	uint32_t rt = 0;
	while ( !_parseCmdMQTT_available[ rt ] )
	{
		if ( !strcmp( str, _parseCmdMQTT_available[ rt ] ) )
		{
			return ( rt + 1 );
		}
		rt++;
	}

	return ( 0 );
}

