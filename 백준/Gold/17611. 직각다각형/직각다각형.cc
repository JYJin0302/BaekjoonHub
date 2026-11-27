#include <bits/stdc++.h>
using namespace std;

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	int n, a, b, c, d;
	cin >> n;

	vector<pair<int, int>> A, ver, hor;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		A.push_back({ a, b });
		if (i != 0) {
			tie(c, d) = A[i - 1];
			if (a == c) {
				ver.push_back({ min(b, d), 1 });
				ver.push_back({ max(b, d), 0 });
			}
			else if (b == d) {
				hor.push_back({ min(a, c), 1 });
				hor.push_back({ max(a, c), 0 });
			}
		}
		if (i == n-1){
			tie(c, d) = A[0];
			if (a == c) {
				ver.push_back({ min(b, d), 1 });
				ver.push_back({ max(b, d), 0 });
			}
			else if (b == d) {
				hor.push_back({ min(a, c), 1 });
				hor.push_back({ max(a, c), 0 });
			}
		}
	}

	sort(ver.begin(), ver.end());
	sort(hor.begin(), hor.end());

	int v, h,  curr;

	curr = 0, v = 0;
	for (auto i : ver) {
		tie(a, b) = i;
		if (b == 0) curr--;
		else curr++;
		v = max(v, curr);
	}
	curr = 0, h = 0;
	for (auto i : hor) {
		tie(a, b) = i;
		if (b == 0) curr--;
		else curr++;
		h = max(h, curr);
	}
	cout << max(h, v);
}