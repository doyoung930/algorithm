#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

// Q) map vs hash_map ������(unordered_map)
//
// map : Red-Black Tree
// - �߰� / Ž�� / ���� O(logN)
// 
// C# dictionary = C++ unordered_map
// 
// hash_map(unordered_map)
// - �߰� / Ž�� / ���� O(1)
//

// map 

void TestHash() {
	struct User {
		int userid = 0;

		string username;
	};

	vector<User> users;
	users.resize(1000);

	const int userid = 123456789;
	int key = (userid % 1000); // hash < ���� ��ȣ

	// 123456789�� ���� ���� ����
	users[key] = User{ 777, "aaa" };

	User& user = users[key];
	if (user.userid == userid) {

		string name = users[777].username;
		cout << name << endl;
	}

	// �浹 ���� - key ���� ��ħ
	// �浹�� �߻��� �ڸ��� ����ؼ� �ٸ� ���ڸ��� ã�Ƴ����� �ȴ�.
	// - ���� �����
	// - ���� �����
}
int main()
{
	TestHash();
}