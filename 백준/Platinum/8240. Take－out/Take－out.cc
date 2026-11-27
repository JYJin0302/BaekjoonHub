#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


int G[1001010];
int sz[1001010];

void solve() {

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    stack<int> B, C;    
    vector<int> ord(n);
    int ordCnt = n / (k + 1);
    vector<vector<int>> ans(ordCnt);
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == 'b') {
            if (C.empty()) B.push(i);
            else {
                int cdx = C.top();
                sz[cdx]++;
                G[i] = cdx;

                if (sz[cdx] == k) {
                    // clear
                    C.pop();
                    ord[cdx] = --ordCnt;
                }
            }
        }
        else {
            G[i] = i;
            C.push(i);
            while (!B.empty() && !C.empty()) {
                int cdx = C.top();
                int bdx = B.top(); B.pop();
                G[bdx] = cdx;
                sz[cdx]++;

                if (sz[cdx] == k) {
                    // clear
                    C.pop();
                    ord[cdx] = --ordCnt;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        ans[ord[G[i]]].push_back(i);
    }

    for (auto a : ans) {
        for (auto b : a) cout << b + 1 << ' ';
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}