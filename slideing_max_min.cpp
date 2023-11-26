class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> nextGreater(n, 0);
        int maxx = n - 1;


        stack<int> st;
        st.push(0);
        int i = 1;
        while (i < n) {
            while (nums[st.top()] < nums[i] and !st.empty()) {
                nextGreater[st.top()] = i;
                st.pop();
            }
            st.push(nums[i]);
            i++;
        }
        nextGreater[n - 1] = n - 1;

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (nextGreater[i] - i >= k) {
                ans.push_back(nums[i]);
            } else {
                ans.push_back(nums[nextGreater[i]]);
            }
        }
        return ans;

    }
};