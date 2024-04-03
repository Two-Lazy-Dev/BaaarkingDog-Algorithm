// BFS
// : 해당 노드와 인접한 노드를 '큐'에 넣고 큐가 빌때까지 계속해서 '인접한 노드'를 탐색

/// step by step
//
// 1. 시작하는 칸을 큐에 넣고 방문 표시를 남김
// 2. 큐에서 원소를 꺼내어, 그 칸에 상하좌우로 인접한 칸에 대해 3번을 진행
// 3. 해당 칸을 이전에 방문했다면 아무 것도 하지 않고, 처음으로 방문했다면 방문했다는 표시를 남기고 해당 칸을 큐에 삽입
// 4. 큐가 빌 때까지 2번을 반복
//
// 모든 칸이 큐에 1번씩 들어가므로 시간복잡도는 칸이 N개일 때 O(N)

/// Pair<> STL
//
// Pair STL은 pair 객체간의 대소 비교를 할 수 있다
//
// pair<int, int> myPair = make_pair(4, 11);
// pair<int, int> myPair2 = make_pair(4, 12);
//
// if (myPair > myPair2) cout << "myPair" << '\n';
// else cout << "myPair2" << '\n';
//
// result : myPair2
//
// -> pair 객체는 first 원소를 비교하고, 그 다음 second 원소를 비교한다

/// BFS 주의사항
// 1. 시작점에 방문했다는 표시를 남기지 않는다 (시작점을 두 번 방문할 수 있다)
// 2. 큐에 넣을 때 방문했다는 표시를 하는 대신, 큐에서 '빼낼 때' 방문했다는 표시를 남겼다 (같은 칸이 큐에 여러 번 들어갈 수 있어서 시간초과나 메모리초과가 날 수 있다)
// 3. 다음 탐색할 원소가 범위를 벗어났는지에 대한 체크를 잘못했다 (배열 인덱스 런타임 에러가 날 수 있다)

#include <bits/stdc++.h>
using namespace std;

int main()
{
	pair<int, int> myPair = make_pair(4, 11);
	pair<int, int> myPair2 = make_pair(4, 12);
	if (myPair > myPair2) cout << "myPair" << '\n';
	else cout << "myPair2" << '\n';

	return 0;
}