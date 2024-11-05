#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

template<typename T, typename Container = vector<T>, typename Predicate = less<T>>

class PriorityQueue
{
public:
	void push(const T& data)
	{
		// 우선 힙 구조부터 맞춰준다.
		_heap.push_back(data);

		// 도장 깨기 시작
		int now = static_cast<int>(_heap.size()) - 1;

		// 루트 노드 까지
		while (now > 0)
		{
			// 부모 노드의 데이터와 비교해서 더 작으면 패배
			int next = (now - 1) / 2;
			/*if (_heap[now] < _heap[next])
				break;*/
			if (_predicate(_heap[now], _heap[next]))
				break;

			// 데이터 교체
			::swap(_heap[now], _heap[next]);
			now = next;
		}
	}

	void pop()
	{
		_heap[0] = _heap.back();
		_heap.pop_back();

		int now = 0;

		while (true)
		{
			int left = 2 * now + 1;
			int right = 2 * now + 2;

			// 리프에 도달한 경우
			if (left >= _heap.size())
				break;

			int next = now;

			// 왼쪽과 비교
			if (_predicate(_heap[next] , _heap[left]))
				next = left;

			// 둘 중 승자를 오른쪽과 비교
			if (right < (int)_heap.size() && _predicate( _heap[next] , _heap[right]))
				next = right;

			// 왼쪽/오른쪽 둘 다 현재 값보다 작으면 종료
			if (next == now)
				break;

			::swap(_heap[now], _heap[next]);
			now = next;
		}
	}

	T& top()
	{
		return _heap[0];
	}

	bool empty()
	{
		return _heap.empty();
	}
private:
	Container _heap = {};
	Predicate _predicate = {};
};

int main()
{
	PriorityQueue<int, vector<int>, greater<int>> pq;

	pq.push(100);
	pq.push(300);
	pq.push(200);
	pq.push(500);
	pq.push(400);

	while (pq.empty() == false)
	{
		int value = pq.top();
		pq.pop();

		cout << value << endl;
	}
}