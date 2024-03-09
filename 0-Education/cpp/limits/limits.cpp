#include <iostream>
#include <climits>

using namespace std;

int main()
{
	int n_int = INT_MAX;		// initialilze n_int to max int value
	short n_short = SHRT_MAX;	// symbols defined in climits file
	long n_long = LONG_MAX;
	long long n_llong = LLONG_MAX;

	// sizeof operator yields size of type or of variable
	// sizeof(type_or_variable_name)
	cout << "int is " << sizeof(int) << " bytes." << endl;
	//cout << "short is " << sizeof short << " bytes." << endl;	// Error : 'sizeof type_name' is not valid
	cout << "short is " << sizeof n_short << " bytes." << endl;
	cout << "long is " << sizeof(n_long) << " bytes." << endl;
	cout << "long long is " << sizeof n_llong << " bytes." << endl << endl;

	cout << "Maximun values:" << endl;
	cout << "int: " << n_int << endl;
	cout << "short: " << n_short << endl;
	cout << "long: " << n_long << endl;
	cout << "long long: " << n_llong << endl << endl;

	cout << "Minimun int values = " << INT_MIN << endl;
	//cout << "Minimun short values = " << n_short + 1 << endl;		// underflow does not occur. Maybe type conversion to INT?
	cout << "Minimun short values = " << short(n_short + 1) << endl;
	cout << "Minimun long values = " << n_long + 1 << endl;
	cout << "Minimun long long values = " << n_llong + 1 << endl;
	cout << "Bits per byte = " << CHAR_BIT << endl;


	return 0;
}