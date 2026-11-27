#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

int C[505];
int D[505];
int A[505];

int minCost[26];

vector<int> idxList[26];

void solve() {
    
    for (int i = 0; i < 26; i++) minCost[i] = -1;
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= m; i++) {
        char c;
        cin >> c >> D[i] >> A[i];

        C[i] = c - 'a';
        int ix = C[i];
        
        if (minCost[ix] == -1) minCost[ix] = A[i];
        else minCost[ix] = min(minCost[ix], A[i]);
    }

    vector<int> curr(n);
    for (int i = 0; i < n; i++) {
        cin >> curr[i];

        int tc = C[curr[i]];
        idxList[tc].push_back(i);
    }
    string s;
    cin >> s;

    vector<int> target(k);
    for (int i = 0; i < k; i++) target[i] = s[i] - 'a';

    int ans = 1e9;
    for (int i = 0; i + k <= n; i++) {
        int val = 0;
        vector<int> need(26), able(26);

        for (int j = 0; j < k; j++) {
            if (target[j] != C[curr[i + j]]) {
                val += D[curr[i + j]];
                need[target[j]]++;
                able[C[curr[i + j]]]++;
            }
        }

        for (int f = 0; f < 26; f++) {
            if (need[f] <= able[f]) continue;
            if (minCost[f] == -1) {
                cout << -1;
                return;
            }
            int nd = need[f] - able[f];

            vector<int> tmp;
            for (auto j : idxList[f]) {
                if (j < i || j >= i + k) {
                    if (D[curr[j]] < minCost[f]) tmp.push_back(D[curr[j]]);
                }
            }
            sort(tmp.begin(), tmp.end());
            while (tmp.size() < nd) tmp.push_back(minCost[f]);

            int tt = 0;
            for (int j = 0; j < nd; j++) tt += tmp[j];
            val += tt;
        }

        ans = min(ans, val);
    }
    cout << ans << '\n';

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}