// 덱 (Deque)
//
// Deque : Double Ended Queue 라는 뜻을 가지고 있다.
//
// Stack과 Queue를 Deque의 '특수한 예시' 정도로 생각하면 좋을 것 같다.
// - Dequeue
//		- Stack
//		- Queue
//
// 이런식으로 하위 분류되는 느낌
//
// 스택과 큐와 마찬가지로
//
// 1. 원소의 가장 앞 / 뒤에 요소를 추가
// 2. 원소의 가장 앞 / 뒤의 요소를 제거
// 3. 원소의 가장 앞 / 뒤의 요소를 조회
//
// 이 모든 게 O(1)의 시간복잡도로 접근이 가능하고
//
// 스택과 큐와의 차이점으로는
// STL Deque에서도 가장 앞 / 뒤 이외의 요소를 '인덱스로 접근'이 가능하다는 특징이 있다.
//
// STL Deque는 매우 독특하게도 STL Vector와 매우 비슷한 기능을 가지고 있다.
//
// https://cplusplus.com/reference/deque/deque/#:~:text=Both%20vectors%20and%20deques%20provide%20a%20very%20similar%20interface%20and%20can%20be%20used%20for%20similar%20purposes
/// While vectors use a single array that needs to be occasionally reallocated for growth, the elements of a deque can be scattered in different chunks of storage
// 
// push_front(), push_back(), pop_front(), pop_back() ...
// + insert(), erase(), 인덱스로 요소에 접근 (Stack이나 Queue STL과 다른점)
//
// 또한 Vector STL은 back의 위치에 push하는 경우 O(1)이지만 front의 위치에 push를 하는 경우 O(N)이 된다.
// 하지만 Deque STL은 front의 위치에도 O(1)의 시간복잡도로 요소 추가가 가능하다. (앞뒤로 뚫려있기 때문이다)

#include <bits/stdc++.h>
using namespace std;

////////////////////
/// 이렇게 스택이나 큐와 달리 MX * 2가 되는 크기로 배열을 만들어,
/// 0번 인덱스가 아닌 중간 인덱스에서 시작한다

constexpr int MX = 1000005;
int dequeArray[2 * MX + 1];
int head = MX, tail = MX;

////////////////////

void _push_back(int x)
{
	dequeArray[tail++] = x;
}

void _push_front(int x)
{
	// ** 이게 중요하다 --head **
	dequeArray[--head] = x;
}

void _pop_back()
{
	if(head == tail)
	{
		cout << -1 << '\n';
		return;
	}

	// ** 새로운 값이 들어올 곳을 가리키기 때문에 -- 먼저 해준다 **
	cout << dequeArray[--tail] << '\n';
}

void _pop_front()
{
	if (head == tail)
	{
		cout << -1 << '\n';
		return;
	}

	// ** 새로운 값이 들어올 곳을 가리키지 않고 가장 앞의 값을 가리키고 있기 때문에 ++를 나중에 해준다 **
	cout << dequeArray[head++] << '\n';
}

void _size()
{
	cout << tail - head << '\n';
}

void _empty()
{
	if (head == tail)
	{
		cout << 1 << '\n';
	}
	else
	{
		cout << 0 << '\n';
	}
}

void _front()
{
	if (head == tail)
	{
		cout << -1 << '\n';
		return;
	}

	// ** head는 --head를 해주기 때문에 새로운 값이 들어갈 곳을 가리키는 것이 아니라 현재 값이 있는 곳을 가리킨다 **
	cout << dequeArray[head] << '\n';
}

void _back()
{
	if (head == tail)
	{
		cout << -1 << '\n';
		return;
	}

	cout << dequeArray[tail - 1] << '\n';
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 덱 (백준 10866번 문제)

	int N; cin >> N;

	while (N--)
	{
		string instruction; cin >> instruction;

		if (instruction == "push_back") {
			int number; cin >> number;
			_push_back(number);
		}
		else if (instruction == "push_front") {
			int number; cin >> number;
			_push_front(number);
		}
		else if (instruction == "pop_back") {
			_pop_back();
		}
		else if (instruction == "pop_front") {
			_pop_front();
		}
		else if (instruction == "back") {
			_back();
		}
		else if (instruction == "front") {
			_front();
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
