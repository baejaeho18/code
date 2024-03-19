#include "bit_displayer.h"

int main()
{
	unsigned char a = 13;
	unsigned char b = 22;

	unsigned char sl_a = a << 3;  // 
	unsigned char sr_a = a >> 3;  // 
	unsigned char neg_a = ~a;     // 242 (255-13)
	unsigned char a_and_b = a & b;  // 4
	unsigned char a_or_b = a | b;   // 31
	unsigned char a_xor_B = a ^ b;  // 27

	cout << "a = " << (int)a << "\t: " << bitLayout(a) << endl;
	cout << "b = " << (int)b << "\t: " << bitLayout(b) << endl;
	cout << "sl_a = " << (int)sl_a << "\t: " << bitLayout(sl_a) << endl;
	cout << "sr_a = " << (int)sr_a << "\t: " << bitLayout(sr_a) << endl;
	cout << "neg_a = " << (int)neg_a << "\t: " << bitLayout(neg_a) << endl;
	cout << "a_and_b = " << (int)a_and_b << "\t: " << bitLayout(a_and_b) << endl;
	cout << "a_or_b = " << (int)a_or_b << "\t: " << bitLayout(a_or_b) << endl;
	cout << "a_xor_B = " << (int)a_xor_B << "\t: " << bitLayout(a_xor_B) << endl;

	return 0;
}

/*
* a = 13  : 00001101 (1 bytes)
* b = 22  : 00010110 (1 bytes)
* sl_a = 104      : 01101000 (1 bytes)
* sr_a = 1        : 00000001 (1 bytes)
* neg_a = 242     : 11110010 (1 bytes)
* a_and_b = 4     : 00000100 (1 bytes)
* a_or_b = 31     : 00011111 (1 bytes)
* a_xor_B = 27    : 00011011 (1 bytes)
*/