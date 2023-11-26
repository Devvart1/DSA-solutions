#include <bits/stdc++.h>
using namespace std;

int search(vector<long long>&A, int start, int end, long long req) {
  int mid = (start + end) / 2;
  int ans = A.size() - 1;
  while (start <= end) {
    if (A[mid] >= req) {
      ans = min(ans, mid);
      end = mid - 1;
      mid = (start + end) / 2;
    }
    else {
      start = mid + 1;
      mid = (start + end) / 2;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // your code goes here
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<long long> A(n);

    for (int i = 0; i < n; ++i) {
      cin >> A[i];
    }
    sort(A.begin(), A.end());

    long long ans = 1e18;
    long long req, cur, score;

    for (int i = 0; i < (n - 2); ++i) {
      for (int j = i + 1; j < (n - 1); ++j) {
        req = 2ll * A[j] - A[i];
        // cout<<i<<" "<<j<<" -- "<<req<<" ";
        int idx = search(A, j + 1, n - 1, req);
        cur = A[idx];
        score = abs(cur - req);
        ans = min(ans, score);
        if (idx > (j + 1)) {
          idx--;
        }
        //  cout<<idx<<" -- ";
        cur = A[idx];
        // cout<<cur<<"\n";
        score = abs(cur - req);
        ans = min(ans, score);
      }
    }

    cout << ans << "\n";
  }
  return 0;
}