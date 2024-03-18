// ����, ť, ���� Ư�� ��ġ������ ���Ҹ� �ְų� �� �� �ִ� ������ �ɷ��ִ� �ڷᱸ���̴�
// �̷��� ����, ť, ���� Restricted Structure��� �θ���

// ����

// '��Ģ������' �Ʒ� 3���� ��ɸ��� �����ϴ� �ڷᱸ��
//
// 1. ���� ����� ���ҿ� �߰�
// 2. ���� ����� ���Ҹ� ����
// 3. ���� ����� ���Ҹ� ��ȸ
//
// �̿��� ��ҵ��� �߰� / ���� / ��ȸ�� ��Ģ������ �Ұ����ϴ�
// �׷��� �� 3���� ����� O(1)�� �ð����⵵�� ����ȴ�
//
// ���� : '�迭' or '���� ����Ʈ'�� �̿��ؼ� ������ �����ϴ�

#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int stackArray[MX];
int topIndex = 0;               // topIndex�� ������ ���Ҹ� ����Ű���� �� ���� �ְ�
								// ������ ���ο� ���Ұ� ���� ��ġ�� ����Ű���� �� ���� �ִµ�,
								// push �Լ��� ������ ���� ���̱� ������ ������ ���� §��. (baaarking ���)

void push_joonyle(int x)
{
    topIndex++;                 // �ø� ��
    stackArray[topIndex] = x;   // ���� �߰�
}

void push_baaarking(int x)
{
    stackArray[topIndex++] = x; // ���� �߰� ��, �ø���
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

    stackArray[topIndex] = 0;   // ���� ���� ��
    topIndex--;                 // ���̱�
}

void pop_baaarking()
{
    if (topIndex <= 0)
        return;

    topIndex--;                 // ** topIndex�� ����Ű�� ������ �ʱ�ȭ�� ������ �����ϴ� **
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