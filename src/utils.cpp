#include <utils.h>
#include <cstdlib>
#include <iostream>

#define macros_swap(type, x, y) do{type t; t = x; x = y; y = t;}while(0)

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
