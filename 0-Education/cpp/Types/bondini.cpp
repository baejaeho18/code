#include <iostream>

using namespace std;

int main()
{
	long code;

	cout << "\aOperation \"HyperHype\" is now activated!\n";	// \n : NewLine(LF)
	cout << "Enter your agent code:________\b\b\b\b\b\b\b\b";	// \b : Backspace(BS), 시스템에 따라 커서가 뒤로 이동하는 동안 지울수도 있다
	cin >> code;
	cout << "\aYou entered " << code << "...\n";				// \a : Alert, 어떤 역할인지 사실 모르겠다!
	cout << "\aCode verified!\r"								// \r : Carriage return(CR), 줄 맨 앞으로 이동
		<< "\vProceed with Plan Z3!\n";						// \v : Vertical Tab, 수직 탭으로 LF와 비슷해보인다.

	return 0;
}