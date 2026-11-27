#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);

	int n, k;
	cin >> n >> k;

	vector<ll> point(n + 1), group_val(k+1), group_time(k+1), rank(k+1);
	vector<ll> res(n + 1);

	for(int i = 0; i < k;i++) {

		int t;
		cin >> t;

		while (t--) {
			int x;
			cin >> x;

			// update x
			ll currVal = point[x];
			group_val[currVal + 1] += (i - group_time[currVal + 1]) * (rank[currVal + 1] + 1);
			group_time[currVal + 1] = i;

			group_val[currVal] += (i - group_time[currVal]) * (rank[currVal] + 1);
			group_time[currVal] = i;

			res[x] += group_val[currVal] - group_val[currVal + 1];
			point[x]++;
			rank[currVal]++;
		}
	}

	for (int i = 1; i <= n; i++) {
		res[i] += (k - group_time[point[i]]) * (rank[point[i]]+1) + group_val[point[i]];
	}

	for (int i = 1; i <= n; i++) {
		cout << (long double)1.0 * res[i] / k << '\n';
	}
}