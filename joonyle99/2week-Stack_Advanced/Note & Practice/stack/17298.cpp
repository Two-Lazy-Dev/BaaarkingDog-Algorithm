#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 오큰수

	// 오큰수란?
	// 자기 오른쪽의 원소 중에서 자신보다 큰 수 중 가장 왼쪽에 있는 수

	stack<int> myStack;

	int N; cin >> N;
	vector<int> myVector(N);
	vector<int> result(1000001, -1);
	for (int i = 0; i < N; ++i)
	{
		// 3 5 2 7
		int v; cin >> v;
		myVector[i] = v;
		while (!myStack.empty() && myVector[myStack.top()] < v)
		{
			result[myStack.top()] = v;
			myStack.pop();
		}
		myStack.push(i);
	}
	for (int i = 0; i < N; ++i)
	{
		cout << result[i] << ' ';
	}

	return 0;
}
