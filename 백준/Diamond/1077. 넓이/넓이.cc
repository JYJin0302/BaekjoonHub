#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point {
	long double x, y;
	long double vx, vy;

	Point() {
		x = 0, y = 0;
		vx = 1, vy = 0;
	}
	Point(ll v1, ll v2) {
		x = v1, y = v2;
		vx = 1, vy = 0;
	}
	Point(long double v1, long double v2) {
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

long double ccw(Point& a, Point& b, Point& c) {
	long double val = a.x * b.y + b.x * c.y + c.x * a.y - (a.y * b.x + b.y * c.x + c.y * a.x);
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

Point getIntersectionPoint(Line& l1, Line& l2) {
	
	long double px, py, a, b, c,d;
	a = l1.s.x, b = l1.s.y;
	c = l2.s.x, d = l2.s.y;

	long double d1 = l1.e.x - l1.s.x, d2 = l1.e.y - l1.s.y;
	long double d3 = l2.e.x - l2.s.x, d4 = l2.e.y - l2.s.y;
	if (d1 * d4 != d2 * d3) {
		px = d4 * (c-a) - d3 * (d-b);
		px /= d1 * d4 - d2 * d3;

		py = d2 * (c-a) - d1 * (d-b);
		py /= d1 * d4 - d2 * d3;

	}
	else if (d1 == 0) {
		py = (a - c) / d3;
		px = (d4 * py + d1 * (d - b)) / d2;
	}
	else if (d2 == 0) {
		py = (d - b) / d4;
		px = (c - a + d3 * py) / d1;
	}
	else if (d3 == 0) {
		px = (c - a) / d1;
		py = (d2 * px + b - d) / d4;
	}
	else {
		px = (d - b) / d2;
		py = (d1 * px + a - c) / d3;
	}

	return Point(a+px*d1, b+px*d2);

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

	vector<Point> cH1(n), cH2(m);
	for (auto& i : cH1) cin >> i.x >> i.y;
	for (auto& i : cH2) cin >> i.x >> i.y;
	int tn = cH1.size(), tm = cH2.size();
	reverse(cH1.begin(), cH1.end());
	reverse(cH2.begin(), cH2.end());

	vector<Point> tmp;
	for (int i = 0; i < tn; i++) {
		Line l1 = { cH1[i], cH1[(i + 1) % tn] };
		for (int j = 0; j < tm; j++) {
			Line l2 = { cH2[j], cH2[(j + 1) % tm] };

			if (isConn(l1, l2)) {
				tmp.push_back(getIntersectionPoint(l1, l2));
			}
		}
	}

	//cout << "in test\n";
	// 포함하는 경우
	for (int i = 0; i < tm; i++) {
		if (isIn(cH1, cH2[i], tn)) {
			tmp.push_back(cH2[i]);
		}
	}
	for (int i = 0; i < tn; i++) {
		if (isIn(cH2, cH1[i], tm)) {
			tmp.push_back(cH1[i]);
		}
	}

	vector<Point> res = getConvexHull(tmp, tmp.size());

	long double ans = 0;
	for (int i = 2; i < res.size(); i++) {
		ans += ccw(res[0], res[i-1], res[i]);
	}
	cout << abs(ans)/2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cout << setprecision(15);

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}

}