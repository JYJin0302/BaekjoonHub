#include <bits/stdc++.h>

using namespace std;

int main() {

	
	const double pi = 3.14159265358979;

	double x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

	double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

	if (r1 > r2) swap(r1, r2);

	double ans = 0;
	if (d >= r1 + r2) ans = 0;
	else if (r2 >= d + r1) ans = r1 * r1 * pi;
	else {

		double x = (d * d + r2 * r2 - r1 * r1) / (2 * d);
		double tt = acos(x/r2);
		ans += r2 * r2 * tt - x*x*tan(tt);

		x = d - x;
		tt = acos(x/r1);
		ans += r1 * r1 * tt - x * x * tan(tt);
	}
	cout << fixed << setprecision(3);
	cout << ans;
}