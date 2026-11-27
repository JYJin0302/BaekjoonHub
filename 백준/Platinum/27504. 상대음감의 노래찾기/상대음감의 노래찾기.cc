#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve(vector<int>& A, vector<int>& B) {
    int n = A.size(), m = B.size();
    vector<int> f(m);

    int curr = 0;
    for (int i = 1; i < m; i++) {

        while (curr > 0 && B[i] != B[curr]) {
            curr = f[curr - 1];
        }

        if (B[i] == B[curr]) {
            curr++;
            f[i] = curr;
        }
    }

    curr = 0;
    int s = 0;

    vector<int> ans;

    while (s + m <= n) {

        while (curr < m && A[s + curr] == B[curr]) curr++;

        if (curr == m) return 1;

        while (curr > 0 && A[s + curr] != B[curr]) curr = f[curr - 1];
        s++;
    }
    return 0;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> inp(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        vector<int> tmp(x);
        for (auto& k : tmp) cin >> k;

        for (int j = 1; j < x; j++) {
            inp[i].push_back(tmp[j] - tmp[j-1]);
        }
    }

    int m;
    cin >> m;

    vector<int> dat;
    int pv;
    cin >> pv;
    for (int i = 1; i < m; i++) {
        int x;
        cin >> x;

        dat.push_back(x - pv);
        pv = x;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (solve(inp[i], dat)) {
            cout << i + 1 << ' ';
            cnt++;
        }
    }

    if (cnt == 0) cout << -1;
}