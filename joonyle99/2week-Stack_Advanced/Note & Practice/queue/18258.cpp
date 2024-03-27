#include <bits/stdc++.h>
using namespace std;

// �迭�� �����ϱ�
int myQueue[2000001];
int head = 0, tail = 0;

void Push(int v)
{
	myQueue[tail++] = v;
}

void Pop()
{
	if (head >= tail)
	{
		cout << -1 << '\n';
		return;
	}

	cout << myQueue[head++] << '\n';
}

void Size()
{
	cout << tail - head << '\n';
}

void Empty()
{
	if (head >= tail)
	{
		cout << 1 << '\n';
	}
	else
	{
		cout << 0 << '\n';
	}
}

void Front()
{
	if (head >= tail)
	{
		cout << -1 << '\n';
		return;
	}

	cout << myQueue[head] << '\n';
}

void Back()
{
	if (head >= tail)
	{
		cout << -1 << '\n';
		return;
	}

	cout << myQueue[tail - 1] << '\n';
}

class ArrayQueue
{
public:
	// ���� �޸� 1MB��
	// 2^20 byte / 4 byte
	// 262,144������ ������ �� �ִ�
	int array[200001];
	int head = 0, tail = 0;

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
		if (Empty()) return -1;

		return array[head];
	}
	int Back() const
	{
		if (Empty()) return -1;

		return array[tail - 1];
	}

public:
	void Push(int v)
	{
		array[tail++] = v;
	}
	int Pop()
	{
		if (Empty()) return -1;

		return array[head++];
	}
};

class LinkedListQueue
{
	class Node
	{
	public:
		int value;
		Node* preNode;
		Node* nextNode;

	public:
		Node(int v)
		{
			this->value = v;

			preNode = nullptr;
			nextNode = nullptr;
		}
		void SetPreNode(Node* node)
		{
			this->preNode = node;
		}
		void SetNextNode(Node* node)
		{
			this->nextNode = node;
		}
	};

public:
	Node* front = nullptr;
	Node* rear = nullptr;
	int nodeCount = 0;

public:
	int Size() const
	{
		return nodeCount;
	}
	bool Empty() const
	{
		return (nodeCount == 0);
	}
	int Front() const
	{
		if (Empty()) return -1;

		return front->value;
	}
	int Back() const
	{
		if (Empty()) return -1;

		return rear->value;
	}

public:
	void PrintAllNode()
	{
		while (!Empty())
		{
			cout << Front() << '\n';
			Pop();
		}
	}

public:
	void Push(int v)
	{
		// ��� ����
		Node* newNode = new Node(v);

		// ��� ���� ����
		nodeCount++;

		if (nodeCount == 1)
		{
			front = newNode;
			rear = newNode;
			return;
		}

		// rear�� newNode�� Pointing ����
		newNode->SetNextNode(rear);
		rear->SetPreNode(newNode);

		// rear�� newNode�� ��ü
		rear = newNode;
	}
	int Pop()
	{
		if (Empty()) return -1;

		// ��� ���� ����
		nodeCount--;

		// �����ϴ� ����� value
		const int returnValue = front->value;

		// front�� ����Ű�� �ִ� ���� front�� ��ü
		front = front->preNode;

		return returnValue;
	}
};

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ť 2

	ArrayQueue myQueue;

	int N; cin >> N;
	while (N-- > 0)
	{
		string inst; cin >> inst;
		if (inst == "push")
		{
			int val; cin >> val;
			myQueue.Push(val);
		}
		else if (inst == "pop")
		{
			cout << myQueue.Pop() << '\n';
		}
		else if (inst == "size")
		{
			cout << myQueue.Size() << '\n';
		}
		else if (inst == "empty")
		{
			cout << myQueue.Empty() << '\n';
		}
		else if (inst == "front")
		{
			cout << myQueue.Front() << '\n';
		}
		else if (inst == "back")
		{
			cout << myQueue.Back() << '\n';
		}
	}

	return 0;
}
