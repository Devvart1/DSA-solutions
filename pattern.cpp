//lc 890

vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
	bool match = true;
	vector<string> ans;
	for (int i = 0; i < words.size(); ++i) {

		map<char, char> m1, m2;

		for (int j = 0; j < words[i].size(); ++j) {

			auto ch1 = m1.find(pattern[j]);
			if (ch1 == m1.end()) {
				m1.insert({pattern[j], words[i][j]});
			}
			else {

				if (ch1->second != words[i][j]) {
					match = false;
					break;
				}
			}
			auto ch2 = m2.find(words[i][j]);
			if (ch2 == m2.end()) {
				m2.insert({words[i][j], pattern[j]});
			}
			else {

				if (ch2->second != pattern[j]) {
					match = false;
					break;
				}
			}
		}
		if (match) {
			ans.push_back(words[i]);
		}
	}
	return ans;
}
