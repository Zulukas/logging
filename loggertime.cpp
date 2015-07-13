#include "loggertime.h"

/* Set the Statics */

bool LoggerTime :: military = 		  	false;
bool LoggerTime :: UTC = 			  	false;

bool LoggerTime :: littleEndian = 		false;
bool LoggerTime :: useMonthName = 		false;
bool LoggerTime :: shortMonthName = 	false;
bool LoggerTime :: displayDayName = 	false;
bool LoggerTime :: shortDayName = 		false;

/* End Statics */
///////////////////////////////////////////////////////////////////////////////
/* Overloaded Operators */

std::ostream & operator << (std::ostream & out, const LoggerTime & _time) {
	time_t tt;
	time(&tt);

	struct tm *t;

	if (_time.getUTC()) {
		t = gmtime(&tt);
	}
	else {
		t = localtime(&tt);
	}

	std::string TIME = getTimeString(t->tm_hour, t->tm_min, t->tm_sec, _time.military);
	std::string DATE = getDateString(t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_wday, 
									 _time.displayDayName, _time.shortDayName, 
									 _time.useMonthName, _time.shortMonthName, 
									 _time.littleEndian);

	Color::Modifier color(_time.getColor());
	Color::Modifier def(Color::DEFAULT);

	out << color << (DATE + " " + TIME) << def;
	return out;
}

/* End Overloaded Operators */
///////////////////////////////////////////////////////////////////////////////
