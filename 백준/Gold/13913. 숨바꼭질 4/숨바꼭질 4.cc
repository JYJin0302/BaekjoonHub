#include <bits/stdc++.h>
using namespace std;
#define INF 200000

int main() {

	int n, m;
	cin >> n >> m;
	if (n == m) {
		cout << "0\n" << n;
		return 0;
	}

	vector<int> path(max(n, m)+2, INF);

	queue<int> q;
	q.push(n);
	path[n] = 0;

	while (!q.empty()) {
		int a = q.front();
		q.pop();

		if (a == m) break;

		if (a > 0 && path[a - 1] == INF) {
			path[a - 1] = path[a] + 1;
			q.push(a-1);
		}

		if (a < max(m, n) && path[a + 1] == INF) {
			path[a + 1] = path[a] + 1;
			q.push(a + 1);
		}

		if (a * 2 <= m + 1 && path[a * 2] == INF) {
			path[a * 2] = path[a] + 1;
			q.push(a * 2);
		}
	}

	cout << path[m] << '\n';
	int cnt = path[m];
	int curr = m;
	vector<int> A;
	A.push_back(m);
	cnt--;
	while (cnt) {
		if (curr > 0 && path[curr - 1] == cnt) {
			A.push_back(curr - 1);
			curr -= 1;
			cnt--;
		}
		else if (curr <= max(m, n) && path[curr + 1] == cnt) {
			A.push_back(curr + 1);
			curr += 1;
			cnt--;
		}
		else if (curr % 2 == 0 && path[curr / 2] == cnt) {
			A.push_back(curr / 2);
			curr /= 2;
			cnt--;
		}
	}

	A.push_back(n);

	for (auto it = A.rbegin(); it != A.rend(); it++) {
		cout << *it << ' ';
	}
}