#include <bits/stdc++.h>
using namespace std;

constexpr int MX = 1000005; // constexpr은 컴파일 시에만 할당이 가능하다
int queueArray[MX];
int head = 0, tail = 0;

void _push(int x)
{
	queueArray[tail++] = x;
}

void _pop()
{
	if (head >= tail)
	{
		cout << -1 << '\n';
		return;
	}

	cout << queueArray[head++] << '\n';
}

void _front()
{
	if (head >= tail)
	{
		cout << -1 << '\n';
		return;
	}

	cout << queueArray[head] << '\n';
}

void _back()
{
	if (head >= tail)
	{
		cout << -1 << '\n';
		return;
	}

	cout << queueArray[tail - 1] << '\n';
}

void _size()
{
	cout << tail - head << '\n';
}

void _empty()
{
	int v = tail - head;
	if (v <= 0) cout << 1 << '\n';
	else cout << 0 << '\n';
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 큐

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
		else if (instruction == "front") {
			_front();
		}
		else if (instruction == "back") {
			_back();
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
