#include <bits/stdc++.h>
using namespace std ;
int partition (int*arr, int s, int e)
{
	int i = e + 1;
	int pivot = arr[s];
	for (int j = e; j > s; --j)
	{
		if (arr[j] > pivot)
		{
			i--;
			swap(arr[i], arr[j]);
		}
	}
	i--;
	swap(arr[i], arr[s]);
	return i;
}
void quicksort(int *arr, int s, int e)
{	if (s < e)
	{
		int p = partition(arr, s, e);
		quicksort(arr, s, p - 1);
		quicksort(arr, p + 1, e);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif
	int n = 0;
	// cout << "Enter the size of the array " << endl;
	cin >> n;
	int*arr = new int[n + 1];
	// cout << "Enter elements" << endl;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	arr[n] = 1e7 + 7;

	quicksort(arr, 0, n - 1);
	cout << "Sorted array is" << endl;
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	delete[]arr;



	return 0;
}