#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll fastPow(ll b, ll ex, ll m) {
    ll res = 1;
    while (ex) {
        if (ex % 2) res = res * b % m;
        b = b * b % m;
        ex /= 2;
    }
    return res;
}

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };


void solve() {

    int n;
    cin >> n;

    map<string, int> cnt;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int x;
        cin >> x;
        cnt[s] += x;
    }

    map<string, int>::iterator iter;
    for (iter = cnt.begin(); iter != cnt.end(); iter++) {
        if (iter->second == 5) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO";

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}