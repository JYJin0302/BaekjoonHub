#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

void solve() {

    int n;
    cin >> n;

    ll cost = -1;
    vector<ll> A(1010);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        ll x;
        cin >> x;

        if (s == "jinju") cost = x;
        else{
            if (x > 1000) x = 1001;
            A[x]++;
        }
    }

    int cnt = 0;
    for (int i = cost+1; i <= 1001; i++) cnt += A[i];

    cout << cost << '\n' << cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(3);
    solve();
    return 0;
}
