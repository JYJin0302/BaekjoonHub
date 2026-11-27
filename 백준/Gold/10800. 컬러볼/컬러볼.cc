#include <bits/stdc++.h>
using namespace std;

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	int n, a, b, c;
	cin >> n;

	vector<tuple<int, int, int>> ball;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		ball.push_back({ b, a , i});
	}

	sort(ball.begin(), ball.end());

	int tot = 0;
	vector<int> curr(n+1);
	vector<int> ans(n);
	vector<pair<int, int>> temp;

	int currsize = -1;
	int temptot = 0;
	for (int i = 0; i < n; i++) {
		tie(a, b, c) = ball[i];
		if (a != currsize) {
			currsize = a;
			tot += temptot;
			temptot = 0;
			for (auto k : temp) {
				int x, y;
				tie(x, y) = k;
				curr[x] += y;
			}
			temp.clear();
		}

		ans[c] = tot - curr[b];
		temptot += a;
		temp.push_back({ b, a });
	}

	for (int i : ans) cout << i << '\n';
}