#include <bits/stdc++.h>
using namespace std;

const double pi = 3.1415926535;

struct Circle {
	double x, y, r;
};

double distt(double a, double b, double c, double d) {
	return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

double intersect(Circle a, Circle b) {
	double dist = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));

	if (a.r > b.r) swap(a, b);

	if (a.r + dist <= b.r) return pi * a.r * a.r;
	if (a.r + b.r <= dist) return 0;

	double xa = (a.r * a.r - b.r * b.r + dist * dist) / (2 * dist);
	double h = sqrt(a.r * a.r - xa * xa);
	double xb = dist - xa;

	double theta = atan(h / xa);
	double area1 = a.r * a.r * theta - xa * h;

	theta = atan(h / xb);
	double area2 = b.r * b.r * theta - xb * h;

	return area1 + area2;
}

int main() {

	Circle A, B, C;
	cin >> A.x >> A.y >> A.r;
	cin >> B.x >> B.y >> B.r;
	cin >> C.x >> C.y >> C.r;

	double ans = pi * (A.r * A.r + B.r * B.r + C.r * C.r);
	ans -= intersect(A, B) + intersect(B, C) + intersect(C, A);

	int cnt = 0;
	for (int i = 0; i <= 500; i++) {
		for (int j = 0; j <= 500; j++) {
			double ti = i / 5.0;
			double tj = j / 5.0;
			if (distt(ti, tj, A.x, A.y) <= A.r && distt(ti, tj, B.x, B.y) <= B.r && distt(ti, tj, C.x, C.y) <= C.r) cnt++;
		}
	}

	cout << fixed << setprecision(6);
	ans += cnt / 25.0;

	cout << ans;
}