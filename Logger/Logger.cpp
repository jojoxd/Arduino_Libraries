#include "Logger.h"
#include <stdio.h>

// Constructor: 
Logger::Logger(){
	// testfor serial
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

// functions:
void Logger::Log(String prefix, String text){
	if(text == ""){
    	// use prefix as text
		_SayT("Log", prefix);
	}
	else{
    	// a prefix and text is given
		_SayPT("Log", prefix, text);
	}
}

void Logger::Info(String prefix, String text){
	if(text == ""){
    	// use prefix as text
		_SayT("Info", prefix);
	}
	else{
    	// a prefix and text is given
		_SayPT("Info", prefix, text);
	}
}

void Logger::Error(String prefix, String text){
	if(text == ""){
    	// use prefix as text
		_SayT("Error", prefix);
	}
	else{
    	// a prefix and text is given
		_SayPT("Error", prefix, text);
	}
}

void Logger::Debug(String prefix, String text){
	if(getDebug()){
		if(text == ""){
			// use prefix as text
			_SayT("Debug", prefix);
		}
		else{
			// a prefix and text is given
			_SayPT("Debug", prefix, text);
		}
	}
	else{
		// debug disabled, don't write to Serial
	}
}

void Logger::_SayPT(String what, String prefix, String text){
	Serial.println("[" + what + "] [" + prefix + "]: " + text); // it compiles, dunno if it works
	//Serial.print("["); Serial.print(what); Serial.print("] ["); Serial.print(prefix); Serial.print("]: "); Serial.println(text);
}

void Logger::_SayT(String what, String text){
	Serial.println("[" + what + "]: " + text); // it compiles, dunno if it works
	//Serial.print("["); Serial.print(what); Serial.print("]: "); Serial.println(text);
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
