#include <bits/stdc++.h>
using namespace std;

class ArrayQueue
{
public:
	// 스택 메모리 1MB는
	// 2^20 byte / 4 byte
	// 262,144개 선언할 수 있다
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
		// 노드 생성
		Node* node = new Node(v);

		// 노드 개수 증가
		nodeCount++;

		// 첫 Push인 경우
		if (nodeCount == 1)
		{
			front = node;
			rear = node;
			return;
		}

		// 새로운 노드가 가리키는 노드를 설정
		node->SetNextNode(rear);
		rear->SetPreNode(node);

		// rear를 새로운 노드로 대체
		rear = node;
	}
	void Pop()
	{
		if (Empty()) return;

		// 노드 개수 감소
		nodeCount--;

		// front를 가리키고 있던 노드로 front를 대체
		front = front->preNode;
	}
};

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 카드2

	LinkedListQueue linkedListQueue;

	int N; cin >> N;
	for (int i = 0; i < N; ++i)
	{
		// 1부터 넣었기 때문에 1부터 나온다
		linkedListQueue.Push(i + 1);
	}

	// 처음부터 1개만 넣은 경우 바로 반환 후 바로 종료
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
