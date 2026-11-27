#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N = 120, cnt = 0, scnt = 0;
vector<int> adj[130];
int dfsn[130], scc[130];
stack<int> stk;

void addEdge(int u, int v) {
	adj[u].push_back(v);
}

void clear() {
	cnt = scnt = 0;
	for (int i = 0; i < N; i++) {
		dfsn[i] = scc[i] = -1;
	}
}


int dfs(int n) {
	dfsn[n] = cnt;
	++cnt;
	stk.push(n);
	int ret = dfsn[n];
	for (auto it : adj[n]) {

		if (dfsn[it] == -1) {
			ret = min(ret, dfs(it));
		}
		else {
			if (scc[it] == -1) ret = min(ret, dfsn[it]);
		}
	}
	if (ret == dfsn[n]) {
		while (!stk.empty()) {
			int tmp = stk.top();
			stk.pop();
			scc[tmp] = scnt;
			if (tmp == n) break;
		}
		scnt++;
	}
	return ret;
}

bool check(int u, int v) {
	return scc[u] == scc[v];
}
void init() {
	for (int i = 0; i < 104; i++) {
		if (dfsn[i] == -1) dfs(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	clear();
	for (int i = 0; i < 26; i++) {
		addEdge(i, 78 + i);
		addEdge(52 + i, 26 + i);
	}

	int q;
	cin >> q;
	while (q--) {

		string s;
		int a, b;
		cin >> s;
		cin >> a >> b;

		int v1 = int(s[0] - 'A');
		int v2 = int(s[1] - 'A');

		if (a == 2) v1 += 52, v2 += 52;

		if (b == 2) {
			addEdge(v1 + 26, v1);
			addEdge(v2 + 26, v2);
		}
		else if (b == 1) {
			addEdge(v1 + 26, v2);
			addEdge(v2 + 26, v1);
			addEdge(v1, v2 + 26);
			addEdge(v2, v1 + 26);
		}
		else {
			addEdge(v1, v1 + 26);
			addEdge(v2, v2 + 26);
		}

	}

	vector<int> ch(26);
	ch[25] = 1;
	ch[24] = 1;
	ch[23] = 1;


	int ans = 0;
	do {
		string tmp;
		for (int i = 0; i < 26; i++) {
			if (ch[i] == 1) {
				tmp += char('A' + i);
				addEdge(i, i + 26);
				addEdge(i + 52, i + 78);
			}
			else {
				addEdge(i + 26, i + 52);
				addEdge(i + 78, i);
			}
		}
		

		init();

		bool valid = 1;
		for (int i = 0; i < 26; i++) {
			if (check(i, i + 26)) valid = 0;
			if (check(i + 52, i + 78)) valid = 0;
		}

		
		if (valid) {
			ans++;
		}
	

		for (int i = 0; i < 26; i++) {
			if (ch[i]) {
				adj[i].pop_back();
				adj[i+52].pop_back();
			}
			else {
				adj[i + 26].pop_back();
				adj[i + 78].pop_back();
			}
		}

		clear();
	} while (next_permutation(ch.begin(), ch.end()));

	cout << ans;

}