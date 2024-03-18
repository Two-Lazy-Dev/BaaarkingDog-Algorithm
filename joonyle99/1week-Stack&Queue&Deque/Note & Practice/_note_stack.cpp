// 스택, 큐, 덱은 특정 위치에서만 원소를 넣거나 뺄 수 있는 제한이 걸려있는 자료구조이다
// 이렇게 스택, 큐, 덱은 Restricted Structure라고 부른다

// 스택

// '원칙적으로' 아래 3가지 기능만을 제공하는 자료구조
//
// 1. 가장 상단의 원소에 추가
// 2. 가장 상단의 원소를 제거
// 3. 가장 상단의 원소를 조회
//
// 이외의 요소들은 추가 / 제거 / 조회가 원칙적으로 불가능하다
// 그래도 위 3개의 기능은 O(1)의 시간복잡도로 실행된다
//
// 구현 : '배열' or '연결 리스트'를 이용해서 구현이 가능하다

#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int stackArray[MX];
int topIndex = 0;               // topIndex를 마지막 원소를 가리키도록 할 수도 있고
								// 앞으로 새로운 원소가 들어가는 위치를 가리키도록 할 수도 있는데,
								// push 함수에 초점을 맞출 것이기 때문에 후자의 경우로 짠다. (baaarking 방식)

void push_joonyle(int x)
{
    topIndex++;                 // 늘린 후
    stackArray[topIndex] = x;   // 원소 추가
}

void push_baaarking(int x)
{
    stackArray[topIndex++] = x; // 원소 추가 후, 늘리기
}

int top_joonyle()
{
    if (topIndex <= 0)
        return -999999999;

    return stackArray[topIndex];
}

void pop_joonyle()
{
    if (topIndex <= 0)
        return;

    stackArray[topIndex] = 0;   // 원소 제거 후
    topIndex--;                 // 줄이기
}

void pop_baaarking()
{
    if (topIndex <= 0)
        return;

    topIndex--;                 // ** topIndex가 가리키는 원소의 초기화는 생략이 가능하다 **
}

void stack_test_case_joonyle()
{
    push_joonyle(5);
    push_joonyle(7);
    push_joonyle(16);
    pop_joonyle();
    pop_joonyle();
    push_joonyle(23);
    push_joonyle(71);

    cout << top_joonyle() << '\n';
}

void stack_test_case_baaarking()
{
    push_baaarking(5);
    push_baaarking(7);
    push_baaarking(16);
    pop_baaarking();
    pop_baaarking();
    push_baaarking(23);
    push_baaarking(71);

    cout << top_joonyle() << '\n';
}

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    stack_test_case_joonyle();

    return 0;
}