#include <iostream>
#include <vector>
#include <list>
using namespace std;


//int main()
//{
//
//	list<int> li;
//	list<int>::iterator eraselt;
//	for (int i = 0; i < 10; i++)
//	{
//		if (i == 5)
//		{
//			li.insert(li.end(), i);
//		}
//		li.push_back(i);
//	}
//	for (list<int>::iterator it = li.begin(); it != li.end(); it++)
//	{
//		cout << (*it) << endl;
//	}
//}

int main()
{
	vector<int> v;
	for (int i = 0; i < 100; i++) {
		v.push_back(i);
		cout << v.size() << " " << v.capacity() << endl;
	}

	v.clear();
	cout << v.size() << " " << v.capacity() << endl;
}
