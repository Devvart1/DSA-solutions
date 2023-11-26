
class Solution {
public:
	double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
		int n = wage.size();

		vector<pair<double, int>> ratioQ(n);

		for (int i = 0; i < n; ++i) {
			ratioQ[i] = {wage[i] / quality, quality[i]};
		}

		sort(ratioQ.begin(), ratioQ.end());

		priority_queue<int> pq;
		int sum = 0;
		for (int i = 0; i < k - 1; ++i) {
			pq.push(ratioQ[i].second);
			sum += ratioQ[i].second;

		}


		int mincost = ratioQ[i].first[k - 1] * sum;
		for (int i = k; i < n; ++i) {



			if (!pq.empty() and pq.top() > ratioQ[i].second) {
				sum -= pq.top();
				pq.pop();

				pq.push(ratioQ[i].second);
				sum += ratioQ[i].second;

			}
			mincost = min(ratioQ[i].first * sum, mincost);
		}
		return mincost;
	}
};