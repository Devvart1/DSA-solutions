#include <bits/stdc++.h>

using namespace std;
void merge(int *a, int s, int n)
{
    int i = s;

    int mid = (s + n) / 2;
    int j = mid + 1;
    int temp[100];
    int k = s;
    while (s <= mid && j <= n)
    {
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= n)
        temp[k++] = a[j++];

    for (int i = s; i <= n; ++i)
    {
        a[i] = temp[i];
    }
}
void merge_sort(int *a, int s, int n)
{
    if (s >= n)
        return;
    
    int mid = (s + n) / 2;
    merge_sort(a, s, mid);
 //   merge(a, s, n);
    merge_sort(a, mid + 1, n);
    merge(a, s, n);
}
int main()
{
    int n = 10;
    // cin>>n;
    // int a[n];
    // for (int i = 0; i < n; ++i)
    // {
    //     cin >> a[i];
    // }
    n=6;
  int a[] = {1, 5, 2, 6, 3, 0};
    merge_sort(a, 0, n - 1);
    cout<<"\n sorted \n";
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] <<endl;
    }
    return 0;
}