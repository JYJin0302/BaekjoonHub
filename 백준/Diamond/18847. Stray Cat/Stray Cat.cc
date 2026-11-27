#include "Anthony.h"
#include "Catherine.h"
#include <bits/stdc++.h>

#define mp std::make_pair

namespace {

	std::vector<std::vector<std::pair<int, int>>> adj;
	std::vector<int> X;
	const std::string pattern = "110010";
	void dfs(int v, int pv = -1, int pval = -1) {
		if (pv == -1) {
			for (auto& [a, b] : adj[v]) {
				X[b] = 1;
				dfs(a, v, 1);
			}
		}
		else {
			if (adj[v].size() == 2) {
				for (auto& [a, b] : adj[v]) if (a != pv) {
					X[b] = pattern[pval] - '0';
					dfs(a, v, (pval + 1) % 6);
				}
			}
			else {
				int pre = pattern[(pval + 5) % 6] - '0';
				for (auto& [a, b] : adj[v]) if (a != pv) {
					if (pre == 0) {
						X[b] = 1;
						dfs(a, v, 1);
					}
					else {
						X[b] = 0;
						dfs(a, v, 3);
					}
				}
			}
		}
	}

}  // namespace

std::vector<int> Mark(int N, int M, int A, int B,
	std::vector<int> U, std::vector<int> V) {


	adj = std::vector<std::vector<std::pair<int, int>>> (N);
	X = std::vector<int>(M);
	for (int i = 0; i < M; i++) {
		adj[U[i]].push_back(mp(V[i], i));
		adj[V[i]].push_back(mp(U[i], i));
	}

	if (A >= 3) {
		std::vector<int> dist(N, -1);
		std::queue<int> q;
		q.push(0);
		dist[0] = 0;
		while (!q.empty()) {
			int a = q.front(); q.pop();
			int val = dist[a] % 3;
			for (auto [u, v] : adj[a]) {
				if (dist[u] == -1) {
					dist[u] = dist[a] + 1;
					X[v] = val;
					q.push(u);
				}
				else if (dist[u] >= dist[a]) {
					X[v] = val;
				}
			}
		}
	}
	else {
		dfs(0);
	}

	//for (int i = 0; i < M; ++i) {
	//	X[i] = FunctionExample(i, A);
	//}
	return X;
}

namespace {

	int A, B;
	int type, visCnt, prev;
	bool stable;

	int P[4][4];

}  // namespace

void Init(int A, int B) {
	::A = A;
	::B = B;
	visCnt = 0;
	prev = -1;
	type = -1;
	stable = false;

	P[0][0] = 1; P[0][1] = 1; P[0][2] = 0; P[0][3] = 0; // 0, 1
	P[1][0] = 0; P[1][1] = 1; P[1][2] = 0; P[1][3] = 1; // 0, 0
	P[2][0] = 1; P[2][1] = 0; P[2][2] = 0; P[2][3] = 1; // 1, 1

	P[3][0] = 1; P[3][1] = 0; P[3][2] = 1; P[3][3] = 1; // 0, 1
}

int Move(std::vector<int> y) {

	if (A >= 3) {
		std::vector<int> tmp;
		for (int i = 0; i < A; i++) {
			if (y[i]) tmp.push_back(i);
		}

		if (tmp.size() == 1) return tmp[0];
		if (tmp[0] == 0 && tmp[1] == 1) return 0;
		if (tmp[0] == 0 && tmp[1] == 2) return 2;
		return 1;
	}

	// A = 2

	int tot = 0;
	for (auto f : y) tot += f;
	if (tot == 0) {
		stable = 1;
		return -1;
	}

	if (stable || (visCnt && tot >= 2) || tot >= 3) {
		if (prev != -1 && tot != 1) y[prev]++;

		int nxt = -1, ncnt = 0;
		for (int i = 0; i < A; i++) {
			if (y[i]) {
				if (nxt == -1 || ncnt > y[i]) {
					ncnt = y[i];
					nxt = i;
				}
			}
		}

		if (!stable && prev == nxt) {
			stable = 1;
			return -1;
		}
		stable = 1;
		prev = nxt;
		return nxt;
	}


	int nxt = -1;
	if (visCnt == 0) {
		if (y[1] == 0) {
			nxt = 0;
			type = 1;
		}
		else if (y[0] == 0) {
			nxt = 1;
			type = 2;
		}
		else {
			nxt = 1;
			type = 0;
		}

		visCnt++;
		prev = nxt;
		return nxt;
	}

	for (int i = 0; i < A; i++) {
		if (y[i]) nxt = i;
	}

	if (P[type][visCnt] == nxt) {
		if (visCnt == 3) {
			stable = 1;
			return -1;
		}
		else {
			visCnt++;
			prev = nxt;
			return nxt;
		}
	}
	else if (visCnt == 1 && type == 0) {
		type = 3;
		visCnt++;
		prev = nxt;
		return nxt;
	}
	else{
		stable = 1;
		prev = nxt;
		return nxt;
	}

}