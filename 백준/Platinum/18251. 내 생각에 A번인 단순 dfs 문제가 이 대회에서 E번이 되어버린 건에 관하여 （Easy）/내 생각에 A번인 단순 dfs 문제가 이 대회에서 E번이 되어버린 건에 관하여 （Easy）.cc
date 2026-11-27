#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int dx[] = { -1, 0, 1, 0 }; 
int dy[] = { 0, 1, 0, -1 };

int n;
ll A[266666];
int dep[266666];
ll dp[19][19];


vector<int> od;

void dfs(int v) {

    if (v * 2 <= n) {
        dep[v * 2] = dep[v] + 1;
        dfs(v * 2);
    }
    od.push_back(v);
    if (v * 2 + 1 <= n) {
        dep[v * 2 + 1] = dep[v] + 1;
        dfs(v * 2 + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    int k = log2(n+1);
    for (int i = 1; i <= k; i++) {
        for (int j = i; j <= k; j++) {
            dp[i][j] = -1e9;
        }
    }

    for (int i = 1; i <= n; i++) cin >> A[i];

    dep[1] = 1;
    dfs(1);


    ll ans = -1e9;
    for (auto i : od) {
        int h = dep[i];

        for (int a = 1; a <= k; a++) {
            for (int b = a; b <= k; b++) {

                if (a <= h&& h <= b) {
                    dp[a][b] = max(0ll, dp[a][b]) + A[i];
                    ans = max(ans, dp[a][b]);
                }
            }
        }

    }
    cout << ans;

}