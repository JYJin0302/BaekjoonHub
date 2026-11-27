#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

bool isV[26];

void solve() {

    string ss = "AEIOUY";
    for (auto f : ss) isV[f - 'A'] = 1;

    int n;
    cin >> n;

    vector<string> A(n);
    for (auto& i : A) cin >> i;

    vector<int> dp(3, 1e8);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        vector<int> tmp(3, 1e8);


        for (int j = 0; j < min(3, int(A[i].size())); j++) {
            string ts = A[i].substr(0, j + 1);

            int cp = 0;
            for (auto f : ts) {
                if (!isV[f - 'A']) cp++;
                else break;
            }
            int cs = 0;
            for (int f = j; f >= 0; f--) {
                if (!isV[ts[f] - 'A']) cs++;
                else break;
            }

            
            for (int f = 0; f < 3; f++) {
                if (f + cp < 3) {
                    int nx = cs;
                    if (cs == j + 1) nx += f;
                    if (nx < 3) tmp[nx] = min(tmp[nx], dp[f] + j + 1);
                }
            }


        }
        swap(dp, tmp);;
    }

    int ans = *min_element(all(dp));
    if (ans == 1e8) cout << '*';
    else cout << ans;
    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}