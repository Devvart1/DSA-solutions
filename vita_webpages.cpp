#include<bits/stdc++.h>

using namespace std;




int minClicks(unordered_map<int, vector<int>>& webPages, int startPage, int endPage) {
	if (startPage == endPage) {
		return 0;
	}

	queue<int> q;
	unordered_map<int, int> dist;

	q.push(startPage);
	dist[startPage] = 0;

	while (!q.empty()) {
		int curPage = q.front();
		q.pop();

		for (int linkedPage : webPages[curPage]) {
			if (linkedPage == endPage) {
				return dist[curPage] + 1;
			}
			if (dist.find(linkedPage) == dist.end()) {
				dist[linkedPage] = dist[curPage] + 1;
				q.push(linkedPage);
			}
		}
	}

	return -1;
}

int main() {

	int n;
	cin >> n;
	cin.ignore();
	unordered_map<int, vector<int>> webPages;

	for (int i = 1; i <= n; i++) {
		string l;
		getline(cin, l);
		istringstream iss(l);
		int linkedPage;

		while (iss >> linkedPage) {
			webPages[i].push_back(linkedPage);
		}
	}

	int startPage, endPage;
	cin >> startPage >> endPage;
	int ans = minClicks(webPages, startPage, endPage);

	cout << ans ;

	return 0;
}
