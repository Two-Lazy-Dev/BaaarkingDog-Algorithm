#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 쇠막대기

	// '()'는 레이저
	// '(' + ')'는 쇠막대기

	/// input[i - 1] == ')'가 포인트이다
	///	string 배열로 이전 입력 데이터에 접근할 수 있다.
	///	나는 그것도 모르고 stack을 2개 사용하여 접근했었다

	string input; cin >> input;
	int l = input.length();
	stack<char> stick;
	int res = 0;
	for (int i = 0; i < l; ++i)
	{
		// 레이저 or 쇠막대기 시작
		if(input[i] == '(') stick.push(input[i]);
		else if (input[i] == ')')
		{
			// 레이저의 끝
			if(input[i - 1] == '(')
			{
				stick.pop();
				res += stick.size();
			}
			// 쇠 막대기의 끝
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
