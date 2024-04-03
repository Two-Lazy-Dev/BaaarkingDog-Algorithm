#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
int board[501][501];
int visited[501][501];

int resCount = 0;
int resSize = 0;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0,1, 0 };

typedef pair<int, int> pos;

int BFS(int x, int y)
{
	queue<pos> myQueue;
	myQueue.push(make_pair(x, y));
	visited[y][x] = 1;
	int cnt = 1;

	while (!myQueue.empty())
	{
		pos curPos = myQueue.front();
		myQueue.pop();
		for (int i = 0; i < 4; ++i)
		{
			pos nextPos = make_pair(curPos.X + dx[i], curPos.Y + dy[i]);
			if (nextPos.X >= 500 || nextPos.X < 0 || nextPos.Y >= 500 || nextPos.Y < 0) continue;
			if (visited[nextPos.Y][nextPos.X] == 1 || board[nextPos.Y][nextPos.X] != 1) continue;
			myQueue.push(nextPos);
			visited[nextPos.Y][nextPos.X] = 1;
			cnt++;
		}
	}

	return cnt;
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : �׸�

	/// BFS�� �̿��� Flood Fill�� �ϴ� ����

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (visited[i][j] == 1) continue;	// if�� �ۼ��Ҷ� �ƴ� ��츦 return break continue �ϴ°� �� �� �������̴�
			if (board[i][j] == 0) continue;

			resSize = max(resSize, BFS(j, i));	// ���� ���� resSize ������ 0���̱� ������ 0���� �ʱ�ȭ ����� �Ѵ�
			resCount++;
		}
	}

	cout << resCount << '\n';
	cout << resSize << '\n';

	return 0;
}
