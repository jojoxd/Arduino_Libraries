#ifndef Logger_h
#define Logger_h

#include "arduino.h"

class Logger{
	public:
		// Constructor & Destructor:
		Logger(String EnableThis);
		~Logger();
		
		// all public functions:
		void Log(String prefix, String text);
		void Info(String prefix, String text);
		void Warn(String prefix, String text);
		void Error(String prefix, String text);
		void Fatal(String prefix, String text);
		void Debug(String prefix, String text);
		void setDebug(boolean dbg);
		boolean getDebug();
		
		// all public variables:
		String logLevel_debug = "debug";
		String logLevel_warn = "warn";
		String logLevel_fatal = "fatal";
		String logLevel_error = "error";
		String logLevel_log = "log";
		
	private:
		// private functions & variables
		void _SAY_T(String LogLevel, String text);
		void _SAY_PT(String LogLevel, String prefix, String text);
		boolean _debug = false;
		boolean SerialEnabled = false;
		boolean ConsoleEnabled = false;
};

#endif