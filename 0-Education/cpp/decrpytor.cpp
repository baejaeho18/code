#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {

	string cyphertext;
	string hexa_digits;
	string decrypt_result;
	int cyphertext_cnt;
	int hexa_digit_cnt = 0;
	double noise_char_cnt = 0;

	cout << "Enter a cyphertext" << endl;
	while (1) {
		string input;
		getline(cin, input);	// 공백 포함
		cyphertext += input;
		if (input.size() >= 2 && input[input.size() - 2] == '.' && input[input.size() - 1] == '.')
			break;
		cyphertext += "\n";
	}
	cyphertext_cnt = cyphertext.length();
	for (int i = 0; i < cyphertext.length(); i++) {
		// count noise characters
		if (cyphertext[i] == '#' || cyphertext[i] == '$' || cyphertext[i] == '%' ||
			cyphertext[i] == '&' || cyphertext[i] == '*')
			noise_char_cnt++;
		// extract hexadecimal digits
		if (cyphertext[i] == '1' || cyphertext[i] == '2' || cyphertext[i] == '3' ||
			cyphertext[i] == '4' || cyphertext[i] == '5' || cyphertext[i] == '6' ||
			cyphertext[i] == '7' || cyphertext[i] == '8' || cyphertext[i] == '9' ||
			cyphertext[i] == 'A' || cyphertext[i] == 'B' || cyphertext[i] == 'C' ||
			cyphertext[i] == 'D' || cyphertext[i] == 'E' || cyphertext[i] == 'F' ||
			cyphertext[i] == '0') {
			hexa_digits += cyphertext[i];
			hexa_digit_cnt++;
		}
	}

	// display noise char rate
	cout.precision(5);
	cout << "Ciphertext noise rate: " << noise_char_cnt / cyphertext_cnt * 100 << "%\n";

	// diplay hexadecima digits
	cout << "Hexadecimal digits: " << hexa_digits << endl;

	// Exception
	if (hexa_digit_cnt == 0) {	// 없을 경우
		cout << "Undecryptable: where are the hexadecimal digits!" << endl;
	}
	else if (hexa_digit_cnt % 2 == 1) {	// 홀수일 경우
		cout << "Undecryptable: the number of hexadecimal digits is odd!" << endl;
	}
	else {
		string ascii_str;
		for (int i = 0; i < hexa_digit_cnt; i += 2) {
			//ascii_str = hexa_digits[i] + (char)hexa_digits[i + 1];
			ascii_str = hexa_digits[i];
			ascii_str += hexa_digits[i + 1];
			int ascii = stoul(ascii_str, nullptr, 16);
			if (0 <= ascii && ascii < 127) {
				decrypt_result += (char)ascii;
			}
			else {
				cout << "Undecryptable: invalid hexadecimal digits pair!" << endl;
				cout << "Decryptor turn off!" << endl;
				return 0;
			}
		}
		cout << "Decryption result: " << decrypt_result << endl;
	}
	cout << "Decryptor turn off!" << endl;

	return 0;
}