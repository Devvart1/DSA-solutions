class Solution {
public:
	int candy(vector<int>& ratings) {

		//	int ans = 0;
		int n = ratings.size();

		vector<int> left(n, 1), right(n, 1);

		for (int i = 0; i < n - 1; ++i) {
			if (ratings[i] < ratings[i + 1])
				left[i]++;

		}

		for (int i = n - 1; i > 0; ++i) {
			if (ratings[i - 1] > ratings[i])
				right[i]++;

		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			ans += max(right[i], left[i]);
		}
	}

};