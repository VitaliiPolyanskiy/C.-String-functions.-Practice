#include <iostream>
#include "mystring.h"
using namespace std;

int main()
{
	char str[100];
	int result;
	cout << "Enter the string: ";
	cin.getline(str, 100);
	cout << endl;
	cout << str;
	LongestWord(str);
	cout << "\n\nEnter an arithmetic expression: ";
	cin.getline(str, 100);
	if (Arithmetic(str, result))
		cout << "Result: " << result << endl;

	return 0;
}