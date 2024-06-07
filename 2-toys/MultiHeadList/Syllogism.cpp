#include <iostream>
#include <string>
#include "MultiHeadList.h"

using namespace std;

class Syllogism {
private :
	MultiHeadList<pair<string,string>>syl;

public :
	void put(const pair<string, string>& argument) {
		for (int i = 0; i < syl.headSize(); ++i) {
			auto it = syl.begin(i);
			while (it != syl.end() && it.curr->data.second != argument.first) ++it;
			if (it != syl.end()) {
				syl.push_back(argument, i);
				return;
			}
		}
		syl.push_back(argument);
	}
	void qna(const string& q) {
		for (int i = 0; i < syl.headSize(); ++i) {
			auto it = syl.begin(i);
			while (it != syl.end() && it.curr->data.first != q) ++it;
			if (it != syl.end()) {
				std::string result = it.curr->data.second;
				++it;
				while (it != syl.end()) {
					result = it.curr->data.second;
					++it;
				}
				std::cout << "If " << q << ", then " << result << std::endl;
				return;
			}
		}
	}

	void print() {
		cout << "=============" << endl;
		for (int i = 0; i != syl.headSize(); i++) {
			cout << i << " : ";
			for (auto it = syl.begin(i); it != syl.end(); it++) {
				if (it == syl.begin(i)) {
					cout << (*it).first << "->" << (*it).second;
				}
				else {
					cout << "->" << (*it).second;
				}
			}
			cout << endl;
		}
	}
};