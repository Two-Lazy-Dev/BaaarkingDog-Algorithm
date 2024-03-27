#include <bits/stdc++.h>
using namespace std;

class ArrayDequeue
{
public:
	int array[100000 * 2 + 1];
	int head = 100000, tail = 100000;

public:
	int Size() const
	{
		return tail - head;
	}
	bool Empty() const
	{
		return (head == tail);
	}
	int Front() const
	{
		return array[head];
	}
	int Back() const
	{
		return array[tail - 1];
	}

public:
	void PrintAll() const
	{
		for (int i = head; i < tail; ++i)
		{
			cout << array[i] << ' ';
		}

		cout << '\n';
	}

public:
	void Push_front(int x)
	{
		array[--head] = x;
	}
	void Push_back(int x)
	{
		array[tail++] = x;
	}
	int Pop_front()
	{
		return array[head++];
	}
	int Pop_back()
	{
		return array[--tail];
	}
};

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 회전하는 큐

	int N; cin >> N;    // 큐의 크기
	int M; cin >> M;    // 뽑는 수의 개수

	ArrayDequeue myDequeue;

	int calculateCount = 0;

	for (int i = 0; i < N; ++i)
	{
		myDequeue.Push_back(i + 1);
	}

	for (int i = 0; i < M; ++i)
	{
		// 빼내고 싶은 값
		int targetValue; cin >> targetValue;

		int targetIndex;

		// ** 여기서 이 빼내고 싶은 값의 인덱스를 알아야 한다 **
		for (int j = myDequeue.head; j < myDequeue.tail; ++j)
		{
			if(myDequeue.array[j] == targetValue)
			{
				targetIndex = j;
			}
		}

		while (true)
		{
			// 첫 번째 값을 확인한다
			int firstValue = myDequeue.Front();

			// 찾는 값이 맞다면
			if (firstValue == targetValue)
			{
				myDequeue.Pop_front();
				break;
			}

			// 왼쪽으로 이동하는 게 더 가까운 경우
			if (targetIndex - myDequeue.head <= myDequeue.tail - targetIndex)
			{
				// 왼쪽으로 한 칸 이동시킨다
				int front = myDequeue.Pop_front();
				myDequeue.Push_back(front);
			}
			else
			{
				// 오른쪽으로 한 칸 이동 시킨다
				int back = myDequeue.Pop_back();
				myDequeue.Push_front(back);
			}
			calculateCount++;
		}
	}

	cout << calculateCount << '\n';

	return 0;
}
