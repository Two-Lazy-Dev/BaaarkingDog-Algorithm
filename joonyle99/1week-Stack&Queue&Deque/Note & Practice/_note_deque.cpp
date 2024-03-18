// �� (Deque)
//
// Deque : Double Ended Queue ��� ���� ������ �ִ�.
//
// Stack�� Queue�� Deque�� 'Ư���� ����' ������ �����ϸ� ���� �� ����.
// - Dequeue
//		- Stack
//		- Queue
//
// �̷������� ���� �з��Ǵ� ����
//
// ���ð� ť�� ����������
//
// 1. ������ ���� �� / �ڿ� ��Ҹ� �߰�
// 2. ������ ���� �� / ���� ��Ҹ� ����
// 3. ������ ���� �� / ���� ��Ҹ� ��ȸ
//
// �� ��� �� O(1)�� �ð����⵵�� ������ �����ϰ�
//
// ���ð� ť���� ���������δ�
// STL Deque������ ���� �� / �� �̿��� ��Ҹ� '�ε����� ����'�� �����ϴٴ� Ư¡�� �ִ�.
//
// STL Deque�� �ſ� ��Ư�ϰԵ� STL Vector�� �ſ� ����� ����� ������ �ִ�.
//
// https://cplusplus.com/reference/deque/deque/#:~:text=Both%20vectors%20and%20deques%20provide%20a%20very%20similar%20interface%20and%20can%20be%20used%20for%20similar%20purposes
/// While vectors use a single array that needs to be occasionally reallocated for growth, the elements of a deque can be scattered in different chunks of storage
// 
// push_front(), push_back(), pop_front(), pop_back() ...
// + insert(), erase(), �ε����� ��ҿ� ���� (Stack�̳� Queue STL�� �ٸ���)
//
// ���� Vector STL�� back�� ��ġ�� push�ϴ� ��� O(1)������ front�� ��ġ�� push�� �ϴ� ��� O(N)�� �ȴ�.
// ������ Deque STL�� front�� ��ġ���� O(1)�� �ð����⵵�� ��� �߰��� �����ϴ�. (�յڷ� �շ��ֱ� �����̴�)

#include <bits/stdc++.h>
using namespace std;

////////////////////
/// �̷��� �����̳� ť�� �޸� MX * 2�� �Ǵ� ũ��� �迭�� �����,
/// 0�� �ε����� �ƴ� �߰� �ε������� �����Ѵ�

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
	// ** �̰� �߿��ϴ� --head **
	dequeArray[--head] = x;
}

void _pop_back()
{
	if(head == tail)
	{
		cout << -1 << '\n';
		return;
	}

	// ** ���ο� ���� ���� ���� ����Ű�� ������ -- ���� ���ش� **
	cout << dequeArray[--tail] << '\n';
}

void _pop_front()
{
	if (head == tail)
	{
		cout << -1 << '\n';
		return;
	}

	// ** ���ο� ���� ���� ���� ����Ű�� �ʰ� ���� ���� ���� ����Ű�� �ֱ� ������ ++�� ���߿� ���ش� **
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

	// ** head�� --head�� ���ֱ� ������ ���ο� ���� �� ���� ����Ű�� ���� �ƴ϶� ���� ���� �ִ� ���� ����Ų�� **
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

	// Title : �� (���� 10866�� ����)

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
