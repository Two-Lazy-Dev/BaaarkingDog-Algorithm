#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int stackArray[MX];
int topIndex = 0;

void _push(int x)
{
	stackArray[topIndex++] = x;
}

bool _empty()
{
	if (topIndex <= 0)
	{
		cout << 1 << '\n';
		return 1;
	}
	else
	{
		cout << 0 << '\n';
		return 0;
	}
}

void _pop()
{
	if (topIndex <= 0)
	{
		cout << -1 << '\n';
		return;
	}

	topIndex--;
	cout << stackArray[topIndex] << '\n';
}

void _size()
{
	cout << topIndex << '\n';
}

void _top()
{
	if (topIndex <= 0)
	{
		cout << -1 << '\n';
		return;
	}

	cout << stackArray[topIndex - 1] << '\n';
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ½ºÅÃ

	int N; cin >> N;

	while (N--)
	{
		string instruction; cin >> instruction;

		if (instruction == "push") {
			int number; cin >> number;
			_push(number);
		}
		else if (instruction == "pop") {
			_pop();
		}
		else if (instruction == "top") {
			_top();
		}
		else if (instruction == "empty") {
			_empty();
		}
		else if (instruction == "size") {
			_size();
		}
	}

	return 0;
}
