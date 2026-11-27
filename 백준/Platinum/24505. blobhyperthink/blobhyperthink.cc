#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int n;
const ll mod = 1e9 + 7;
vector<ll> fw;

void update(int ix, ll v) {
    while (ix <= n) {
        fw[ix] += v;
        fw[ix] %= mod;
        ix += ix & -ix;
    }
}
ll ssum(int ix) {
    ll res = 0;
    while (ix) {
        res += fw[ix];
        res %= mod;
        ix -= ix & -ix;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;


    vector<ll> A(n+1);
    for (int i = 1; i <= n; i++) cin >> A[i];
 
    vector<ll> val(n + 1, 1), tval(n+1);
    val[0] = 0;

    fw = vector<ll>(n + 1);

    for (int x = 2; x <= 11; x++) {

        for (int i = 1; i <= n; i++) {

            tval[i] = ssum(A[i] - 1);
            update(A[i], val[i]);
        }

        swap(val, tval);
        fw = vector<ll>(n + 1);
    }

    ll ans = 0;
    for (auto i : val) {
        ans += i;
        ans %= mod;
    }
    cout << ans;

}