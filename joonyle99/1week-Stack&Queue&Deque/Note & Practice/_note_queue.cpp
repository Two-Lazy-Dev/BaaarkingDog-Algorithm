// 큐
// 
// 또한 스택은 세로로 세워서 가장 상단의 원소를 top이라고 부르는 반면,
// 큐는 가로로 눕혀서 추가되는 곳을 rear(뒤쪽) 나오는 곳을 front(앞쪽)이라고 한다.
//
// 스택과 비슷한 방식으로 조회 / 추가 / 제거가 이루어진다.
//
// 1. rear(뒤쪽)에 원소를 추가
// 2. front(앞쪽)에서 원소를 제거
// 3. front의 원소를 조회
// 4. rear의 원소를 조회
//
// 스택은 top에서의 원소 조회 / 추가 / 제거 이외에는 '원칙적으로' 불가능 한데,
// 큐는 front와 rear에서의 원소 조회 / 추가 / 제거 이외의 경우에 불가능하다.
//
// => '원칙적으로'일뿐 배열로 구현하면 조회 / 추가 / 제거 기능을 추가할 수 있다.
// 하지만 스택이나 큐의 자료구조를 사용하면서 그럴 일이 없기 때문에 그러한 기능들은 STL에도 존재하지 않는다.
//
// head와 tail을 처음에 0으로 두고 큐를 시작한다
// head와 tail은 원소가 추가되거나 제거되면서 가리키는 인덱스의 크기가 점점 커진다.
// 따라서 앞쪽에 쓸모없는 공간이 생겨나게 되는데,
// 이러한 경우 Circular Queue라는 원형 큐의 구조를 사용하게 된다
// 원리는 단순히 가장 처음 원소로 가도록 하는 것이다.
//
// !! 주의 사항 !!
//
// 큐가 비어있는 경우에, front(), back(), pop()을 호출하면 '런타임 에러'가 발생할 수 있다.

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
