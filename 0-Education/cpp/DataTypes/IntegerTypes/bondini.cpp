#include <iostream>

using namespace std;

int main()
{
	long code;

	cout << "\aOperation \"HyperHype\" is now activated!\n";	// \n : NewLine(LF)
	cout << "Enter your agent code:________\b\b\b\b\b\b\b\b";	// \b : Backspace(BS), �ý��ۿ� ���� Ŀ���� �ڷ� �̵��ϴ� ���� ������� �ִ�
	cin >> code;
	cout << "\aYou entered " << code << "...\n";				// \a : Alert, � �������� ��� �𸣰ڴ�!
	cout << "\aCode verified!\r"								// \r : Carriage return(CR), �� �� ������ �̵�
		<< "\vProceed with Plan Z3!\n";						// \v : Vertical Tab, ���� ������ LF�� ����غ��δ�.

	return 0;
}