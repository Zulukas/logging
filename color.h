#ifndef COLOR_H
#define COLOR_H

#include <ostream>
namespace Color {
    enum Code {
        RED      	= 31,
        GREEN    	= 32,
        YELLOW 	 	= 33,
        BLUE     	= 34,
        PURPLE   	= 35,
        CYAN     	= 36,
        WHITE    	= 37,
        DEFAULT  	= 39,
        F_RED    	= 41,
        F_GREEN  	= 42,
        F_YELLOW 	= 43,
        F_BLUE     	= 44,
        F_PURPLE   	= 45,
        F_CYAN     	= 46,
        F_WHITE    	= 47,
        F_DEFAULT  	= 49
    };
    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}

/*#include <string.h>

#define BLACK 		"\033[0;30m"
#define RED 		"\033[0;31m"
#define GREEN 		"\033[0;32m"
#define YELLOW 		"\033[0;33m"
#define BLUE		"\033[0;34m"
#define PURPLE 		"\033[0;35m"
#define CYAN 		"\033[0;36m"
#define WHITE 		"\033[0;37m"
#define B_BLACK 	"\033[1;30m"
#define B_RED		"\033[1;31m"
#define B_GREEN		"\033[1;32m"
#define B_YELLOW	"\033[1;33m"
#define B_BLUE		"\033[1;34m"
#define B_PURPLE	"\033[1;35m"
#define B_CYAN		"\033[1;36m"
#define B_WHITE		"\033[1;37m"

#define ENDCOLOR 	"\033[0m"

char* setStringTextColor(char *COLOR, const char *txt) {
	char* msg;
	strcpy(msg, COLOR);
	strcat(msg, txt);
	//strcat(msg, ENDCOLOR);

	return msg;
}
*/
#endif