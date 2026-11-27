#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 1000000;
int A[1000001];
vector<int> fw_sum, fw_cnt;

void update(int x, int v, vector<int>& fw) {
	while (x <= MAX_N) {
		fw[x] += v;
		x += x & -x;
	}
}

int ssum(int x, vector<int>& fw) {
	int res = 0;
	while (x) {
		res += fw[x];
		x -= x & -x;
	}
	return res;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	fw_cnt = vector<int>(MAX_N + 1);
	fw_sum = vector<int>(MAX_N + 1);
	int q;
	cin >> q;
	while (q--) {

		int t, x;
		cin >> t >> x;

		if (t == 1) {
			A[x]++;
			update(x, 1, fw_sum);
			//update(x + 1, -1, fw_sum);
			if (A[x] == 1) {
				update(x, 1, fw_cnt);
			}
		}
		else {
			A[x]--;
			update(x, -1, fw_sum);
			//update(x + 1, 1, fw_sum);
			if (A[x] == 0) {
				update(x, -1, fw_cnt);
			}
		}

		int l = 0, r = MAX_N, res = 0;
		while (l <= r) {
			int mid = (l + r) / 2;
			int val = ssum(mid, fw_cnt);

			if (val == mid) {
				res = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		int ans = ssum(res, fw_sum);
		cout << ans << '\n';

	}
}