#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : °ýÈ£

	int T; cin >> T;
	while (T-- > 0)
	{
		stack<int> myStack;
		string input; cin >> input;
		int l = input.length();
		bool isYes = true;
		for (int i = 0; i < l; ++i)
		{
			if (input[i] == '(') myStack.push(input[i]);
			else
			{
				if (myStack.empty())
				{
					isYes = false;
					break;
				}
				else myStack.pop();
			}
		}

		if (!myStack.empty()) isYes = false;

		if (isYes) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}

	return 0;
}
