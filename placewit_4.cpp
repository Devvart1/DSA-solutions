#include <iostream>
#include <string>

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	std::string s = "A,B,C,";
	std::string substr = ",";
	std:: cin >> s;
	std:: cin >> substr;
	int ans = 0;

	int index = 0;
	while ((index = s.find(substr, index)) != std::string::npos) {
		ans++;
		index += substr.length();
	}
	std:: cout << ans;
	return 0;
}