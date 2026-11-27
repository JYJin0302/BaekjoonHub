#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

int char2int(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 'A';
    }
    return c - 'a' + 26;
}

void solve() {

    int n, m;
    cin >> n >> m;

    string A, B;
    cin >> A >> B;

    vector<int> cntA(52), cntB(52);
    for (auto f : A) {
        cntA[char2int(f)]++;
    }
    int tot = 0;
    for (int i = 0; i < 52; i++)if (cntA[i] != 0) tot++;

    int l = 0, r = 0, ans = 0;
    while (r < m) {
        int curr = char2int(B[r]);
        cntB[curr]++;

        while (cntB[curr] > cntA[curr]) {
            int pre = char2int(B[l++]);
            cntB[pre]--;
        }
        
        bool ok = 1;
        for (int i = 0; i < 52; i++) {
            if (cntA[i] != cntB[i]) {
                ok = 0;
                break;
            }
        }
        if (ok) ans++;
        r++;
    }
    cout << ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) solve();
}