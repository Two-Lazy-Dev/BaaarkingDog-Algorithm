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

	// Title : �丶��
	// ��ĥ�� ������ �丶����� ��� �ʹ���
	 
	/// BFS�� Ǯ��߰ڴٶ�� ������ �� �ִ� �ٰ�
	// 1. �ʺ� �켱 Ž��. �丶�䰡 �;���� ������ Queue�� �־� ������ �丶�並 ������� ��������
	// 2. �丶�䰡 �� �ͱ���� �ʿ��� �ּ� �ϼ��� ���ϱ� ���ؼ��� ���� ���� ���� �丶��鿡 ���� ���� ����� ���� �丶��κ����� �Ÿ��� ���� �� �־���� (dist[][]�� ���� �ذ�)

	// ó�� ���� �� ���� �丶���� ������ 1����� ������ BFS�� ���������
	// �ش� ���������� 2�� �̻��� �� �ֱ� ������ �������� �������� ��츦 �ٷ�� �Ѵ�

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
