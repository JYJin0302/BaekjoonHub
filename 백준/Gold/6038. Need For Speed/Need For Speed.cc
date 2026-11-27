#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct T {
	ll f, m;
	int idx;

	bool operator<(T& o) {
		if(f * o.m != m * o.f) return f * o.m < m* o.f;
		return m > o.m;
	}
};

void solve() {

	ll F, M, n;
	cin >> F >> M >> n;

	vector<T> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i].f >> A[i].m;
		A[i].idx = i + 1;
	}

	sort(A.rbegin(), A.rend());

	vector<int> ans;
	for (int i = 0; i < n;i++) {
		T tmp = A[i];

		if (M * tmp.f > F * tmp.m) {
			F += tmp.f;
			M += tmp.m;
			ans.push_back(tmp.idx);
		}
	}

	sort(ans.begin(), ans.end());

	if (ans.size() == 0) cout << "NONE";
	else for (auto i : ans) cout << i << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
}