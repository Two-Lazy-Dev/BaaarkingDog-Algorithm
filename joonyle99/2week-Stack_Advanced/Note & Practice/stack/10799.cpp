#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : �踷���

	// '()'�� ������
	// '(' + ')'�� �踷���

	/// input[i - 1] == ')'�� ����Ʈ�̴�
	///	string �迭�� ���� �Է� �����Ϳ� ������ �� �ִ�.
	///	���� �װ͵� �𸣰� stack�� 2�� ����Ͽ� �����߾���

	string input; cin >> input;
	int l = input.length();
	stack<char> stick;
	int res = 0;
	for (int i = 0; i < l; ++i)
	{
		// ������ or �踷��� ����
		if(input[i] == '(') stick.push(input[i]);
		else if (input[i] == ')')
		{
			// �������� ��
			if(input[i - 1] == '(')
			{
				stick.pop();
				res += stick.size();
			}
			// �� ������� ��
			else if (input[i - 1] == ')')
			{
				res++;
				stick.pop();
			}
		}
	}

	cout << res << '\n';

	return 0;
}
