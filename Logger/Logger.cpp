#include "Logger.h"
#include "arduino.h"
#include <Console.h>

/*	Public Functions			||
||								||
||	Contents: 					||
||		-	Constructor			||
||		- 	Destructor			||
||								*/

// Constructor: 
Logger::Logger(String EnableThis){
	EnableThis.toLowerCase(); // lowercasing is a good practice!
	if(EnableThis.indexOf("console") > -1){
		// enable Console
		ConsoleEnabled = true;
	}
	if(EnableThis.indexOf("serial") > -1){
		// enable Serial
		SerialEnabled = true;
	}
}

boolean ConsoleEnabled = false;
boolean SerialEnabled = false;

// Destructor:
Logger::~Logger(){
}

/*	Declaring LogLevels			*/
const String logLevel_debug = "debug";
const String logLevel_warn = "warn";
const String logLevel_fatal = "fatal";
const String logLevel_error = "error";
const String logLevel_info = "log";

/*	Declaring functions			*/
void Logger::Log(String prefix, String text){
	if(text == ""){
		// prefix as text, no prefix
		_SAY_T(logLevel_log, prefix);
	}
	else{
		// function as normal
		_SAY_PT(logLevel_log, prefix, text);
	}
};
void Logger::Info(String prefix, String text){
	if(text == ""){
		// prefix as text, no prefix
		_SAY_T(logLevel_info, prefix);
	}
	else{
		// function as normal
		_SAY_PT(logLevel_log, prefix, text);
	}
};
void Logger::Warn(String prefix, String text){
	if(text == ""){
		// prefix as text, no prefix
		_SAY_T(logLevel_warn, prefix);
	}
	else{
		// function as normal
		_SAY_PT(logLevel_warn, prefix, text);
	}
};
void Logger::Error(String prefix, String text){
	if(text == ""){
		// prefix as text, no prefix
		_SAY_T(logLevel_error, prefix);
	}
	else{
		// function as normal
		_SAY_PT(logLevel_error, prefix, text);
	}
};
void Logger::Fatal(String prefix, String text){
	if(text == ""){
		// prefix as text, no prefix
		_SAY_T(logLevel_fatal, prefix);
	}
	else{
		// function as normal
		_SAY_PT(logLevel_fatal, prefix, text);
	}
};
void Logger::Debug(String prefix, String text){
	if(_debug){
		if(text == ""){
			// prefix as text, no prefix
			_SAY_T(logLevel_debug, prefix);
		}
		else{
			// function as normal
			_SAY_PT(logLevel_debug, prefix, text);
		}
	}
};

boolean _debug = false;

void Logger::setDebug(boolean dbg){
	_debug = dbg;
}

boolean getDebug(){
	return _debug;
}

/*	Private Functions			||
||								||
||	Contents:					||
||		-	_SAY_T				||
||		-	_SAY_PT				||
||								*/

void Logger::_SAY_T(String LogLevel, String text){
	if(this->ConsoleEnabled){
		Console.println("[" + LogLevel + "]: " + (String)text);
	}
	if(this->SerialEnabled){
		Serial.println("[" + LogLevel + "]: " + (String)text);
	}
}

void Logger::_SAY_PT(String LogLevel, String prefix, String text){
	if(this->ConsoleEnabled){
		Console.println("[" + (String)LogLevel + "] [" + (String)prefix + "]: " + (String)text);
	}
	if(this->SerialEnabled){
		Serial.println("[" + (String)LogLevel + "] [" + (String)prefix + "]: " + (String)text);
	}
}