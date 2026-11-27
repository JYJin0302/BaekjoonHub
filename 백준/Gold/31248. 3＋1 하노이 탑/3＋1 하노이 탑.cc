#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

vector<pair<char, char>> ans;
char N[4] = { 'A', 'B', 'C', 'D' };
void go(int cnt, int p1, int p2, int p3) {
	if (cnt == 0) {
		return;
	}
	go(cnt-1, p1, p3, p2);
	ans.push_back(mp(N[p1], N[p2]));
	go(cnt - 1, p3, p2, p1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int p1 = 0, p2 = 1, p3 = 2;
	while (n >= 3) {
		go(n - 2, p1, p2, p3);
		ans.push_back(mp(N[p1], N[p3]));
		ans.push_back(mp(N[p1],N[3] ));
		ans.push_back(mp(N[p3],N[3] ));
		swap(p1, p2);
		n -= 2;
	}

	if (n == 2) {
		ans.push_back(mp(N[p1], N[p3]));
		ans.push_back(mp(N[p1], N[3]));
		ans.push_back(mp(N[p3], N[3]));
	}
	else {
		ans.push_back(mp(N[p1] ,N[3]));
	}

	cout << ans.size() << '\n';
	for (auto f : ans) cout << f.first << ' ' << f.second << '\n';
}