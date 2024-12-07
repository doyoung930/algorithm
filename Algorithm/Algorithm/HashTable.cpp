#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

// Q) map vs hash_map 차이점(unordered_map)
//
// map : Red-Black Tree
// - 추가 / 탐색 / 삭제 O(logN)
// 
// C# dictionary = C++ unordered_map
// 
// hash_map(unordered_map)
// - 추가 / 탐색 / 삭제 O(1)
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
	int key = (userid % 1000); // hash < 고유 번호

	// 123456789번 유저 정보 세팅
	users[key] = User{ 777, "aaa" };

	User& user = users[key];
	if (user.userid == userid) {

		string name = users[777].username;
		cout << name << endl;
	}

	// 충돌 문제 - key 값이 겹침
	// 충돌이 발생한 자리를 대신해서 다른 빈자리를 찾아나서면 된다.
	// - 선형 조사법
	// - 이차 조사법
}
int main()
{
	TestHash();
}