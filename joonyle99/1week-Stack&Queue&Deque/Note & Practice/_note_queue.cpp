// ť
// 
// ���� ������ ���η� ������ ���� ����� ���Ҹ� top�̶�� �θ��� �ݸ�,
// ť�� ���η� ������ �߰��Ǵ� ���� rear(����) ������ ���� front(����)�̶�� �Ѵ�.
//
// ���ð� ����� ������� ��ȸ / �߰� / ���Ű� �̷������.
//
// 1. rear(����)�� ���Ҹ� �߰�
// 2. front(����)���� ���Ҹ� ����
// 3. front�� ���Ҹ� ��ȸ
// 4. rear�� ���Ҹ� ��ȸ
//
// ������ top������ ���� ��ȸ / �߰� / ���� �̿ܿ��� '��Ģ������' �Ұ��� �ѵ�,
// ť�� front�� rear������ ���� ��ȸ / �߰� / ���� �̿��� ��쿡 �Ұ����ϴ�.
//
// => '��Ģ������'�ϻ� �迭�� �����ϸ� ��ȸ / �߰� / ���� ����� �߰��� �� �ִ�.
// ������ �����̳� ť�� �ڷᱸ���� ����ϸ鼭 �׷� ���� ���� ������ �׷��� ��ɵ��� STL���� �������� �ʴ´�.
//
// head�� tail�� ó���� 0���� �ΰ� ť�� �����Ѵ�
// head�� tail�� ���Ұ� �߰��ǰų� ���ŵǸ鼭 ����Ű�� �ε����� ũ�Ⱑ ���� Ŀ����.
// ���� ���ʿ� ������� ������ ���ܳ��� �Ǵµ�,
// �̷��� ��� Circular Queue��� ���� ť�� ������ ����ϰ� �ȴ�
// ������ �ܼ��� ���� ó�� ���ҷ� ������ �ϴ� ���̴�.
//
// !! ���� ���� !!
//
// ť�� ����ִ� ��쿡, front(), back(), pop()�� ȣ���ϸ� '��Ÿ�� ����'�� �߻��� �� �ִ�.

#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int queueArray[MX];
int head = 0, tail = 0;

void _push(int x)
{
	queueArray[tail++] = x;
}

void _pop()
{
	if (head >= tail) return;

	head++;
}

int _front()
{
	return queueArray[head];
}

int _back()
{
	return queueArray[tail - 1];
}

void test_case()
{
	_push(5);
	_push(2);
	cout << _back() << '\n';
	_push(16);
	cout << _front() << '\n';
	_pop();
	_pop();
	_pop();
	_pop();
	_push(5);
	cout << _front() << '\n';
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	test_case();

	return 0;
}
