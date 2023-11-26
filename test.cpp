// //{ Driver Code Starts
// #include <bits/stdc++.h>
// using namespace std;

// // } Driver Code Ends
// class Solution
// {

// public:
//     vector<long long> findMissing(long long A[], long long B[],
//                                   int N, int M)
//     {
//         unordered_map<long long, long long> a, b;
//         vector<long long> ans;
//         for (long long i = 0; i < N; ++i)
//             a[A[i]]++;

//         for (int i = 0; i < M; ++i)
//             b[B[i]]++;
//         for (long long i = 0; i < N; ++i)
//         {
//             if (b[A[i]] == 0)
//                 ans.push_back(A[i]);
//         }
//         for (long long i = 0; i < M; ++i)
//         {
//             if (a[B[i]] == 0)
//                 ans.push_back(B[i]);
//         }
//         return ans;
//     }
// };

// //{ Driver Code Starts.

// int main()
// {

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         int m;
//         cin >> m;
//         long long a[n];
//         long long b[m];
//         for (int i = 0; i < n; i++)
//             cin >> a[i];
//         for (int i = 0; i < m; i++)
//             cin >> b[i];
//         vector<long long> ans;

//         Solution ob;
//         ans = ob.findMissing(a, b, n, m);
//         for (int i = 0; i < ans.size(); i++)
//             cout << ans[i] << " ";

//         cout << "\n";
//     }
//     return 0;
// }
// // } Driver Code Ends

#include<bits/stdc++.h>

using namespace std;
void inc(int n)
{
    if(n==0)
    return;
    inc(n-1);
    cout<<n<<" ";

}
void dic(int n)
{
    if(n==0)
    return;
    
    
cout<<n<<" ";

    dic(n-1);
  
    
}
int main()
{
    inc(5);
    cout<<endl;
    dic(5);
    return 0;
}