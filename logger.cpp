#include "logger.h"

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>

Logger :: Logger(char *filename) {
	std::string syscmd = "rm -f " + (std::string)filename;

	system(syscmd.c_str());

	this->file = filename;
}

Logger :: Logger(char *filename, bool append) {
	this->file = filename;
}

Logger :: Logger(LoggerTime &lt, char *filename) {
	std::string syscmd = "rm -f " + (std::string)filename;

	system(syscmd.c_str());

	this->file = filename;
	this->lt = lt;
}

Logger :: Logger(LoggerTime &lt, char *filename, bool append) {
	this->file = filename;
	this->lt = lt;
}

void Logger :: write(string message, bool timestamp) {
	std::ofstream out;
	out.open(this->file, std::ios_base::app);

	if (timestamp)
		out << "[" << lt << "] " << message;
	else
		out << message;

	return;
}