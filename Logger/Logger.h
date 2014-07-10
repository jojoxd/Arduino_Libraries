#ifndef Logger_h
#define Logger_h

#include "Arduino.h"

class Logger{
    public:
        Logger();
        ~Logger();
        void Log(String prefix, String text);
		void Info(String prefix, String text);
		void Error(String prefix, String text);
		void Debug(String prefix, String text);
		void setDebug(boolean debug);
		void setLogging(boolean logging);
		boolean getLogging();
		boolean getDebug();
		int multiPrint(char *str, ...);
	private:
		boolean _debug;
		boolean _logging;
};

#endif
