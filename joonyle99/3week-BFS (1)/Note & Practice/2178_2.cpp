#include <bits/stdc++.h>
using namespace std;

int N, M;
char board[101][101];
int dist[101][101];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool isDeteced = false;

void init()
{
	/*
	// 기본적이고 고전적인 방식
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			// -1은 visited 용도로 체크할 수 있다
			dist[i][j] = -1;
		}
	}
	*/

	// fill 함수를 이용한 방식
	for (int i = 0; i < N; ++i)
	{
		fill(dist[i], dist[i] + M, -1);
	}
}

void BFS(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	dist[y][x] = 1;	// 시작 지점은 1칸이 기본값

	while (!q.empty() && !isDeteced)
	{
		pair<int, int> curPos = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			pair<int, int> nextPos = make_pair(curPos.first + dx[i], curPos.second + dy[i]);
			if (nextPos.first >= M || nextPos.first < 0 || nextPos.second >= N || nextPos.second < 0) continue;
			if (board[nextPos.second][nextPos.first] != '1') continue;
			if (dist[nextPos.second][nextPos.first] != -1) continue;
			q.push(nextPos);
			dist[nextPos.second][nextPos.first] = dist[curPos.second][curPos.first] + 1;
			if (nextPos.second == N - 1 && nextPos.first == M - 1)
			{
				isDeteced = true;
				break;
			}
		}
	}

}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 미로 탐색

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		string input; cin >> input;
		for (int j = 0; j < M; ++j)
		{
			board[i][j] = input[j];
		}
	}

	init();

	pair<int, int> startPoint = { 0, 0 };

	// 최단거리는 BFS
	BFS(startPoint.first, startPoint.second);

	cout << dist[N - 1][M - 1] << ' ';

	/*
	for(int i=0; i<N; ++i)
	{
		for(int j=0; j<M; ++j)
		{
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
	*/

	/*
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	*/

	return 0;
}
