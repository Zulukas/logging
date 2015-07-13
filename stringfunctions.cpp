#include "stringfunctions.h"
#include <string>

/* End String Function Global Constants */
///////////////////////////////////////////////////////////////////////////////
/* Start string-returning functions */

std::string getDayName(int day, bool shortDay) {
	shortDay = !shortDay; //too lazy to correct the entire switch statement :)

	switch (day) {
		case 0:
			if (shortDay)
				return "Sunday";
			else
				return "Sun";
		case 1:
			if (shortDay) 
				return "Monday";
			else
				return "Mon";
		case 2:
			if (shortDay) 
				return "Tuesday";
			else
				return "Tue";
		case 3:
			if (shortDay) 
				return "Wednesday";
			else
				return "Wed";
		case 4:
			if (shortDay) 
				return "Thursday";
			else
				return "Thur";
		case 5:
			if (shortDay) 
				return "Friday";
			else
				return "Fri";
		case 6:
			if (shortDay) 
				return "Saturday";
			else
				return "Sat";
		default:
			return "ERROR";
	}
}

std::string getMonthName(int month, bool shortMonth) {
	switch (month) {
		case 1:
			if (shortMonth)
				return "Jan";
			else
				return "January";
		case 2:
			if (shortMonth)
				return "Feb";
			else
				return "February";
		case 3:
			if (shortMonth)
				return "Mar";
			else
				return "March";
		case 4:
			if (shortMonth)
				return "Apr";
			else
				return "April";
		case 5:
			return "May";
		case 6:
			if (shortMonth)
				return "Jun";
			else
				return "June";
		case 7:
			if (shortMonth)
				return "Jul";
			else
				return "July";
		case 8:
			if (shortMonth)
				return "Aug";
			else
				return "August";
		case 9:
			if (shortMonth)
				return "Sep";
			else
				return "September";
		case 10:
			if (shortMonth)
				return "Oct";
			else
				return "October";
		case 11:
			if (shortMonth)
				return "Nov";
			else
				return "November";
		case 12:
			if (shortMonth)
				return "Dec";
			else
				return "December";
		default:
			return "ERROR";
	}
}

std::string getDateString(int year, int month, int day, int wday,
						  bool showDay, bool shortDay, bool showMonth, bool shortMonth,
						  bool littleEndian) {
	std::string out;
	std::string DAY = std::to_string(day);
	std::string MONTH;
	std::string YEAR = std::to_string(year);

	if (showDay && wday >= 0 && wday < 7) {
		out += getDayName(wday, shortDay) + " ";
	}

	if (showMonth) {
		MONTH = getMonthName(month, shortMonth);
	}
	else {
		MONTH = std::to_string(month);
	}

	if (littleEndian) {
		out += DAY + "-" + MONTH + "-" + YEAR;
	}
	else {
		out += MONTH + "-" + DAY + "-" + YEAR;
	}

	return out;
}

std::string getTimeString(int hour, int minute, int second, bool military) {
	std::string out = "";

	std::string HOUR;
	std::string MINUTE = (minute < 10) ?
						 ("0" + std::to_string(minute)) : (std::to_string(minute));
	std::string SECONDS = (second < 10) ? 
						  ("0" + std::to_string(second)) : (std::to_string(second));

	if (military) {
		HOUR = std::to_string(hour);

		return HOUR + ":" + MINUTE + ":" + SECONDS;
	}

	bool PM = (hour >= 12);
	HOUR = std::to_string((PM) ? (hour - 12) : (hour));

	return HOUR + ":" + MINUTE + ":" + SECONDS + (PM ? " pm" : " am");
}