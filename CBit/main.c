#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "superlogger.h"

const char message[] = "Hejsan nu sdjklalsdjakl";

typedef struct
{
	char a;
	char b;
	char c;
	char d;
	int e;
}TEST1;

typedef struct
{
	char a;
	int e;
	char b;
	char c;
	char d;
}TEST2;



void main3121231()
{
	char* ch = "Hello";

	printf("%d %d", sizeof(TEST1), sizeof(TEST2));
	int a;
	WriteLogMessage("Nu startar programmet",
		false, true, true,
		false,
		true,
		false);

}