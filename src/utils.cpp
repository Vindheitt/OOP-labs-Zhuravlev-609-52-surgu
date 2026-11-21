#include <utils.h>
#include <cstdlib>
#include <iostream>

using std::cin;

void clearScreen(void){
	#ifdef _WIN32
 		system("cls");
	#else
		system("clear");
	#endif
}
int enterInt(int& n) {
	if (!(cin >> n)) {
    	cin.clear();
        cin.ignore(10000, '\n');
        return 1;
	}
	return 0;
}
