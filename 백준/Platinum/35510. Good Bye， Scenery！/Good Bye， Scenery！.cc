#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int tn;
int fw[303030];
void update(int ix, int val) {
	while (ix <= tn + 30) {
		fw[ix] += val;
		ix += ix & -ix;
	}
}

int getS(int ix) {
	int res = 0;
	while (ix) {
		res += fw[ix];
		ix -= ix & -ix;
	}
	return res;
}

void solve() {
	int n;
	cin >> n;
	vector<int> A(n);
	for (auto& i : A) cin >> i;

	tn = n;
	for (int i = 1; i <= tn + 30; i++) fw[i] = 0;

	vector<pair<int, int>> B(n);
	for (int i = 0; i < n; i++) B[i] = mp(A[i], i + 1);
	sort(all(B));

	int ix = n - 1;
	priority_queue<int> pq;  // position

	ll ans = 0;

	for (int i = n; i >= 1; i--) {
		while (ix >= 0 && B[ix].x >= i) {
			pq.push(B[ix].y);
			ix--;
		}

		if (pq.empty()) {
			cout << "-1\n";
			return;
		}

		int x = pq.top();
		pq.pop();

		int pos = x - getS(x);
		ans += i - pos;
		update(x, 1);
	}

	cout << ans << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	cin >> t;
	while (t--) { solve(); }
	return 0;
}