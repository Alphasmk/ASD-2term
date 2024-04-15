#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool skobki(string), clear = true;

int main()
{
	setlocale(LC_CTYPE, "rus");
	string buf;
	cout << "Введите строку: ";
	getline(cin, buf);
	bool isBalanced;
	isBalanced = skobki(buf);

	if (clear)
	{
		cout << "Скобок нет" << endl;
		return 1;
	}

	if (isBalanced)
	{
		cout << "Скобки сбалансированы" << endl;
	}
	else
	{
		cout << "Скобки не сбалансированы" << endl;
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