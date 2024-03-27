#include <bits/stdc++.h>
using namespace std;

int topArr[500001];
stack<pair<int, int>> topStack;
stack<int> topStack2;

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 탑

	/// 배열로 구현
	// 0 1 2 3 4를 돌면서
	// 3의 경우 2, 1, 0을 향해 쏘면서 막히면 정지하고 해당 탑의 번호를 입력
	// 이런식으로 하면 될거같은데?

	// 탑의 높이가 100,000,000
	// 탑의 수가 500,000
	// 이라고 가정한다면
	//
	// O(N^2)의 시간복잡도로 구현하면
	// 500,000 * 500,000은 250,000,000,000 (약 천억번)
	// 시간 제한이 1.5초이기 때문에
	// 컴퓨터가 시간 안에 할 수 있는 연산횟수는 약 1억번
	// 따라서 O(N^2)의 시간복잡도로 구현하면 시간초과가 뜰 것이다

	/// 스택으로 구현
	// 왼쪽 탑부터 스택에 쌓인다
	// 최종적으로 가장 상단에 있는 것은 오른쪽 탑일 것이다
	// 따라서 가장 상단의 탑을 기준으로 하나 하나 요소를 제거해가며 (왼쪽으로 신호를 송신)
	// 수신할 수 있는 탑을 탐색한다
	// 이러한 과정을 모든 탑에 대하여 반복 작업한다
	//
	// 근데 이렇게 스택으로 구현해도 O(N^2)인 것은 마찬가지이다
	// 왜냐하면 N개의 탑 높이를 순회하면서
	// (N - 1), (N - 2), ... 개의 탑과 비교하니까
	// 배열로 구현하는 것과 사실상 같은 맥락이다.
	//
	// 따라서 아주 획기적인 방법이 필요하다

	/*
	int N; cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int height; cin >> height;
		topStack2.push(height);	// N
	}

	vector<int> result2(topStack2.size(), 0);

	// 모든 탑을 순회한다
	while (!topStack2.empty())
	{
		// 처음 검사할 탑을 설정
		int topHeight = topStack2.top();

		// 해당 탑을 제외한 나머지 탑을 향해 신호 발사
		topStack2.pop();
		stack<int> tempTopStack = topStack2;

		// 왼쪽으로 있는 탑을 향해 반복해서 신호를 보낸다
		while (!tempTopStack.empty())
		{
			int targetTopNumber = tempTopStack.size();
			int tartgetTopHeight = tempTopStack.top();

			// 신호를 수신하는 경우, 해당 높이를 입력하고 다음 탑을 탐색한다
			if (tartgetTopHeight >= topHeight)
			{
				result2[topStack2.size()] = targetTopNumber;
				break;
			}

			tempTopStack.pop();
		}
	}

	for (auto v : result2)
	{
		cout << v << ' ';
	}

	cout << '\n';
	*/

	/// O(N)의 시간복잡도로 탑의 높이를 비교하는 방법
	// 탑의 높이는 왼쪽에서부터 주어진다
	// 6 9 5 7 4 이런식으로
	// 그런데 가만보면 6이 주어지고, 9가 주어지고, 5가 주어지는 이러한 순서 속에서
	// 새롭게 추가되는 탑의 높이가 최고 높이로 갱신된다면 이전의 탑은 지워도 된다는 사실을 발견할 수 있다

	// 아래 코드는 내 코드가 아니라
	// 인터넷에서 다른 사람이 작성한 코드이다
	// 로직이 군더더기 없이 깔끔한데, 이러한 코드 작성을 보고 배워야겠다
	// 어떻게 이렇게 깔끔하게 생각하지
	// 문제 이해도의 차이인가?
	// 왜 나는 로직이 더럽고 깔끔하지 못하지?
	// 내 코드는 약간 야매로 하나하나 끼워 맞추면서 성공한 느낌인데
	// 마음에 안 든다

	// 1. 모든 탑의 레이저 송신기는 레이저 신호를 지표면과 평행하게 수평 직선의 왼쪽 방향으로 발사 (한 방향으로 발사한다 스택의 Restricted 성질 이용)
	// 2. 가장 먼저 만나는 단 하나의 탑에서만 수신이 가능하다. (이전 데이터를 삭제하여, 연산 횟수를 줄이는 경우)

	int N; cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int height; cin >> height;

		// 바로 반복문을 돌려버리는구나
		while(!topStack.empty())
		{
			// 수신탑 발견
			if (topStack.top().second >= height)
			{
				cout << topStack.top().first << ' ';
				break;
			}

			// 수신탑을 발견하기 전까지 계속해서 제거
			topStack.pop();
		}

		// 수신탑이 없는 경우
		if(topStack.empty())
		{
			cout << 0 << ' ';
		}

		// 새로운 수신탑 등록
		topStack.push(make_pair(i + 1, height));
	}

	/*
	 *
	 *	처음 통과한 내 코드
	 *	코드의 로직이 좀 더러운 것을 볼 수 있다
	 *
	int Num; cin >> Num;
	vector<int> result(Num);
	for (int i = 0; i < Num; ++i)
	{
		int height; cin >> height;

		if (topStack.empty())
		{
			topStack.push(make_pair(i + 1, height));
			result[i] = 0;
			continue;
		}

		if (!topStack.empty() && topStack.top().second <= height)
		{
			while (!topStack.empty())
			{
				topStack.pop();

				if (topStack.empty())
				{
					result[i] = 0;
					break;
				}

				if (topStack.top().second >= height)
				{
					result[i] = topStack.top().first;
					break;
				}
			}
		}
		else if (!topStack.empty() && topStack.top().second >= height)
		{
			result[i] = topStack.top().first;
		}

		topStack.push(make_pair(i + 1, height));
	}

	for (auto v : result)
	{
		cout << v << ' ';
	}
	*/

	return 0;
}
