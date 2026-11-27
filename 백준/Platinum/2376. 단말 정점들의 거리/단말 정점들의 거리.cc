#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, cnt = 0;
vector<vector<int>> adj;
vector<int> fc;

struct Node {
	int p = -1;
	int l = -1, r = -1;
};
vector<Node> A;

void insert(int c, int d, int t) {

	if (d == 0) return;

	if (fc[c] == 2) {

		if (A[c].p == -1) {
			A[c].p = n + cnt;
			
			if (A[n + cnt].l == -1) {
				A[n + cnt].l = c;
			}
			else A[n + cnt].r = c;
			cnt++;

			fc[A[c].p]++;
		}
		insert(A[c].p, d - 1, t);

		return;
	}

	int nx;
	if (d == 1) nx = t;
	else {
		nx = cnt + n;
		cnt++;
	}

	if (fc[c] == 1) {
		A[c].r = nx;
		A[nx].p = c;
		fc[c]++;
		insert(nx, d - 1, t);
	}
	else {
		A[c].l = nx;
		A[nx].p = c;
		fc[c]++;
		insert(nx, d - 1, t);
	}
}


int main() {

	cin >> n;

	fc = vector<int>(n * 2);
	for (int i = 0; i < n; i++) fc[i] = 2;

	adj = vector<vector<int>>(n*2);
	A = vector<Node>(n * 2);

	for (int i = 0; i < n - 1; i++) {
		int x;
		cin >> x;

		insert(i, x, i + 1);
	}

	int a, b;
	cin >> a >> b;
	a--, b--;
	vector<int> dist(n * 2, -1);
	dist[a] = 0;

	queue<int> q;
	q.push(a);
	while (!q.empty()) {

		int x = q.front();
		q.pop();

		if (x == b) break;

		if (A[x].l != -1 && dist[A[x].l] == -1) {
			dist[A[x].l] = dist[x] + 1;
			q.push(A[x].l);
		}
		if (A[x].r != -1 && dist[A[x].r] == -1) {
			dist[A[x].r] = dist[x] + 1;
			q.push(A[x].r);
		}
		if (A[x].p != -1 && dist[A[x].p] == -1) {
			dist[A[x].p] = dist[x] + 1;
			q.push(A[x].p);
		}
	}

	cout << dist[b];
}