#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ±ÕÇüÀâÈù ¼¼»ó

	while (true)
	{
		string input;
		std::getline(cin, input);
		if (input == ".") break;
		int l = input.length();
		stack<int> myStack;
		bool isYes = true;
		for (int i = 0; i < l; ++i)
		{
			if (input[i] == '(' || input[i] == '[') myStack.push(input[i]);
			else if (input[i] == ')')
			{
				if(!myStack.empty() && myStack.top() == '(') myStack.pop();
				else
				{
					isYes = false;
					break;
				}
			}
			else if (input[i] == ']')
			{
				if (!myStack.empty() && myStack.top() == '[') myStack.pop();
				else
				{
					isYes = false;
					break;
				}
			}
		}

		if (!myStack.empty()) isYes = false;

		if (isYes) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}

	return 0;
}
