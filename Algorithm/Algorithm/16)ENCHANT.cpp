#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;
// ENCHANT
//
// +0 집행검
// 무기 강화 주문서 => +1 / +2 / +3 중 하나

// +9 집행검 뜨는 경우의 수는?
// ex) +1 +2 +3 +4 ... +9
// ex) +3 +6 +9
// ex) +1 +3 +4

int N;
int cache[100];
// [+num]에서 시작해서 [+N] 까지 가는 경우의 수

int Enchant(int num)
{
	// 기저 사항
	if (num > N)
		return 0;
	if (num == N)
		return 1;

	// 캐시 확인
	int& ret = cache[num];
	if (ret != -1)
		return ret;


	// 적용
	return ret = Enchant(num + 1) + Enchant(num + 2) + Enchant(num + 3);

}

int main()
{
	N = 20;

	memset(cache, -1, sizeof(cache));

	int ret = Enchant(0);
	cout << ret << endl;
}

