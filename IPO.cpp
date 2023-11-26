class Solution {
public:



	static bool comp(vector<int> &a, vector<int>&b) {
		return a[0] > b[0];
	}
	int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

		vector<pair<int, int>> pro_cap, cap_pro;
		int n = profits.size();
		for (int i = 0; i < n; ++i) {
			pro_cap.push_back({profits[i], capital[i]});
		}
		for (int i = 0; i < n; ++i) {
			cap_pro.push_back({capital[i], i});
		}
		sort(pro_cap.rbegin(), pro_cap.rend());

		int i = 0;
		if (k > n)
			k = n;
		vector<int> vis(n, 0);

		for (int j = 0; j < k; ++j) {
			// auto project = lower_bound(pro_cap.begin(), pro_cap.end(), w);
			for ( i = 0; i < n; ++i) {
				// cout<<pro_cap[i].first<<" "<<pro_cap[i].second<<endl;
				if (pro_cap[i].second <= w and vis[i] == 0) {
					vis[i] = 1;
					w += pro_cap[i].first;
//cout<<w<<endl;
					break;

				}

			}
			//  cout<<w<<endl;
		}
		//cout<<" f "<<w;
		return w;
	}

	int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {


		int n = profits.size();

		vector<bool> vis(n, 0);

		priority_queue<int> pro_pq, cap_pq;


		return w;

	}

};

