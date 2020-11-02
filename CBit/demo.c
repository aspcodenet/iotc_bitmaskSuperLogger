#include <stdbool.h>
#include <stdio.h>

#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b))))        // '!!' to make sure this returns 0 or 1



void printBitsDemo(size_t const size, void const* const ptr)
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



int main()
{
	//Signed unsigned
	unsigned char val = 255;
	printBitsDemo(sizeof(val),&val); 

	char val2 = 255;
	printBitsDemo(sizeof(val2), &val2); 

	//Sätta en bit utan att sabba andra!!
	//DETTA ÄR EN BYTE SOM STYR REGISTER SOM SÄTTER PINNAR PÅ ARDUINO
	unsigned char v = 0b10010000;
	printBitsDemo(sizeof(v), &v);


	//loop
	//Sätta bit 2 till high- digitalWrite(3,HIGH)
	////Sätta en bit utan att sabba andra!!
	///
	int bitNummerAttSatta = 2;
	//v |= (1 << bitNummerAttSatta);//00000001 << shifta ettan till vänster så många gånger 
	BIT_SET(v, bitNummerAttSatta);
	printBitsDemo(sizeof(v), &v);

	//Sätt två bitar samtidigt
	v |= (1 << 3) | (1 << 5);
	v |= 0b00101000;
	
	printBitsDemo(sizeof(v), &v);


	//clear två bitar samtidigt
	v = 0b11111111;
	v &= ~(1 << 3 | 1 << 5); //00101000   11010111
	v &= ~(0b11010111);
	

	printBitsDemo(sizeof(v), &v);

	
	//
		//Cleara en bit utan att sabba andra!!!
	bitNummerAttSatta = 3;
	v = 0b10011111; //10010111
	//v &= ~(1 << bitNummerAttSatta); //00000001 00001000   111101111
	BIT_CLEAR(v, bitNummerAttSatta);
	printBitsDemo(sizeof(char), &v);

	
	if(BIT_CHECK(v, bitNummerAttSatta))
	{
		
	}
	//v |= (1 << 2);

	return 0;
}