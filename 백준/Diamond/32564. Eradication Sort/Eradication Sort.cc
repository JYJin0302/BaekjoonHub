#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const ll inf = 1e13;
struct Line {
	ll a, b;
	ll get(ll x) { return a * x + b; }
};

struct Node {
	int l, r;  // child
	ll s, e;   // range
	Line line;
};

struct Li_Chao {
	vector<Node> tree;

	void init(ll s, ll e) { tree.push_back({-1, -1, s, e, {0, -inf}}); }

	void update(int node, Line v) {
		ll s = tree[node].s, e = tree[node].e;
		ll m = s + e >> 1;

		Line low = tree[node].line, high = v;
		if (low.get(s) > high.get(s)) swap(low, high);

		if (low.get(e) <= high.get(e)) {
			tree[node].line = high;
			return;
		}

		if (low.get(m) < high.get(m)) {
			tree[node].line = high;
			if (tree[node].r == -1) {
				tree[node].r = tree.size();
				tree.push_back({-1, -1, m + 1, e, {0, -inf}});
			}
			update(tree[node].r, low);
		} else {
			tree[node].line = low;
			if (tree[node].l == -1) {
				tree[node].l = tree.size();
				tree.push_back({-1, -1, s, m, {0, -inf}});
			}
			update(tree[node].l, high);
		}
	}

	ll query(int node, ll x) {
		if (node == -1) return -inf;
		ll s = tree[node].s, e = tree[node].e;
		ll m = s + e >> 1;
		if (x <= m) return max(tree[node].line.get(x), query(tree[node].l, x));
		else return max(tree[node].line.get(x), query(tree[node].r, x));
	}
} seg;

ll dp[1001010];
ll A[1001010];

void solve() {
	int n;
	cin >> n;

	seg.init(-1e12, 1e12);

	for (int i = 1; i <= n; i++) cin >> A[i];
	A[n+1] = 1001010;
	A[0] = -1;
	n += 2;

	vector<pair<ll, ll>> O(n);
	for(int i =0 ;i < n; i++) O[i] = mp(A[i], i);
	sort(all(O));

	seg.update(0, {0, 0});
	for (int f = 1; f < n; f++) {
		// get Ans
		auto[x,i] = O[f];
		dp[i] = -seg.query(0, i-1) + 1ll * (i - 1) * (i - 1);

		// update Line
		ll a = -2 * i;
		ll b = 1ll * i * i + dp[i];
		seg.update(0, {-a, -b});

		// cout << "NEw edg: " << a << ' '<< b << '\n';
		// cout << "Go upd: "<< x << ' '<< i << ' ' << dp[i] << '\n';

		// for(int j = 0;j <= n; j++) cout << seg.query(0, j) << ' ';
		// cout << '\n';
		// cout << '\n';

	}

	cout << dp[n - 1] << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
	return 0;
}