#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ���� ���� �ٹ̱�

	/// O(N^2)�� �ð����⵵�� ���� ���
	// �Է� ������ N�� �ִ� 80,000�̹Ƿ�
	// 1�ʿ� ���� 6,400,000,000���̴� �̴� 64������� ���� ���ڸ���
	// �ð� �ʰ� �߻�

	/*
	int heightArr[100001];

	int N; cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> heightArr[i];
	}

	// 64����� �� �� �����Ƿ� int�� �ƴ� long long�� ����Ѵ�
	long long count = 0;

	for (int origin = 0; origin < N; ++origin)
	{
		for (int target = origin + 1; target < N; ++target)
		{
			if (heightArr[origin] > heightArr[target])
				count++;
			else
				break;
		}
	}

	cout << count << '\n';
	*/

	/// monotone stack�̶�?
	// -> ���� ���θ� �������� �Ǵ� ������������ ���� ���ִ� �˰���
	// https ://justicehui.github.io/medium-algorithm/2019/01/01/monotoneStack/
	// -> �ش� �˰������� O(N)�� �ð� ���⵵ ������ �ٿ��ִ� ������ ��ũ��
	// �� �ǹ� �Ѱǹ��� �߰��Ҷ����� stack �� �ڱ⺸�� ū��鸸 ���α�
	// ->���⼭ monotone stack ���

	stack<int> myStack;

	// �ڷ��� �������� �ִ�� 64����� ���� ���� �ִµ� int�� �ǰڳ�
	long long count = 0;

	int N; cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int h; cin >> h;
		/// �ٽ� ���� montone stack ���
		// ���̰� �ڽź��� ���ų� ���� �������� ������
		// cf) myStack.empty()�� ���� ��� ������ empty()�� top()�Լ����� ���� �ʰ� while�� ����ȴ�
		// ���ʿ� �ڱ⺸�� ���̰� ū �����ۿ� ���� �ʴµ�,
		// �׷��� �������� �ڽ��� ������ �� �� �ִٴ� ���̴�
		// ���⼭ ����Ʈ�� �ڽź��� ���� ������ ������ �����ϸ鼭 �ڿ������� ���̰� ū �͸� ����� �Ǹ�
		// ** �ᱹ�� ���Ӱ� ������ ������ ���� ��� �����鿡�� ��ġ��ŷ �� �� �ִٴ� ���̴�. **
		//
		// ���ÿ� �����ִ� ����(����) ������ ���� ���� ���� �ִ� �ǹ� ���̴�
		while (!myStack.empty() && myStack.top() <= h)
		{
			myStack.pop();
		}
		count += myStack.size();
		myStack.push(h);
	}

	cout << count << '\n';

	/// ������ Ȱ���ؼ� ������ �ذ��ϴ� ����
	
	// ���� ������ ����� ũ��. �ٵ� ���þ� ������ ���� ��, { 10, 3, 7, 4 } �������� ���̰� 7�� �ǹ��� 3���� ���ų� ũ�Ƿ�, 3�� ���ÿ��� ���Ű� �Ǹ� 7�� ���ÿ� �־�����. �׸��� ���ÿ��� { 10, 7 } �� �����ִ�.

	// ** �Ϲ������� �������� ��, ���� ���̰� 4�� �ǹ��� ���忡�� ������ ����, ���̰� 3�� �ǹ��� ���̰� 7�� �ǹ��� ���� �������Ƿ�, 3 �ǹ��� 4 �ǹ��� �翬�� �������� �ʴ� �ǹ��̴�. **

		// �׷��� ������ڸ�, ������ ���� ��Ȳ���� ������ ������ ���� �� �ִٰ� �����ߴ�.

		// ���� �� ������ ���� ���� ���� �ʿ� ������ ��(ex.���� 7�� ���� ���� 3 �ǹ��� �ʿ� ������)
		// ������ �� ���� ���θ� ����ȴٰ� ����� ��(������ Ư�� LIFO)

	return 0;
}
