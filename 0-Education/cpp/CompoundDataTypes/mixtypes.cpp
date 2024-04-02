#include <iostream>

using namespace std;

struct antractica_years_end
{
	int year;
};

int main()
{
	antractica_years_end s01, s02, s03;
	
	s01.year = 1998;
	cout << s01.year << endl;
	
	antractica_years_end* pa = &s02;
	pa->year = 1999;
	cout << s02.year << endl;

	antractica_years_end trio[3];	// array of 3 structure
	trio[0].year = 2003;
	cout << trio->year << endl;

	const antractica_years_end* arp[3] = { &s01, &s02, &s03 };
	cout << arp[1]->year << endl;

	const antractica_years_end** ppa = arp;
	cout << (*ppa)->year << endl;

	auto ppb = arp;		// or else use const antractica_years_end ** ppb = arp;
	cout << (*(ppb + 1))->year << endl;

	return 0;
}

/*
* 1998
* 1999
* 2003
* 1999
* 1998
* 1999
*/