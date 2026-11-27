#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int sz = 1<<17;
vector<int> Mst[sz*2];

void init(int n) {
	if (n >= sz) return;

	init(n * 2), init(n * 2 + 1);
	Mst[n].resize(Mst[n * 2].size() + Mst[n * 2 + 1].size());
	merge(Mst[n * 2].begin(), Mst[n * 2].end(), Mst[n * 2 + 1].begin(), Mst[n * 2 + 1].end(), Mst[n].begin());
}

int solve(int l, int r, int n, int sl, int sr, int k) {
	if (l > sr || r < sl) return 0;
	if (l >= sl && r <= sr) {
		int ix = upper_bound(Mst[n].begin(), Mst[n].end(), k) - Mst[n].begin();
		return Mst[n].size() - ix;
	}

	int m = (l + r) >> 1;
	return solve(l, m, n * 2, sl, sr, k) + solve(m + 1, r, n * 2 + 1, sl, sr, k);
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int>A(n);
	for (auto& i : A) cin >> i;

	for (int i = 0; i < n; i++) {
		Mst[i + sz].push_back(A[i]);
	}

	init(1);
    
    int pv = 0;
	int q;
	cin >> q;
	while (q--) {
		int a, b, k;
		cin >> a >> b >> k;
        a ^= pv;
        b ^= pv;
        k ^= pv;
		a--, b--;
		pv = solve(0, sz - 1, 1, a, b, k);
        cout << pv << '\n';
	}

}