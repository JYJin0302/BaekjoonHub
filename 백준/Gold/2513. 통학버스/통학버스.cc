#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k, s, a, b;
	cin >> n >> k >> s;

	vector<pair<int, int>> left;
	vector<pair<int, int>> right;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (a < s) left.push_back({ a, b });
		else if (a > s) right.push_back({ a, b });
	}

	sort(left.begin(), left.end());
	sort(right.rbegin(), right.rend());

	int ans = 0;

	int li = 0;
	while (li < left.size()) {
		ans += (s - left[li].first) * 2;
		int temp = k;
		while (temp && li < left.size()) {
			int tt = min(temp, left[li].second);
			temp -= tt;
			left[li].second -= tt;
			if (left[li].second == 0) li++;
		}
	}

	int ri = 0;
	while (ri < right.size()) {
		ans += (right[ri].first - s) * 2;
		int temp = k;
		while (temp && ri < right.size()) {
			int tt = min(temp, right[ri].second);
			temp -= tt;
			right[ri].second -= tt;
			if (right[ri].second == 0) ri++;
		}
	}
	cout << ans;
}