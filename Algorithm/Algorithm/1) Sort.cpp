#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

// ����

// 1) ���� ���� (Bubble sort)
void BubbleSort(vector<int>& v)
{

	// (N - 1) + ( N - 2) + ... + 2 + 1
	// ���������� �� = N * ( N - 1 ) / 2
	// O(N^2)

	const int n = (int)v.size();

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < (n - 1 - i); j++)
		{
			if (v[j] > v[j + 1]) {
				int temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
}



// 2) ���� ���� (Selection Sort)
void SelectionSort(vector<int>& v)
{

	// (N - 1) + ( N - 2) + ... + 2 + 1
	// ���������� �� = N * ( N - 1 ) / 2
	// O(N^2)

	const int n = (int)v.size();

	for (int i = 0; i < n - 1; i++) {
		
		int bestIdx = i;

		for (int j = i + 1; j < n; j++) {
			if (v[j] < v[bestIdx])
				bestIdx = j;
		}

		// ��ȯ
		int temp = v[i];
		v[i] = v[bestIdx];
		v[bestIdx] = temp;
	}
}

// 3) ���� ���� (Insertion Sort)
// ��κ��� �����Ͱ� ���ĵ� �����̸� ȿ���� ���� ����
void InsertionSort(vector<int>& v) {
	const int n = (int)v.size();

	for (int i = 1; i < n; i++) {
		int insertData = v[i];

		int j;

		for (j = i - 1; j >= 0; j--) {
			if (v[j] > insertData)
				v[j + 1] = v[j];
			else
				break;

		}

		v[j + 1] = insertData;
	}
}

int main()
{
	vector<int> v{ 1,5,3,4,2 };
	//BubbleSort(v);
	//SelectionSort(v);
	InsertionSort(v);
	// cout << v << endl;
}