#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int g;
	cin >> g;

	vector<int> Ans;
	int o = 1, n = 2;
	while (o < n) {
		if (n * n - o * o < g) {
			n++;
		}
		else if (n * n - o * o == g) {
			Ans.push_back(n);
			n++;
			o++;
		}
		else {
			o++;
		}
	}

	if (Ans.size() == 0) cout << -1;
	else {
		for (int i : Ans) cout << i << '\n';
	}
}