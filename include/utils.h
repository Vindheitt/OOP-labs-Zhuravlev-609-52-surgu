#ifndef UTILS_H
#define UTILS_H

#define STR_LEN 256
#define DES_LEN 512

#define swap(t, x, y) do{t temp = x; x = y; y = temp;} while(0)

// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>

void clearScreen(void);

int enterInt(int *n);

int enterString(char* str, int len);

#endif
