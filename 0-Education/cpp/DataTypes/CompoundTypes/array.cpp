#include <iostream>

using namespace std;

int main()
{
    int yams[3];    // creates array with three elements
    yams[0] = 7;    // index starts at 0
    yams[1] = 8;
    yams[2] = 6;

    int yamcosts[3] = { 20, 30, 5 };    // create, initialize array

    cout << "Total yams = " << yams[0] + yams[1] + yams[2] << endl;
    cout << "The package with " << yams[1] << " yams costs " << yamcosts[1] << " cents per yam.\n";
    int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1];
    total = total + yams[2] * yamcosts[2];
    cout << "The total yam expense is " << total << " cents.\n";
    // Inteded wrong codes - Runtime Error: Out of index(size of array).
    // yams[3] = 5;
    // cout << yams[3] << endl;
    cout << "\nSize of yams array = " << sizeof yams;
    cout << " bytes.\n";
    cout << "Size of one element = " << sizeof yams[0];
    cout << " bytes.\n" << endl;

    // Initialization Rules for Arrays
    // 1) Can use initialization form only when defining the array
    int cards[4] = { 3, 6, 9, 12 };     // okay
    int hand[4];                        // okay
    // hand[4] = { 5, 6, 7, 8 };        // not allowed
    // 2) Can not assign one array wholesale to another
    // hand = cards;                    // not allowed
    // 3) Can initializes fewer values than array elements - remainder are zero
    float hotelTips[5] = { 5.0, 2.5 };
    cout << "Hotel Tips: " << hotelTips[0] << ", " << hotelTips[1] << ", ";
    cout << hotelTips[2] << ", " << hotelTips[3] << ", " << hotelTips[4] << endl;
    int zeros[2] = { 0 };
    cout << "Zeros: " << zeros[0] << ", " << zeros[1] << endl;
    // 4) Can drop '=' sign when initializing an array
    int one[3] { 1 };
    cout << "One: " << one[0] << ", " << one[1] << ", " << one[2] << endl;
    // 5) Can leave the square brackets([]) empty - compiler counts the lements
    short things[] = { 1, 5, 3, 8 };
    cout << "Size of things: " << sizeof things / sizeof(things[0]) << endl;

    return 0;
}

