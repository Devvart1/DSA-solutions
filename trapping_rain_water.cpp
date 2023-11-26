// class Solution {
// public:
// 	int trap(vector<int>& height) {




// 		int n = height.size();
// 		        vector<int> leftMax(n, 0);
// 		vector<int> rightMax(n, 0);

// 		leftMax[0] = height[0];
// 		rightMax[n - 1] = height[n - 1];
// 		for (int i = 1; i < height.size(); ++i)
// 		{
// 			leftMax[i] = max(leftMax[i - 1], height[i]);
// 		}
// 		for (int i = n - 2; i >= 0; ++i)
// 		{
// 			rightMax[i] = max(rightMax[i + 1], height[i]);
// 		}

// 		int ans = 0;

// 		for (int i = 1; i < height.size(); ++i)
// 		{
// 			ans += max({0, min(leftMax[i], rightMax[i]) - height[i]});
// 		}
// 		return ans;
// 	}
// };

class Solution {
public:
	int trap(vector<int>& height) {
		int l, r, ans, n, l_max, r_max;

		l =   ans = l_max = r_max = 0;
		r = n = height.size() - 1;

		while (l < r) {


			if (height[l] <= height[r]) {
				if (height[l] > l_max)
				{
					l_max = height[l];
					l++;
				}
				else {
					ans += l_max - height[l];
				}
				l++;
			}
			else if (height[r] <= height[l]) {
				if (height[r] > r_max)
				{	r_max = height[r];

				}
				else {
					ans += r_max - height[r];
				}
				r--;

			}
		}

		return ans;
	}
};