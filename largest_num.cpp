class Solution {
public:
	// string num_str(int num) {
	// 	string s = "";
	// 	int i = 0;
	// 	while (num) {
	// 		s += (char)num % (int)pow(10, i);
	// 		num /= 10;
	// 	}
	// 	cout << s;
	// 	reverse(s.begin(), s.end());
	// 	return s;
	// }

	bool comp(string &a, string &b) {

		if (a + b < b + a)return 0;
		return 1;
	}
	string largestNumber(vector<int>& nums) {
		vector<string> sort_num;

		for (auto x : nums) {
			sort_num.push_back(to_string(x));
		}
		sort(sort_num.begin(), sort_num.end(), comp);
		string ans = "";
		for (auto x : sort_num) {
			ans += x;
		}
		return ans;
	}
};