#include <bits/stdc++.h>
using namespace std;

int topArr[500001];
stack<pair<int, int>> topStack;
stack<int> topStack2;

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ž

	/// �迭�� ����
	// 0 1 2 3 4�� ���鼭
	// 3�� ��� 2, 1, 0�� ���� ��鼭 ������ �����ϰ� �ش� ž�� ��ȣ�� �Է�
	// �̷������� �ϸ� �ɰŰ�����?

	// ž�� ���̰� 100,000,000
	// ž�� ���� 500,000
	// �̶�� �����Ѵٸ�
	//
	// O(N^2)�� �ð����⵵�� �����ϸ�
	// 500,000 * 500,000�� 250,000,000,000 (�� õ���)
	// �ð� ������ 1.5���̱� ������
	// ��ǻ�Ͱ� �ð� �ȿ� �� �� �ִ� ����Ƚ���� �� 1���
	// ���� O(N^2)�� �ð����⵵�� �����ϸ� �ð��ʰ��� �� ���̴�

	/// �������� ����
	// ���� ž���� ���ÿ� ���δ�
	// ���������� ���� ��ܿ� �ִ� ���� ������ ž�� ���̴�
	// ���� ���� ����� ž�� �������� �ϳ� �ϳ� ��Ҹ� �����ذ��� (�������� ��ȣ�� �۽�)
	// ������ �� �ִ� ž�� Ž���Ѵ�
	// �̷��� ������ ��� ž�� ���Ͽ� �ݺ� �۾��Ѵ�
	//
	// �ٵ� �̷��� �������� �����ص� O(N^2)�� ���� ���������̴�
	// �ֳ��ϸ� N���� ž ���̸� ��ȸ�ϸ鼭
	// (N - 1), (N - 2), ... ���� ž�� ���ϴϱ�
	// �迭�� �����ϴ� �Ͱ� ��ǻ� ���� �ƶ��̴�.
	//
	// ���� ���� ȹ������ ����� �ʿ��ϴ�

	/*
	int N; cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int height; cin >> height;
		topStack2.push(height);	// N
	}

	vector<int> result2(topStack2.size(), 0);

	// ��� ž�� ��ȸ�Ѵ�
	while (!topStack2.empty())
	{
		// ó�� �˻��� ž�� ����
		int topHeight = topStack2.top();

		// �ش� ž�� ������ ������ ž�� ���� ��ȣ �߻�
		topStack2.pop();
		stack<int> tempTopStack = topStack2;

		// �������� �ִ� ž�� ���� �ݺ��ؼ� ��ȣ�� ������
		while (!tempTopStack.empty())
		{
			int targetTopNumber = tempTopStack.size();
			int tartgetTopHeight = tempTopStack.top();

			// ��ȣ�� �����ϴ� ���, �ش� ���̸� �Է��ϰ� ���� ž�� Ž���Ѵ�
			if (tartgetTopHeight >= topHeight)
			{
				result2[topStack2.size()] = targetTopNumber;
				break;
			}

			tempTopStack.pop();
		}
	}

	for (auto v : result2)
	{
		cout << v << ' ';
	}

	cout << '\n';
	*/

	/// O(N)�� �ð����⵵�� ž�� ���̸� ���ϴ� ���
	// ž�� ���̴� ���ʿ������� �־�����
	// 6 9 5 7 4 �̷�������
	// �׷��� �������� 6�� �־�����, 9�� �־�����, 5�� �־����� �̷��� ���� �ӿ���
	// ���Ӱ� �߰��Ǵ� ž�� ���̰� �ְ� ���̷� ���ŵȴٸ� ������ ž�� ������ �ȴٴ� ����� �߰��� �� �ִ�

	// �Ʒ� �ڵ�� �� �ڵ尡 �ƴ϶�
	// ���ͳݿ��� �ٸ� ����� �ۼ��� �ڵ��̴�
	// ������ �������� ���� ����ѵ�, �̷��� �ڵ� �ۼ��� ���� ����߰ڴ�
	// ��� �̷��� ����ϰ� ��������
	// ���� ���ص��� �����ΰ�?
	// �� ���� ������ ������ ������� ������?
	// �� �ڵ�� �ణ �߸ŷ� �ϳ��ϳ� ���� ���߸鼭 ������ �����ε�
	// ������ �� ���

	// 1. ��� ž�� ������ �۽ű�� ������ ��ȣ�� ��ǥ��� �����ϰ� ���� ������ ���� �������� �߻� (�� �������� �߻��Ѵ� ������ Restricted ���� �̿�)
	// 2. ���� ���� ������ �� �ϳ��� ž������ ������ �����ϴ�. (���� �����͸� �����Ͽ�, ���� Ƚ���� ���̴� ���)

	int N; cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int height; cin >> height;

		// �ٷ� �ݺ����� ���������±���
		while(!topStack.empty())
		{
			// ����ž �߰�
			if (topStack.top().second >= height)
			{
				cout << topStack.top().first << ' ';
				break;
			}

			// ����ž�� �߰��ϱ� ������ ����ؼ� ����
			topStack.pop();
		}

		// ����ž�� ���� ���
		if(topStack.empty())
		{
			cout << 0 << ' ';
		}

		// ���ο� ����ž ���
		topStack.push(make_pair(i + 1, height));
	}

	/*
	 *
	 *	ó�� ����� �� �ڵ�
	 *	�ڵ��� ������ �� ������ ���� �� �� �ִ�
	 *
	int Num; cin >> Num;
	vector<int> result(Num);
	for (int i = 0; i < Num; ++i)
	{
		int height; cin >> height;

		if (topStack.empty())
		{
			topStack.push(make_pair(i + 1, height));
			result[i] = 0;
			continue;
		}

		if (!topStack.empty() && topStack.top().second <= height)
		{
			while (!topStack.empty())
			{
				topStack.pop();

				if (topStack.empty())
				{
					result[i] = 0;
					break;
				}

				if (topStack.top().second >= height)
				{
					result[i] = topStack.top().first;
					break;
				}
			}
		}
		else if (!topStack.empty() && topStack.top().second >= height)
		{
			result[i] = topStack.top().first;
		}

		topStack.push(make_pair(i + 1, height));
	}

	for (auto v : result)
	{
		cout << v << ' ';
	}
	*/

	return 0;
}
