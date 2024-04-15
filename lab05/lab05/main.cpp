#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool skobki(string), clear = true;

int main()
{
	setlocale(LC_CTYPE, "rus");
	string buf;
	cout << "������� ������: ";
	getline(cin, buf);
	bool isBalanced;
	isBalanced = skobki(buf);

	if (clear)
	{
		cout << "������ ���" << endl;
		return 1;
	}

	if (isBalanced)
	{
		cout << "������ ��������������" << endl;
	}
	else
	{
		cout << "������ �� ��������������" << endl;
	}

	return 0;
}

bool skobki(string buf) {
	stack <char> stack;

	for (char c : buf)
	{
		if (c == '(' || c == '[' || c == '{')
		{
			clear = false;
			stack.push(c);
		}
		else if (c == ')' || c == ']' || c == '}')
		{
			if (stack.empty())
			{
				return false;
			}
			char top = stack.top();
			stack.pop();
			if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{'))
			{
				return false;
			}
		}
	}

	return stack.empty();
}