#include <bits/stdc++.h>
using namespace std;

vector<int> root;

int find(int n) {
	if (root[n] == n) return n;

	return root[n] = find(root[n]);
}

bool cmpx(tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
	return get<0>(a) < get<0>(b);
}
bool cmpy(tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
	return get<1>(a) < get<1>(b);
}
bool cmpz(tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
	return get<2>(a) < get<2>(b);
}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	int n;
	cin >> n;

	root = vector<int>(n);
	for (int i = 1; i < n; i++) root[i] = i;

	vector<tuple<int, int, int, int>> planet(n);
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		planet[i] = { a, b, c, i };
	}

	vector<tuple<int, int, int>> lines;

	// x
	sort(planet.begin(), planet.end(), cmpx);

	for (int i = 1; i < n; i++) {

		int a, b, c, d;
		int x, y, z, w;

		tie(a, b, c, d) = planet[i];
		tie(x, y, z, w) = planet[i - 1];

		lines.push_back({ abs(a - x),d, w });
	}

	// y
	sort(planet.begin(), planet.end(), cmpy);

	for (int i = 1; i < n; i++) {

		int a, b, c, d;
		int x, y, z, w;

		tie(a, b, c, d) = planet[i];
		tie(x, y, z, w) = planet[i - 1];

		lines.push_back({ abs(b - y), d, w });
	}

	// z
	sort(planet.begin(), planet.end(), cmpz);

	for (int i = 1; i < n; i++) {

		int a, b, c, d;
		int x, y, z, w;

		tie(a, b, c, d) = planet[i];
		tie(x, y, z, w) = planet[i - 1];

		lines.push_back({ abs(c - z), d, w });
	}

	sort(lines.begin(), lines.end());
	int ans = 0;

	for (auto i : lines) {
		int a, b, c;
		tie(a, b, c) = i;

		if (find(b) == find(c)) continue;
		root[find(c)] = find(b);

		ans += a;
	}

	cout << ans;
}