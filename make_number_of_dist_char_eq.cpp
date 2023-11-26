class Solution {
public:
	bool isItPossible(string word1, string word2) {
		unordered_map<char, int> m1, m2;

		for (auto x : word1)m1[x - 'a']++;

		for (auto x : word2)m2[x - 'a']++;
//  if(abs((int)m1.size() - (int)m2.size())>1)
//  return 0;
		if (m1.size() == m2.size())return 1;

		int n = word1.size();
		int m = word2.size();

		for (int i = 0; i < 26; ++i) {

			for (int j = 0; j < 26; ++j) {

				if (m1[i] > 0 and m2[j] > 0) {

					m1[i]--;
					if (m[i] == 0)
						m1.erase(i);
					m2[i]++;
					m1[j]++;


					m2[j]--;
					if (m2[j] == 0)
						m2.erase(j);
// 		int uniq1=0;
//         int uniq2=0;
//        for (int k = 0; k< 26; ++k)if(m1[k]>0)uniq1++;

//        for (int k = 0; k< 26; ++k)if(m2[k]>0)uniq2++;
//  if(uniq1==uniq2)
//  return 1;
					if (m1.size() == m2.size())return 1;

					m1[i]++;
					m2[i]--;
					m1[j]--;
					m2[j]++;
				}
			}
		}
		return 0;

	}
};