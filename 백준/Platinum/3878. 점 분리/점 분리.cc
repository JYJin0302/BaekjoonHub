#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point {
	ll x, y;
	ll vx, vy;

	Point() {
		x = 0, y = 0;
		vx = 1, vy = 0;
	}
	Point(ll v1, ll v2) {
		x = v1, y = v2;
		vx = 1, vy = 0;
	}

	bool operator<(Point& o) {
		if (y == o.y) return x < o.x;
		return y < o.y;
	}
	bool operator==(Point& o) {
		return o.x == x && o.y == y;
	}
	bool operator<=(Point& o) {
		return *this < o || *this == o;
	}


	Point operator-(Point& o) {
		return Point(x - o.x, y - o.y);
	}
	Point operator+(Point& o) {
		return Point(x + o.x, y + o.y);
	}

};

struct Line {
	Point s, e;
};

ll ccw(Point& a, Point& b, Point& c) {
	ll val = a.x * b.y + b.x * c.y + c.x * a.y - (a.y * b.x + b.y * c.x + c.y * a.x);
	if (val != 0) val /= abs(val);
	return val;
}

bool isInLine(Point p1, Point p2, Point t) {
	if (t.x > max(p1.x, p2.x) || t.x < min(p1.x, p2.x)) return 0;
	if (t.y > max(p1.y, p2.y) || t.y < min(p1.y, p2.y)) return 0;

	return (p1.x - t.x) * (p2.y - t.y) == (p2.x - t.x) * (p1.y - t.y);
}

bool isConn(Line& a, Line& b) {

	ll v1 = ccw(a.s, a.e, b.s) * ccw(a.s, a.e, b.e);
	ll v2 = ccw(b.s, b.e, a.s) * ccw(b.s, b.e, a.e);

	if (v1 == 0 && v2 == 0) {
		bool ok = 0;
		if (isInLine(a.s, a.e, b.s) || isInLine(a.s, a.e, b.e)) ok = 1;
		if (isInLine(b.s, b.e, a.s) || isInLine(b.s, b.e, a.e)) ok = 1;
		return ok;
	}
	return v1 <= 0 && v2 <= 0;
}

bool cmp(Point& a, Point& b) {
	if (a.vy * b.vx != a.vx * b.vy) return a.vy * b.vx < a.vx * b.vy;
	return (a.vx * a.vx + a.vy * a.vy) < (b.vx * b.vx + b.vy * b.vy);
}

bool isIn(vector<Point>& ch, Point t, int n) {
	//convexhull vector, target point, ch size
	if (n <= 2) return 0;
	
	int l = 1, r = n - 1, res = 1;
	if (ccw(ch[0], ch[1], t) > 0) return 0;
	if (ccw(ch[0], ch[n-1], t) < 0) return 0;
	while (l <= r) {
		int m = (l + r) / 2;

		ll val = ccw(ch[0], ch[m], t);
		if (val > 0) r = m - 1;
		else {
			res = m;
			l = m+1;
		}
	}

	l = res;
	Line t1 = { ch[l], ch[l + 1] };
	Line t2 = { ch[0], t };

	if (isConn(t1, t2)) {
		//cout << "CONNECTEd: " << t1.s.x << ' ' << t1.s.y << ' ' << t1.e.x << ' ' << t1.e.y << " + "\
			<< t2.s.x << ' ' << t2.s.y << ' ' << t2.e.x << ' ' << t2.e.y << '\n';
		return 0;
	}
	return 1;

}

vector<Point> getConvexHull(vector<Point>& inp, int n) {

	sort(inp.begin(), inp.end());
	if (n <= 2) return inp;
	for (int i = 0; i < n; i++) {
		inp[i].vx = inp[i].x - inp[0].x;
		inp[i].vy = inp[i].y - inp[0].y;
	}

	sort(inp.begin(), inp.end(), cmp);

	stack<Point> st;
	for (int i = 0; i <= n; i++) {

		while (st.size() >= 2) {
			Point b = st.top(); st.pop();
			Point a = st.top();

			if (ccw(a, b, inp[i%n]) > 0) {
				st.push(b);
				break;
			}
		}
		st.push(inp[i%n]);
	}
	vector<Point> res;
	while (st.size() > 1) {
		res.push_back(st.top());
		st.pop();
	}
	return res;
}

void solve() {

	int n, m;
	cin >> n >> m;

	vector<Point> A(n), B(m);
	for (auto& i : A) cin >> i.x >> i.y;
	for (auto& i : B) cin >> i.x >> i.y;

	vector<Point> cH1, cH2;
	cH1 = getConvexHull(A, n);
	cH2 = getConvexHull(B, m);
	int tn = cH1.size(), tm = cH2.size();

	//cout << "Connect test\n";
	for (int i = 0; i < tn; i++) {
		Line l1 = { cH1[i], cH1[(i + 1) % tn] };
		for (int j = 0; j < tm; j++) {
			Line l2 = { cH2[j], cH2[(j + 1) % tm] };

			if (isConn(l1, l2)) {
				cout << "NO\n";
				return;
			}
		}
	}

	//cout << "in test\n";

	// 포함하는 경우
	vector<int> cnt(2), cnt2(2);
	for (int i = 0; i < tm; i++) {
		if (isIn(cH1, cH2[i], tn)) {
			//cout << cH2[i].x << ' ' << cH2[i].y << ' ' << "is In Ch1\n";
			cnt[1]++;
		}
		else cnt[0]++;
	}
	for (int i = 0; i < tn; i++) {
		if (isIn(cH2, cH1[i], tm)) {
			//cout << cH1[i].x << ' ' << cH1[i].y << ' ' << "is In cH2\n";
			cnt2[1]++;
		}
		else cnt2[0]++;
	}
	//cout << cnt[0] << ' ' << cnt[1] << ' ' << cnt2[0] << ' ' << cnt2[1] << '\n';

	if (cnt[1] == tm || cnt2[1] == tn) cout << "NO\n";
	else cout << "YES\n";

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

}