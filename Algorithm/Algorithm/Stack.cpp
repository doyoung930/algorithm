#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

// Stack (LIFO Last In First Out 후입 선출)
// 되돌리기 ( Ctrl + Z )

template<typename T, typename Container = vector<T>>
class Stack {
public:
	void push(const T& value) {
		_container.push_back(value);
	}
	void pop()
	{
		_container.pop_back();
	}
	T& top()
	{
		return _container.back();
	}
	bool empty() { return _container.empty(); }
	int size() { return _container.size(); }

private:
	//vector<T> _container;
	//list<T> _container;
	Container _container;
};

int main()
{
	Stack<int, list<int> > s;

	// 삽입
	s.push(1);
	s.push(2);
	s.push(3);

	//최상위 원소
	while (s.empty() == false) {
		int data = s.top();

		// 최상위 원소 삭제
		s.pop();

		cout << data << endl;
	}

	int size = s.size();
}
