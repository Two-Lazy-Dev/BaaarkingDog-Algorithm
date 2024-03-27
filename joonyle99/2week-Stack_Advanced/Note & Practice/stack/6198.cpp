#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 옥상 정원 꾸미기

	/// O(N^2)의 시간복잡도를 가진 방식
	// 입력 데이터 N이 최대 80,000이므로
	// 1초에 연산 6,400,000,000번이다 이는 64억번으로 한참 모자르다
	// 시간 초과 발생

	/*
	int heightArr[100001];

	int N; cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> heightArr[i];
	}

	// 64억까지 들어갈 수 있으므로 int가 아닌 long long을 사용한다
	long long count = 0;

	for (int origin = 0; origin < N; ++origin)
	{
		for (int target = origin + 1; target < N; ++target)
		{
			if (heightArr[origin] > heightArr[target])
				count++;
			else
				break;
		}
	}

	cout << count << '\n';
	*/

	/// monotone stack이란?
	// -> 스택 내부를 오름차순 또는 내림차순으로 유지 해주는 알고리즘
	// https ://justicehui.github.io/medium-algorithm/2019/01/01/monotoneStack/
	// -> 해당 알고리즘으로 O(N)의 시간 복잡도 정도로 줄여주는 강력한 테크닉
	// 한 건물 한건물을 추가할때마다 stack 에 자기보다 큰놈들만 냅두기
	// ->여기서 monotone stack 사용

	stack<int> myStack;

	// 자료형 조심하자 최대로 64억까지 나올 수가 있는데 int가 되겠냐
	long long count = 0;

	int N; cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int h; cin >> h;
		/// 핵심 로직 montone stack 사용
		// 높이가 자신보다 낮거나 같은 빌딩들을 빼낸다
		// cf) myStack.empty()를 먼저 썼기 때문에 empty()면 top()함수까지 가지 않고 while은 종료된다
		// 왼쪽에 자기보다 높이가 큰 빌딩밖에 남지 않는데,
		// 그러한 빌딩들은 자신을 내려다 볼 수 있다는 뜻이다
		// 여기서 포인트는 자신보다 낮은 높이의 빌딩을 제외하면서 자연스럽게 높이가 큰 것만 남기게 되면
		// ** 결국에 새롭게 들어오는 빌딩은 남은 모든 빌딩들에게 벤치마킹 될 수 있다는 것이다. **
		//
		// 스택에 남아있는 숫자(높이) 개수가 현재 나를 보고 있는 건물 수이다
		while (!myStack.empty() && myStack.top() <= h)
		{
			myStack.pop();
		}
		count += myStack.size();
		myStack.push(h);
	}

	cout << count << '\n';

	/// 스택을 활용해서 문제를 해결하는 이유
	
	// 뭔가 논리적인 비약이 크다. 근데 곱씹어 생각해 봤을 때, { 10, 3, 7, 4 } 구간에서 높이가 7인 건물은 3보다 같거나 크므로, 3은 스택에서 제거가 되며 7은 스택에 넣어진다. 그리고 스택에는 { 10, 7 } 만 남아있다.

	// ** 일반적으로 생각했을 때, 다음 높이가 4인 건물의 입장에서 보았을 때도, 높이가 3인 건물은 높이가 7인 건물에 의해 가려지므로, 3 건물은 4 건물에 당연히 보여지지 않는 건물이다. **

		// 그래서 요약하자면, 다음과 같은 상황에서 스택이 적절히 사용될 수 있다고 생각했다.

		// 현재 내 값으로 인해 이전 값이 필요 없어질 때(ex.높이 7에 의해 높이 3 건물은 필요 없어짐)
		// 조건이 한 방향 으로만 진행된다고 보장될 때(스택의 특성 LIFO)

	return 0;
}
