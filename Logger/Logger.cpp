#include "Logger.h"
#include <stdarg.h>

// Constructor: 
Logger::Logger(){
	if(!Serial){
		Serial.begin(9600);
		while(!Serial){};
	}
	else{
		// serial is already on!
	}
}

// Destructor:
Logger::~Logger(){
	Serial.end();
}

// Variables:
boolean _logging = true;
boolean _debug = false;
int ARDBUFFER = 16;

// functions:
void Logger::Log(String prefix, String text){
  if(text == ""){
    // use prefix as text
  }
  else{
    // a prefix and text is given
  }
}

void Logger::Info(String prefix, String text){
}

void Logger::Error(String prefix, String text){
}

void Logger::Debug(String prefix, String text){
}

void Logger::setDebug(boolean debug){
	_debug = debug;
}

void Logger::setLogging(boolean logging){
	_logging = logging;
}

boolean getLogging(){
	return _logging;
}

boolean getDebug(){
	return _debug;
}
