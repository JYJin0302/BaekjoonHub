#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

const ll mod = 998244353;

void solve() {

    int n;
    cin >> n;

    string s;
    cin >> s;

    int m;
    cin >> m;

    vector<bool> edgList(900);
    for (int i = 0; i < m; i++) {
        string ts;
        cin >> ts;

        int val = ts[0] - 'a';
        val = val * 26 + ts[1] - 'a';
        edgList[val] = 1;
    }

    vector<int> A(n);
    for (int i = 1; i < n; i++) {
        int val = s[i - 1] - 'a';
        val = val * 26 + s[i] - 'a';
        A[i] = val;
    }


    ll ans = 0;
    int l = 1, r = 1;
    vector<int> cntL(900), cntR(900);
    int ccL = 0, ccR = 0;
    for (int i = 1; i < n; i++) {
        l = max(l, i);
        r = max(r, i);

        while (l < n && edgList[A[l]] && ccL < m) {
            cntL[A[l]]++;
            if (cntL[A[l]] == 1) ccL++;
            l++;
        }

        while (r < n && edgList[A[r]]) {
            cntR[A[r]]++;
            if (cntL[A[r]] == 1) ccR++;
            r++;
        }

        if (ccL == m) {
            ans += r - l + 1;
        }

        if (edgList[A[i]]) {
            cntL[A[i]]--;
            if (cntL[A[i]] == 0) ccL--;
            cntR[A[i]]--;
            if (cntR[A[i]] == 0) ccR--;
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}