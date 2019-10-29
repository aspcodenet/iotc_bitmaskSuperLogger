#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void printBits(size_t const size, void const* const ptr)
{
	unsigned char* b = (unsigned char*)ptr;
	unsigned char byte;
	int i, j;

	for (i = size - 1; i >= 0; i--)
	{
		for (j = 7; j >= 0; j--)
		{
			byte = (b[i] >> j) & 1;
			printf("%u", byte);
		}
	}
	printf("\n");
}


#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b))))        // '!!' to make sure this returns 0 or 1

void  main()
{
	char tal = 0;

	while (1)
	{
		printf("1. Ange tal\n");
		printf("2. Sätt en bit\n");
		printf("3. Clear en bit\n");
		int sel;
		scanf("%d", &sel);
		if (sel == 1)
		{
			printf("Ange tal att börja med:");
			int n;
			scanf("%d",&n);
			tal = n;
			printBits(sizeof(tal),&tal);
		}
		else if (sel == 2)
		{
			int bit;
			printf("Ange bit (0-7) att sätta:");
			scanf("%d", &bit);
			BIT_SET(tal, bit);
			printf("Nu är talet %d\n", tal);
			printBits(sizeof(tal), &tal);
		}
		else if (sel == 3)
		{
			int bit;
			printf("Ange bit (0-7) att cleara:");
			scanf("%d", &bit);
			BIT_CLEAR(tal, bit);
			printf("Nu är talet %d\n", tal);
			printBits(sizeof(tal), &tal);
		}
	}
	//char portD;
	//BIT_SET(portD, 3);
	////delay
	//BIT_CLEAR(portD, 3);

	//if (BIT_CHECK(portD, 3))
	//{
	//	BIT_CLEAR(portD, 3);
	//}
	//else
	//	BIT_SET(portD, 3);


	char c2 = 0;
	for (int i = 0; i <= 7; i++)
	{
		BIT_SET(c2, i);
		printBits(sizeof(c2), &c2);
	}

	for (int i = 0; i <= 7; i++)
	{
		BIT_CLEAR(c2, i);
		printBits(sizeof(c2), &c2);
	}


	BIT_SET(c2, 5);
	if (BIT_CHECK(c2, 5))
	{
		printf("Yepp");
	}


	char c = 123;
	printBits(sizeof(c), &c);


	int i = 23;
	float f = 23.45f;
	printBits(sizeof(i), &i);
	printBits(sizeof(f), &f);
}