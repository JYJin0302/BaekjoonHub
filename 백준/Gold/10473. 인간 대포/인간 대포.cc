#include <bits/stdc++.h>
using namespace std;


double calDist(pair<double, double> a, pair<double, double> b) {

	return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));

}

int main() {

	pair<double, double> s, f;
	cin >> s.first >> s.second;
	cin >> f.first >> f.second;

	int n;
	cin >> n;
	cout << setprecision(6) << fixed;

	vector<pair<double, double>> A(n);

	for (int i = 0; i < n; i++) {
		cin >> A[i].first >> A[i].second;
	}

	vector<vector<double>> path(n, vector<double>(n));
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double dist = calDist(A[i], A[j]);
			path[i][j] = min(dist / 5.0, 2.0 + fabs(dist - 50) / 5.0);
			path[j][i] = path[i][j];
		}
	}

	vector<bool> check(n + 1);
	double ret = calDist(s, f) / 5.0;

	priority_queue<pair<double, double>> pq;
	for (int i = 0; i < n; i++) {
		double dist = calDist(s, A[i]);
		pq.push({ -dist/5.0, i });
	}

	while (!pq.empty()) {

		double a, b;
		tie(a, b) = pq.top();
		pq.pop();
		a *= -1;
		
		if (check[b]) continue;
		check[b] = 1;

		double d = calDist(A[b], f);
		d = min(d / 5.0, 2 + abs(d - 50) / 5);
		ret = min(ret, a + d);

		for (int i = 0; i < n; i++){
			if (check[i] == 1) continue;
			double d = calDist(A[b], A[i]);
			d = min(d / 5.0, 2 + abs(d - 50) / 5);

			pq.push({ -(a + d), i });
		}
	}

	cout << ret;
}