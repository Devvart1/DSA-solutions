#include <bits/stdc++.h>

using namespace std;

int count_inv(int *a, int n)
{

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (a[j] < a[i])
            {
                cout << "(" << a[i] << "," << a[j] << ")\t";
                ans++;
            }
        }
    }
    return ans;
}
int merge(int *a, int s, int e)
{
    int mid = (e + s) / 2;
    int i = s;
    int j = mid + 1;
    int k = s;
    int temp[1000];
    int cnt = 0;
    while (i <= mid && j <= e)
    {
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
            cnt += mid - i + 1;
        }
    }
    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= e)
        temp[k++] = a[j++];

    for (int i = s; i <= e; ++i)
    {
        a[i] = temp[i];
    }
    return cnt;
}
int inv_count(int *a, int s, int e)
{
    if (s >= e)
        return 0;

    int mid = (e + s) / 2;
    int x = inv_count(a, s, mid);
    int y = inv_count(a, mid + 1, e);

    int z = merge(a, s, e);
    return x + y + z;
}
int main()
{

    int n;
    // cin>>n;
    int a[] = {1, 5, 2, 6, 3, 0};

    // for(int i=0;i<n;++i)
    // {
    //     cin>>a[i];

    // }
    cout << inv_count(a, 0, 6);
}