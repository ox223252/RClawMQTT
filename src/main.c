#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdint.h>
#include "./lib/config/config_arg.h"
#include "./lib/config/config_file.h"
#include "./lib/log/log.h"
#include "./lib/mosquittoInterface/mosquittoInterface.h"
#include "./lib/rclaw/rclaw.h"

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

typedef struct
{
	int rclawFd;
	struct mosquitto * mosq;
}robotDescriptor;

void onMsg ( char* topic, char* msg, void * arg )
{
	robotDescriptor *robot = arg;

	char *token = strtok( topic, "/");

	printf ( "%s : %s\n", topic, msg );

	if ( strcmp( token, "RClaw" ) == 0 )
	{ // robotclaw
		// IHM to RClow or RClaw to IHM mode
		token = strtok(NULL, "/");
		bool O2R = ( strcmp( token, "O2R" ) == 0 );
		if ( !O2R ) // robot set/get values, it already know value, soo don't treat it
		{ // if token is different as set/get it's not manage
			return;
		}

		// set or get mode
		token = strtok(NULL, "/");
		bool set = ( strcmp( token, "set" ) == 0 );
		if ( !set &&
			strcmp ( token, "get" ) )
		{
			printf ( "MOSQUITTO unknow cmd : %s %s \n", token, msg );
			return;
		}

		// motor or codeur
		token = strtok(NULL, "/");
		bool motor = ( strcmp ( token, "Motor" ) == 0 );
		if ( !motor &&
			strcmp ( token, "Codeur" ) )
		{
			printf ( "MOSQUITTO unknow cmd : %s %s \n", token, msg );
			return;
		}

		// right or left
		token = strtok(NULL, "/");
		bool right = ( strcmp( token, "right" ) );
		if ( !right &&
			strcmp( token, "left" ) )
		{
			printf ( "MOSQUITTO unknow cmd : %s %s \n", token, msg );
			return;
		}

		if ( motor )
		{
			token = strtok(NULL, "/");

			if ( strcmp ( token, "Acc" ) == 0 )
			{

			}
			else if ( strcmp ( token, "D" ) == 0 )
			{

			}
			else if ( strcmp ( token, "I" ) == 0 )
			{

			}
			else if ( strcmp ( token, "P" ) == 0 )
			{

			}
			else if ( strcmp ( token, "QPPS" ) == 0 )
			{
			}
			else if ( strcmp ( token, "Speed" ) == 0 )
			{
				token = strtok(NULL, "/");
				if ( strcmp ( token, "order" ) == 0 )
				{
					if ( set )
					{
						token = strtok(NULL, "/");
						int8_t value = atoi(token);
						rclawReadWriteData ( robot->rclawFd, DRIVE_M1_WITH_SIGNED_SPEED, &value, NULL );
					}
				}
				else if ( strcmp ( token, "value" ) == 0 )
				{
					if ( !set )
					{
						token = strtok(NULL, "/");
						int8_t value = 0;
						rclawReadWriteData ( robot->rclawFd, DRIVE_M1_WITH_SIGNED_SPEED, &value, NULL );
						mosquitto_publish ( robot->mosq, NULL, "/Roboclaw/R2O/set/Motor/Speed/value", 1, &value, 0, 0 );
					}
				}
				else
				{
					printf ( "MOSQUITTO unknow cmd : %s %s \n", token, msg );
					return;
				}
			}
			else
			{
				printf ( "MOSQUITTO unknow cmd : %s %s \n", token, msg );
				return;
			}
		}
		else
		{
			printf ( "MOSQUITTO receive : %d\n", atoi ( msg ) );
		}
	}
	else
	{
		printf ( "%s : %s\n", token, msg );
	}
}

