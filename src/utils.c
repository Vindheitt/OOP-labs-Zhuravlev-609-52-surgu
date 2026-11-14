#include <utils.h>
#include <stdio.h>
#include <stdlib.h>

void clearScreen(void){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int enterInt(int *n) {
	char buf;

	if (n == NULL)
		return -1;

	if (scanf("%d%c", n, &buf) != 2) {
		printf("Something went wrong with enter int..\n");
		printf("Please try again: ");
		while (getchar() != '\n');
		return 1;
	}
	if (buf != '\n')
		while (getchar() != '\n');
	return 0;
}

int enterString(char* str, int len){
    if (!str || len < 1)
        return -1;

    int i = 0;
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {
        if (i < len - 1)
            str[i++] = (char)c;
    }

    str[i] = '\0';
    return i;
}
