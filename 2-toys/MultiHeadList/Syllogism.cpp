#include <iostream>
#include <string>
#include "MultiHeadList.h"

using namespace std;

class Syllogism {
private :
	MultiHeadList<pair<string,string>>syl;

public :
	void put(const pair<string, string>& argument) {
		int firstHeadIdx = -1, secondHeadIdx = -1;
		bool firstFound = false, secondFound = false;

		for (int i = 0; i < syl.headSize(); ++i) {
			auto it = syl.begin(i);
			for (auto it = syl.begin(i); it != syl.end(); it++) {
				if (it.curr->data.second == argument.first) {
					firstHeadIdx = i;
					firstFound = true;
				}
				if (it.curr->data.first == argument.second) {
					secondHeadIdx = i;
					secondFound = true;
				}
				if (firstFound && secondFound)
					break;
			}
			if (firstFound && secondFound)
				break;
		}
		
		if (firstFound && secondFound) {
			syl.push_back(argument, firstHeadIdx);
			syl.merge(firstHeadIdx, secondHeadIdx);
		}
		else if (firstFound)
			syl.push_back(argument, firstHeadIdx);
		else if (secondFound)
			syl.insert(syl.begin(secondHeadIdx), argument);
		else
			syl.push_back(argument);
	}

	void qna(const string& q) {
		for (int i = 0; i < syl.headSize(); ++i) {
			auto it = syl.begin(i);
			while (it != syl.end() && it.curr->data.first != q) 
				++it;
			
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
			for (auto it = syl.begin(i); it != syl.end(); ++it) {
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