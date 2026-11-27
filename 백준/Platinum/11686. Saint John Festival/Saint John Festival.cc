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

	void pf() {
		cout << s.x << ' ' << s.y << ' ' << e.x << ' ' << e.y << '\n';
	}
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
		if (isInLine(ch[l], ch[l + 1], t)) return 1;
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

	int n;
	cin >> n;

	vector<Point> A(n), cH1;
	for (auto& i : A) cin >> i.x >> i.y;
	cH1 = getConvexHull(A, n);

	int tn = cH1.size();

	int ans = 0;

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		Point tmp;
		cin >> tmp.x >> tmp.y;
		if (isIn(cH1, tmp, tn)) {
			//cout << "in: " << tmp.x << ' ' << tmp.y << '\n';
			ans++;
		}
	}
	cout << ans;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}

}