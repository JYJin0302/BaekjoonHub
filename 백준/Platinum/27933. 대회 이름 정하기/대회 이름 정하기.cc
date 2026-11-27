#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<ll> A(n);
    for (auto& i : A) cin >> i;

    vector<int> idx;
    vector<ll> val;

    idx.push_back(0);
    ll pv = A[0];
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) pv = max(pv, A[i]);
        else {
            val.push_back(pv);
            pv = A[i];
            idx.push_back(i);
        }
    }
    val.push_back(pv);

    int sz = val.size();
    vector<ll> sA(sz);
    sA[0] = val[0];
    for (int i = 1; i < sz; i++) sA[i] = sA[i - 1] + val[i];

    vector<ll> preM(n), sufM(n);
    preM[0] = A[0];
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) preM[i] = max(preM[i - 1], A[i]);
        else {
            preM[i] = A[i];
        }
    }
    sufM[0] = A[n-1];
    for (int i = n-2; i >= 0; i--){
        if (s[i] == s[i + 1]) sufM[i] = max(sufM[i + 1], A[i]);
        else {
            sufM[i] = A[i];
        }
    }

    int q;
    cin >> q;
    while (q--) {

        int a, b;
        cin >> a >> b;
        a--, b--;

        int ai = upper_bound(idx.begin(), idx.end(), a) - idx.begin()-1;
        int adx = idx[ai];
        int bi = upper_bound(idx.begin(), idx.end(), b) - idx.begin() - 1;
        int bdx = idx[bi];

        if (adx == bdx) {
            cout << "YK 0\n";
            continue;
        }

        ll valY = 0, valK = 0;
        if (s[a] == 'Y') {
            if (s[b] == 'Y'){
                valY = sA[bi - 1] - sA[ai];
                valY += sufM[a];

                valK = sA[bi - 1] - sA[ai] + preM[b];
            }
            else {

                valY = sA[bi - 1] - sA[ai] + sufM[a] + preM[b];
                valK = sA[bi - 1] - sA[ai];
            }
        }
        else {
            if (s[b] == 'Y') {
                valK = sA[bi - 1] - sA[ai] + sufM[a] + preM[b];
                valY = sA[bi - 1] - sA[ai];
            }
            else {

                valK = sA[bi - 1] - sA[ai];
                valK += sufM[a];

                valY = sA[bi - 1] - sA[ai] + preM[b];
            }

        }

        if (valK == valY) {
            cout << "YK " << valK << '\n';
        }
        else if (valK > valY) {
            cout << 'K' << ' ' << valK << '\n';
        }
        else cout << "Y " << valY << '\n';
    }


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