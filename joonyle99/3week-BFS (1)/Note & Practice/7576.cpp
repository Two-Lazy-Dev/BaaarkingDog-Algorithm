#include <bits/stdc++.h>
using namespace std;

int M, N;
int board[1001][1001];
int dist[1001][1001];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
queue<pair<int, int>> q;

void init()
{
	for (int i = 0; i < N; ++i) fill(dist[i], dist[i] + M, 0);
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 토마토
	// 며칠이 지나면 토마토들이 모두 익는지
	 
	/// BFS로 풀어야겠다라고 생각할 수 있는 근거
	// 1. 너비 우선 탐색. 토마토가 익어나가는 과정이 Queue에 넣어 인접한 토마토를 순서대로 익혀나감
	// 2. 토마토가 다 익기까지 필요한 최소 일수를 구하기 위해서는 아직 익지 않은 토마토들에 대해 가장 가까운 익은 토마토로부터의 거리를 구할 수 있어야함 (dist[][]를 통해 해결)

	// 처음 시작 시 익은 토마토의 개수가 1개라면 기존의 BFS와 비슷하지만
	// 해당 문제에서는 2개 이상일 수 있기 때문에 시작점이 여러개인 경우를 다뤄야 한다

	cin >> M >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 1) q.push(make_pair(j, i));
		}
	}

	init();

	while (!q.empty())
	{
		pair<int, int> curPos = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			pair<int, int> nextPos = make_pair(curPos.first + dx[i], curPos.second + dy[i]);
			if (nextPos.first >= M || nextPos.first < 0 || nextPos.second >= N || nextPos.second < 0) continue;
			if (board[nextPos.second][nextPos.first] != 0) continue;
			if (dist[nextPos.second][nextPos.first] != 0) continue;
			board[nextPos.second][nextPos.first] = 1;
			dist[nextPos.second][nextPos.first] = dist[curPos.second][curPos.first] + 1;
			q.push(nextPos);
		}
	}

	int res = 0;

	for(int i=0; i<N; ++i)
	{
		for(int j=0; j<M; ++j)
		{
			if(board[i][j] == 0)
			{
				cout << -1 << '\n';
				return 0;
			}
			else if(board[i][j] == 1)
			{
				res = max(res, dist[i][j]);
			}
			else if(board[i][j] == -1)
			{
				continue;
			}
		}
	}

	cout << res << '\n';

	/*
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
	*/

	return 0;
}
