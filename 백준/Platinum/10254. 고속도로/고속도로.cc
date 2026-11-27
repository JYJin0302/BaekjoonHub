#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct P {
	ll x, y;
	ll vx, vy;
	P(){
		x = y = vx = vy = -1e10;
	}
	P operator-(P& o) {
		P res;
		res.x = x - o.x;
		res.y = y - o.y;
		return res;
	}

	bool operator<(P& o) {
		if (vx == -1e10) return make_pair(y, x) < make_pair(o.y, o.x);
		ll res = vx * o.vy - vy * o.vx;
		if (res == 0) return vx * vx + vy * vy < o.vx* o.vx + o.vy * o.vy;
		return res > 0;
	}

};

ll ccw(P a, P b) {
	return a.x * b.y - a.y * b.x;
}

ll ccw(P& a, P& b, P& c) {
	return a.x * b.y + b.x * c.y + c.x * a.y - (a.y * b.x + b.y * c.x + c.y * a.x);
}

ll dist(P& a, P& b) {
	//cout << "GO: " << a.x << ' ' << a.y << ' ' << b.x << ' ' << b.y << '\n';
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

void solve() {

	int n;
	cin >> n;
	vector<P> A(n);
	for (auto& i : A) cin >> i.x >> i.y;

	sort(A.begin(), A.end());

	for (int i = 0; i < n; i++) {
		A[i].vx = A[i].x - A[0].x;
		A[i].vy = A[i].y - A[0].y;
	}

	sort(A.begin(), A.end());
	A.push_back(A[0]);

	//for (auto i : A) cout << i.x << ' ' << i.y << '\n';

	stack<P> st;
	st.push(A[0]);
	st.push(A[1]);
	
	for (int i = 2; i <= n; i++) {
		while (st.size() >= 2) {
			P a, b;
			b = st.top(); st.pop();
			a = st.top();

			if (ccw(a, b, A[i]) > 0) {
				st.push(b);
				break;
			}
			//cout << "Pop\n";
		}
		if (i != n) st.push(A[i]);
	}

	if (st.size() == 1) st.push(A[n-1]);

	vector<P> ch;
	//cout << "CONVEXh hull:\n";
	while (!st.empty()) {
		//cout << st.top().x << ' ' << st.top().y << '\n';
		ch.push_back(st.top());
		st.pop();
	}

	int tn = ch.size();
	reverse(ch.begin(), ch.end());

	if (tn == 2) {
		cout << ch[0].x << ' ' << ch[0].y << ' ' << ch[1].x << ' ' << ch[1].y << '\n';
		return;
	}
	//for (auto i : ch) cout << i.x << ' ' << i.y << '\n';
	
	int ix = 1;
	ll mdist = 0;
	int ans1 = -1, ans2 = -1;
	for (int i = 0; i < tn; i++) {

		while ((ix + 1) % tn != i && ccw(ch[(i + 1) % tn] - ch[i], ch[(ix + 1) % tn] - ch[ix]) >= 0) {
			ll tdist = dist(ch[i], ch[ix]);
			//cout << tdist << ' ' << i << ' ' << ix << '\n';
			if (tdist > mdist) {
				mdist = tdist;
				ans1 = i;
				ans2 = ix;
			}
			ix = (ix+1)%tn;
		}
	}
	//cout << ans1 << ' ' << ans2 << '\n';

	cout << ch[ans1].x << ' ' << ch[ans1].y << ' ' << ch[ans2].x << ' ' << ch[ans2].y << '\n';


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}