#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "lib/mosquittoInterface/mosquittoInterface.h"

void onMsg ( char* topic, char* msg, void * arg )
{
	char *token = strtok( topic, "/");
    
	printf ( "%s : %s\n", topic, msg );

	if ( strcmp( token, "Dyna" ) == 0 )
	{ // dynamixels
		
		int value = 0;
		token = strtok(NULL, "/");
		if ( strcmp( token, "getIDs" ) == 0 )
		{

		}
		else if ( value = atoi( token ), value || 
			( token[ 0 ] == 0 ) )
		{
			bool set = false;

			if ( strcmp( token, "Appairage" ) == 0 )
			{
				// TODO
				return;
			}
			else if ( strcmp( token, "changeID" ) == 0 )
			{
				// TODO
				return;
			}
			else if ( strcmp( token, "set" ) == 0 )
			{
				set = true;
			}
			else if ( strcmp( token, "get" ) == 0 )
			{
				set = false;
			}
			else
			{
				printf ( "MOSQUITTO unknow cmd : %s %s \n", token, msg );
				return;
			}
			
			token = strtok(NULL, "/");
			if ( strcmp( token, "Value" ) == 0 )
			{

			}
			else if ( strcmp( token, "Speed" ) == 0 )
			{
				
			}
			else
			{
				printf ( "MOSQUITTO unknow cmd : %s %s \n", token, msg );
				return;
			}
		}
		else
		{
			printf ( "unknow cmd : %s %s", topic, msg );
			return;
		}
	}
	else if ( strcmp( token, "RClaw" ) == 0 )
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

				}
				else if ( strcmp ( token, "value" ) == 0 )
				{

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

int main ( void )
{
	int err = 0;
	struct mosquitto * mosq;
	MQTT_init_t mosq_init = {
		.name = "robot",
		.host = "127.0.0.1",
		.port = 1883,
		.ca = NULL,
		.cert = NULL,
		.key = NULL,
		.lastName = "status",
		.lastMsg = "disconnected"
	};
	
	if ( err= bigBoyMQTT_init ( mosq_init, &mosq, onMsg, NULL ), err )
	{
		perror ( "Mosquitto init" );
		return ( __LINE__ );
	}

	mosquitto_subscribe( mosq, NULL, "/Dyna/#", 0 );
	mosquitto_subscribe( mosq, NULL, "/RClaw/O2R/#", 0 );

	char data[] = "6";
	mosquitto_publish( mosq, NULL, "/RClaw/R2O/set/Codeur/left", sizeof ( data ), data, 0, false );

	while ( getchar() != '\n' )
	{
	}

	bigBoyMQTT_stop ( &mosq );
	return ( 0 );
}
