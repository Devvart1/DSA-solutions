#include <bits/stdc++.h>
using namespace std;
int partition(int *a, int s, int e)
{
    int i = s - 1;
    int j = s;
    int pivot = a[e];

    for (; j < e;)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
        j++;
    }
    swap(a[i + 1], a[e]);
    return i + 1;
}
void quicksort(int *a, int s, int e)
{
    if (s >= e)
        return;

    int p = partition(a, s, e);
    quicksort(a, s, p - 1);
    quicksort(a, p + 1, e);
}

int main()
{

    int n;

    int a[] = {1, 5, 3, 2, 16, 7, 4, 9, 1};

    n = 9;
    quicksort(a, 0, n);
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
}