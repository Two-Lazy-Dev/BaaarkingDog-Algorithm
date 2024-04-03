#include <bits/stdc++.h>
using namespace std;

int T;
int M, N, K;
int X, Y;

int board[50][50];
int visited[50][50];

//  좌 상 우 하
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void Reset(int M, int N)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			board[i][j] = 0;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			visited[i][j] = 0;
		}
	}
}

void PrintBoard(int M, int N)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cout << board[i][j] << ' ';
		}

		cout << '\n';
	}
}

void BFS(int x, int y)
{
	queue<pair<int, int>> myQueue;

	myQueue.emplace(x, y);
	visited[y][x] = 1;				// y, x 순서로 넣어줘야 한다

	while (!myQueue.empty())
	{
		const pair<int, int> curPos = myQueue.front();
		myQueue.pop();

		for (int i = 0; i < 4; ++i)
		{
			pair<int, int> nextPos = make_pair(curPos.first + dx[i], curPos.second + dy[i]);

			if (nextPos.first > M - 1 || nextPos.first < 0 || nextPos.second > N - 1 || nextPos.second < 0) continue;
			if (board[nextPos.second][nextPos.first] == 0) continue;		// 배추가 안 심어져 있다면
			if (visited[nextPos.second][nextPos.first] == 1) continue;		// 방문한 배추라면

			myQueue.push(nextPos);
			visited[nextPos.second][nextPos.first] = 1;
		}
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 유기농 배추

	cin >> T;
	while (T-- > 0)
	{
		int result = 0;

		cin >> M >> N >> K;

		for (int i = 0; i < K; ++i)
		{
			cin >> X >> Y;

			board[Y][X] = 1;
		}

		// PrintBoard(M, N);

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (board[i][j] == 1 && visited[i][j] == 0)
				{
					BFS(j, i);
					result++;
				}
			}
		}

		// 이 타이밍에 리셋해줘야 정확한 범위만큼 리셋이 가능하다
		Reset(M, N);

		cout << result << '\n';
	}

	return 0;
}
