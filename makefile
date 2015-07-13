RM=rm -rf

PROG_NAME = a.out

it: stringfunctions.o logger.o loggertime.o tester.o
	g++ -std=c++11 -o TEST stringfunctions.o loggertime.o tester.o logger.o

#it: stringfunctions.o loggertime.o driver.o
#	g++ -std=c++11 -o app stringfunctions.o loggertime.o driver.o

driver.o: driver.cpp logger.h loggertime.h stringfunctions.h

tester.o: tester.cpp logger.h loggertime.h stringfunctions.h
	g++ -c -g -std=c++11 tester.cpp

loggertime.o: loggertime.h loggertime.cpp stringfunctions.h
	g++ -c -g loggertime.cpp

logger.o: logger.h logger.cpp loggertime.h
	g++ -c -g -std=c++11 logger.cpp

stringfunctions.o: stringfunctions.h loggertime.h stringfunctions.cpp
	g++ -c -g -std=c++11 stringfunctions.cpp

clean: 
	@echo --Rebuild completely from source--
	$(RM) *.o *~ ./TEST
	make a.out