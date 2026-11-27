#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<int> getfail(const vector<ll>& A) {
    int N = A.size();
    vector<int> fail(N);
    fail[0] = 0;
    for (int i = 1; i < N; i++) {
        int j = fail[i - 1];
        while (j > 0 && A[j] != A[i]) { j = fail[j - 1]; }
        if (A[j] == A[i]) { fail[i] = j + 1; }
    }
    return fail;
}

void solve() {

    int L;
    cin >> L;
    vector<ll> A(L);
    for (auto& i : A) cin >> i;
    vector<int> tmp = getfail(A);
    //for (auto f : tmp) cout << f << '\n';

    int p = L - tmp.back();
    ll l, r;
    cin >> l >> r;

    ll tot = 0; 
    for (int i = 0; i < p; i++) tot += A[i];

    ll d = (r - l) / p;
    ll ans = d * tot;

    l += d * p;

    d = r - l;
    l = (l % p + p) % p;

    while (d--) {
        ans += A[l];
        l = (l + 1) % p;
    }
    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}