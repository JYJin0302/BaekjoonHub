#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int mod = 1e9 + 7;
vector<vector<ll>> mult(vector<vector<ll>> a, vector < vector < ll >> b) {

    vector<vector<ll>> res(a.size(), vector<ll>(a[0].size()));
    for (int k = 0; k < a.size(); k++) {
        for (int i = 0; i < a.size(); i++) {
            ll temp = 0;
            for (int j = 0; j < a.size(); j++) {
                temp += a[k][j] * b[j][i];
                temp %= mod;
            }
            res[k][i] = temp;
        }
    }

    return res;
}

vector<vector<vector<ll>>> A;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> base(n + 1, vector<ll>(n + 1));

    vector<pair<int, int>> order;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        base[a][b] = 1;
        base[b][a] = 1;
    }

    int k;
    cin >> k;

    k--;
    int cnt = 1;
    ll size = 1;
    while (size <= k) {
        size *= 2;
        cnt++;
    }
    cnt--;

    if (k == 0) {
        cout << base[1][1];
        return 0;
    }

    vector<vector<vector<ll>>> A(cnt);
    vector<ll> bb(cnt);
    for (int i = 0; i < cnt; i++) {
        bb[i] = k % 2;
        k /= 2;
    }

    A[0] = base;

    for (int i = 1; i < cnt; i++) {
        A[i] = mult(A[i - 1], A[i - 1]);
    }

    vector<vector<ll>> ans = A[0];
    for (int i = 0; i < cnt; i++) {
        if (bb[i] == 1) ans = mult(ans, A[i]);
    }

    cout << ans[1][1];

}