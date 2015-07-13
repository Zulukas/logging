#include "logger.h"
#include "loggertime.h"
#include "stringfunctions.h"
#include "color.h"

#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>

using namespace std;

int main() {
	/*LoggerTime lt2;

	lt2.setMilitary(false);
	lt2.setUTC(false);
	lt2.setDisplayDayName(true);
	lt2.setUseMonthName(true);
	lt2.setLittleEndian(true);
	lt2.setShortDayName(true);
	lt2.setShortMonthName(true);

//	lt2.displayStatics();

	
	for (int i = 0; i < 10; i++) {
		cout << lt2 << endl;
		system("sleep 1");
	}

	char file[256] = "testfile.txt";

	Logger logger(file, true);

	for (int i = 0; i < 10; i++) {
		string msg = std::to_string(i) + + "\n";
		logger.write(msg);
	}*/

	LoggerTime lt;
	lt.setMilitary(false);
	lt.setUTC(false);
	lt.setDisplayDayName(true);
	lt.setUseMonthName(true);
	lt.setLittleEndian(true);
	lt.setShortDayName(true);
	lt.setShortMonthName(true);
	lt.setColor(Color::GREEN);

	char* txt = "testfile.txt";

	Logger logger(lt, txt);
	
	Color::Modifier red(Color::RED);
	Color::Modifier b_red(Color::F_RED);
	Color::Modifier def(Color::DEFAULT);
	Color::Modifier b_def(Color::F_DEFAULT);

	cout << "this ->" << b_red << txt << b_def << "<- is red" << endl;

	logger.write("This is a nice message");	

	return 0;
}
