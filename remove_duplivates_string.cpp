class Solution {
public:
	string removeDuplicateLetters(string s) {


		stack<char> st;

		unordered_map<char, int> m;


		for (auto x : s)m[x]++;


		int n = s.size();
		st.push(s[0]);
		m[s[0]]--;
		for (int i = 1; i < n; ++i) {

			if (st.top() >= s[i] and m[st.top()] > 0) {

				st.pop();

				st.push(s[i]);
				m[s[i]]--;

			}
			else
			{	st.push(s[i]);
				m[s[i]]--;
			}
		}
		string ans = "";


		while (!st.empty()) {

			ans += st.top();
			st.pop();

		}
		return ans;


	}
};