int main ( int argc, char* argv[] )
{
	int err = 0;
	int rt = 0;


	struct
	{
		uint8_t help:1,
			quiet:1,
			verbose:1,
			#ifndef RELEASE_MODE
				color:1, // only available for debug mode
				debug:1, // only available for debug mode
			#else
				unused:2,
			#endif
			term:1,
			file:1;
	}
	flags = { 0 };
	char logFileName[ 32 ] = "out/log.txt";

	const char name[] = "robot";
	const char host[] = "127.0.0.1";
	const char lastName[] = "status";
	const char lastMsg[] = "disconnected";
	char rclawPath[64] = "/dev/ttyACM0";

	struct mosquitto * mosq;
	#pragma GCC diagnostic ignored "-Wdiscarded-qualifiers"
	MQTT_init_t mosq_init = {
		.name = name,
		.host = host,
		.port = 1883,
		.ca = NULL,
		.cert = NULL,
		.key = NULL,
		.lastName = lastName,
		.lastMsg = lastMsg
	};
	#pragma GCC diagnostic pop

	config_el config[] =
	{
		{ "MQTT_HOST", cT ( ptrStr ),  &mosq_init.host, "MQTT broker ip addr" },
		{ "MQTT_PORT", cT ( uint16_t ), &mosq_init.port, "MQTT broker port" },
		{ "MQTT_CA", cT ( ptrStr ),  &mosq_init.ca, "MQTT broker SSL CA file" },
		{ "MQTT_CERT", cT ( ptrStr ),  &mosq_init.cert, "MQTT broker SSL CERT file" },
		{ "MQTT_KEY", cT ( ptrStr ),  &mosq_init.key, "MQTT broker SSL KEY file" },
		{ "MQTT_LAST_TOPIC", cT ( ptrStr ),  &mosq_init.lastName, "MQTT topic used to post last msg on deconnection" },
		{ "MQTT_LAST_MSG", cT ( ptrStr ),  &mosq_init.lastMsg, "MQTT msg sent on deconnection" },
		{ NULL }
	};
 
	param_el param[] =
	{
		{ "--help", "-h", 0x01, cT ( bool ), &flags, "help" },
		{ "--quiet", "-q", 0x02, cT ( bool ), &flags, "quiet" },
		{ "--verbose", "-v", 0x04, cT ( bool ), &flags, "verbose" },
		#ifndef RELEASE_MODE
			{ "--color", "-c", 0x08, cT ( bool ), &flags, "color" },
			{ "--debug", "-d", 0x10, cT ( bool ), &flags, "debug" },
		#endif
		{ "--term", "-lT", 0x20, cT ( bool ), &flags, "log on term" },
		{ "--file", "-lF", 0x40, cT ( bool ), &flags, "log in file" },

		{ "--logFileName", "-lFN", 1, cT ( str ), logFileName, "log file name" },
		{ "--mqqtt_host", "-mH", 1, cT ( ptrStr ),  &mosq_init.host, "MQTT broker ip addr" },
		{ "--mqtt_port", "-mP", 1, cT ( uint16_t ), &mosq_init.port, "MQTT broker port" },
		{ "--mqtt_ca", "-mA", 1, cT ( ptrStr ),  &mosq_init.ca, "MQTT broker SSL CA file" },
		{ "--mqtt_CERT", "-mC", 1, cT ( ptrStr ),  &mosq_init.cert, "MQTT broker SSL CERT file" },
		{ "--mqtt_KEY", "-mK", 1, cT ( ptrStr ),  &mosq_init.key, "MQTT broker SSL KEY file" },
		{ "--mqtt_topic", "-mT", 1, cT ( ptrStr ),  &mosq_init.lastName, "MQTT topic used to post last msg on deconnection" },
		{ "--mqtt_msg", "-mM", 1, cT ( ptrStr ),  &mosq_init.lastMsg, "MQTT msg sent on deconnection" },
		{ NULL }
	};

	// INIT_CONFIG
	if ( readConfigFile ( "config", config ) )
	{ // failure case
	}
	
	if ( readConfigArgs ( argc, argv, config ) )
	{ // failure case
	}
	
	if ( readParamArgs ( argc, argv, param ) )
	{ // failure case
	}
	
	if ( flags.help )
	{// configFile read successfully
		printf ( "%s is a program to control and configure rclaw\n", argv[ 0 ] );
		printf ( "Author: ox223252\n" );
		printf ( "License: GPLv2\n" );
		helpParamArgs ( param );
		helpConfigArgs ( config );
		return ( 0 );
	}

 	// INIT_LOG
	logSetVerbose ( flags.verbose );
	#ifndef RELEASE_MODE
		logSetDebug ( flags.debug );
		logSetColor ( flags.color );
	#endif
	logSetQuiet ( flags.quiet );
	logSetOutput ( flags.term | !flags.file, flags.file );
	logSetFileName ( logFileName );

	robotDescriptor robot;
	robot.rclawFd = initLib ( rclawPath );
	if ( robot.rclawFd )
	{
		return ( __LINE__ );
	}

	if ( err = bigBoyMQTT_init ( mosq_init, &mosq, onMsg, &robot ), err )
	{
		perror ( "Mosquitto init" );
		rt = __LINE__;
		goto rcError;
	}

	robot.mosq = mosq;

	mosquitto_subscribe( mosq, NULL, "/RClaw/O2R/#", 0 );

	while ( getchar() != '\n' )
	{
		printf ( "press enter to quit this soft\n" );
	}

	bigBoyMQTT_stop ( &mosq );
rcError:
	close ( robot.rclawFd );
	return ( rt );
}
