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

	// Title : ȸ���ϴ� ť

	int N; cin >> N;    // ť�� ũ��
	int M; cin >> M;    // �̴� ���� ����

	ArrayDequeue myDequeue;

	int calculateCount = 0;

	for (int i = 0; i < N; ++i)
	{
		myDequeue.Push_back(i + 1);
	}

	for (int i = 0; i < M; ++i)
	{
		// ������ ���� ��
		int targetValue; cin >> targetValue;

		int targetIndex;

		// ** ���⼭ �� ������ ���� ���� �ε����� �˾ƾ� �Ѵ� **
		for (int j = myDequeue.head; j < myDequeue.tail; ++j)
		{
			if(myDequeue.array[j] == targetValue)
			{
				targetIndex = j;
			}
		}

		while (true)
		{
			// ù ��° ���� Ȯ���Ѵ�
			int firstValue = myDequeue.Front();

			// ã�� ���� �´ٸ�
			if (firstValue == targetValue)
			{
				myDequeue.Pop_front();
				break;
			}

			// �������� �̵��ϴ� �� �� ����� ���
			if (targetIndex - myDequeue.head <= myDequeue.tail - targetIndex)
			{
				// �������� �� ĭ �̵���Ų��
				int front = myDequeue.Pop_front();
				myDequeue.Push_back(front);
			}
			else
			{
				// ���������� �� ĭ �̵� ��Ų��
				int back = myDequeue.Pop_back();
				myDequeue.Push_front(back);
			}
			calculateCount++;
		}
	}

	cout << calculateCount << '\n';

	return 0;
}
