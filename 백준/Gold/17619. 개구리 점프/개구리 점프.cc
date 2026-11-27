#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q, a, b, y, t;
	cin >> n >> q;

	vector<tuple<int, int, int>> A;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> y;
		A.push_back({ a, b , i});
	}

	sort(A.begin(), A.end());

	vector<int> conn(n);
	int cnt = 1;
	int l, r;
	tie(l, r, t) = A[0];
	conn[t] = 1;

	for (int i = 0; i < n; i++) {
		tie(a, b, t) = A[i];
		if (a > r) {
			cnt++;
			l = a, r = b;
		}
		else {
			r = max(r, b);
		}
		conn[t] = cnt;
	}

	while (q--) {
		cin >> a >> b;
		if (conn[a-1] == conn[b-1]) cout << "1\n";
		else cout << "0\n";
	}

}