
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif

   int t; cin >> t;
   while ( t--)
   {
      int n; cin >> n;
      //  int m;cin>>m;
      vector<int>v(n + 1);
      vector<int>pre(n + 1);
      for ( int i = 1; i < n + 1; i++)
      {
         cin >> v[i];// pre[i] = pre[i - 1] + v[i];
      }
      int ans = 1;
      int lo = 1, hi = n;

      while ( hi >= lo)
      {
         int mid = (lo + hi) / 2;
         cout << "?" << " ";
         cout << mid - lo + 1 << " ";
         int res = 0;
         for (int i = lo; i <= mid; i++) {
            cout << i << " ";
            res += v[i];
         }
         //cout<<endl;
         int x; cin >> x;
         //  = pre[mid] - pre[lo - 1];
         if (x > res) {

            ans = mid;
            hi = mid - 1;
         }
         else
         {
            lo = mid + 1;
         }

      }
      cout << "!" << " " << ans << endl;
   }

}