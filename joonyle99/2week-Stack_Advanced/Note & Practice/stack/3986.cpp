#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 좋은 단어

	int N; cin >> N;
	int count = 0;
	while (N-- > 0)
	{
		string input; cin >> input;

		stack<int> myStack;
		int l = input.length();
		for(int i=0; i<l; ++i)
		{
			if (myStack.empty()) myStack.push(input[i]);
			else
			{
				if (myStack.top() == input[i]) myStack.pop();
				else myStack.push(input[i]);
			}
		}

		if (myStack.empty()) count++;
	}

	cout << count << '\n';

	return 0;
}
