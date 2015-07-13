#ifndef LOGGERTIME
#define LOGGERTIME

#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>

#include "stringfunctions.h"
#include "color.h"

struct TimeData;

class LoggerTime {
private: 
	//time related statics
	static bool military; //00:00:00 - 23:59:59
	static bool UTC;

	//date related statics
	static bool littleEndian;
	static bool useMonthName;
	static bool shortMonthName;
	static bool displayDayName;
	static bool shortDayName;

	Color::Code color;

public:
	inline void displayStatics() {
		std::string result[2] = {"no\n", "yes\n"};

		std::cout << "Statics Report:\n" 
			 << "Military time: " << result[(this->military)]
			 << "UTC time: " << result[(this->UTC)]
			 << "Little Endian: " << result[(this->littleEndian)]
			 << "Use Month Name: " << result[(this->useMonthName)]
			 << "Short Month Name: " << result[(this->shortMonthName)]
			 << "Display Day Name: " << result[(this->displayDayName)]
			 << "Short Day Name: " << result[(this->shortDayName)];
	}

	inline Color::Code getColor() const { return color; }
	inline void setColor(Color::Code color) { this->color = color; }

	//Military Time
	inline bool getMilitary() const { return military; }
	inline void setMilitary(bool input) { this->military = input; }

	//UTC time
	inline bool getUTC() const { return UTC; }
	inline void setUTC(bool input) { this->UTC = input; }

	inline bool getLittleEndian() const { return littleEndian; }
	inline void setLittleEndian(bool input) { this->littleEndian = input; }

	inline bool getUseMonthName() const { return useMonthName; }
	inline void setUseMonthName(bool input) { this->useMonthName = input; }

	inline bool getShortMonthName() const { return shortMonthName; }
	inline void setShortMonthName(bool input) { this->shortMonthName = input; }

	inline bool getDisplayDayName() const { return displayDayName; }
	inline void setDisplayDayName(bool input) { this->displayDayName = input; }

	inline bool getShortDayName() const { return shortDayName; }
	inline void setShortDayName(bool input) { this->shortDayName = input; }

	inline struct tm * getLocalTime() {
		time_t t;

		return localtime(&t);
	}

	inline struct tm * getGMTime() {
		time_t t;

		return gmtime(&t);
	}

	friend std::ostream & operator << (std::ostream & out, const LoggerTime &time);
};

#endif