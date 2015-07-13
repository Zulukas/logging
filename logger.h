#ifndef LOGGER
#define LOGGER

#include "loggertime.h"

#include <string>
#include <fstream>

using namespace std;

class Logger {
private:
	LoggerTime lt;
	char *file;

public:
	Logger(char *filename);
	Logger(char *filename, bool append);
	Logger(LoggerTime &lt, char *filename);
	Logger(LoggerTime &lt, char *filename, bool append);

	void setLoggerTime(LoggerTime &lt) { this->lt = lt; }

	virtual void write(std::string message, bool timestamp = 1);
};

#endif