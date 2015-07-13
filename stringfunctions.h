#ifndef STRINGFUNCTIONS
#define STRINGFUNCTIONS

#include <string>
#include <ctime>
#include <time.h>

#include "loggertime.h"

/* Forward Declarations */
class LoggerTime;

/*
* Notes:
*
* Functions with default values given must be given within the declaration, 
* not within the definition
*
* Always include .h files, not .cpp's.  Using .cpps will result in errors 
* about multiple definitions
*
* Anytime you're referencing a class or function which involves some kind of 
* circular inclusion, you must forward declare.
*/

/** API Documentation **/
// VARIABLES:
// 		numStringFormats = number of recognized legal formats; used for iteration purposes mostly
// 		legalFormats = recognized legal date formats
//
// FUNCTIONS:
//		getDayStr(int day, bool shortDay) = Return the string name of the day, shortDay will cause
//											it to return for days (Tue instead of Tuesday)
//		getMonthStr(int month, bool shortMonth) = Works similarly to getDayStr, returns month strings
//		checkDateFormat(string format) = Checks to see if a string is in a legal date format
//		checkLittleEndianFormat(string format) = Checks to see if the format string is little endian notation
//		checkMiddleEndianFormat(string format) = Checks to see if the format string is middle endian notatiton
//		checkBigEndianFormat(string format) = Checks to see if the format string is big endian notation

std::string getDayName(int day, bool shortDay = 0);
std::string getMonthName(int month, bool shortMonth = 0);
std::string getDateString(int year, int month, int day, int wday = 7, bool showDay = 0, 
						  bool shortDay = 1, bool showMonth = 0, bool shortMonth = 1, 
						  bool littleEndian = 1);
std::string getTimeString(int hour, int minute, int second, bool military = 1);

bool checkDateFormat(std::string format);

#endif