#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;
#include <thread>
#include <windows.h>

// 오늘의 주제 : 동적 계획법 (DP)

// 메모이제이션 (memoization)
int cache[50][50];

int combination(int n, int r)
{
	// 기저 사례
	if (r == 0 || n == r)
		return 1;

	// 이미 답을 구한 적 있으면 바로 반환
	int& ret = cache[n][r];
	if (ret != -1)
		return ret;

	// 새로 답을 구해서 캐시에 저장
	return ret = combination(n - 1, r - 1) + combination(n - 1, r);
}

int main()
{
	::memset(cache, -1, sizeof(cache));

	__int64 start = GetTickCount64();

	int lotto = combination(45, 6);

	__int64 end = GetTickCount64();

	cout << end - start << " ms" << endl;
}