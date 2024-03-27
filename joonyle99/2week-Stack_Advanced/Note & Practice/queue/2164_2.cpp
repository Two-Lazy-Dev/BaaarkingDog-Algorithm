#include <bits/stdc++.h>
using namespace std;

class ArrayQueue
{
public:
	// ���� �޸� 1MB��
	// 2^20 byte / 4 byte
	// 262,144�� ������ �� �ִ�
	int array[100001];
	int head = 0, tail = 0;

public:
	void Push(int v)
	{
		array[tail++] = v;
	}

	void Pop()
	{
		if (head >= tail)
		{
			cout << -1 << '\n';
			return;
		}

		cout << array[head++] << '\n';
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

		cout << array[head] << '\n';
	}

	void Back()
	{
		if (head >= tail)
		{
			cout << -1 << '\n';
			return;
		}

		cout << array[tail - 1] << '\n';
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
	int Size()
	{
		return nodeCount;
	}
	bool Empty()
	{
		return (nodeCount == 0);
	}
	int Front()
	{
		if (Empty()) return -1;

		return front->value;
	}
	int Back()
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
		Node* node = new Node(v);

		// ��� ���� ����
		nodeCount++;

		// ù Push�� ���
		if (nodeCount == 1)
		{
			front = node;
			rear = node;
			return;
		}

		// ���ο� ��尡 ����Ű�� ��带 ����
		node->SetNextNode(rear);
		rear->SetPreNode(node);

		// rear�� ���ο� ���� ��ü
		rear = node;
	}
	void Pop()
	{
		if (Empty()) return;

		// ��� ���� ����
		nodeCount--;

		// front�� ����Ű�� �ִ� ���� front�� ��ü
		front = front->preNode;
	}
};

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ī��2

	LinkedListQueue linkedListQueue;

	int N; cin >> N;
	for (int i = 0; i < N; ++i)
	{
		// 1���� �־��� ������ 1���� ���´�
		linkedListQueue.Push(i + 1);
	}

	// ó������ 1���� ���� ��� �ٷ� ��ȯ �� �ٷ� ����
	if (linkedListQueue.Size() == 1)
	{
		cout << linkedListQueue.Front() << '\n';
		return 0;
	}

	while (true)
	{
		linkedListQueue.Pop();

		if (linkedListQueue.Size() == 1)
		{
			cout << linkedListQueue.Front() << '\n';
			break;
		}

		int front = linkedListQueue.Front();
		linkedListQueue.Pop();
		linkedListQueue.Push(front);
	}

	return 0;
}
