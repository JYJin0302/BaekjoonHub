#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair


pair<ll, ll> A[2525];
vector<ll> num;
int getIdx(ll x) {
    return lower_bound(num.begin(), num.end(), x) - num.begin();
}

int L[2525];
int R[7575];

bool vs[7575];

bool go(int ix) {

    ll v1, v2;
    tie(v1, v2) = A[ix];

    int nx = getIdx(v1 + v2);
    if (!vs[nx]) {
        vs[nx] = 1;
        if (R[nx] == -1 || go(R[nx])) {
            R[nx] = ix;
            L[ix] = nx;
            return 1;
        }
    }

    nx = getIdx(v1 - v2);
    if (!vs[nx]) {
        vs[nx] = 1;
        if (R[nx] == -1 || go(R[nx])) {
            R[nx] = ix;
            L[ix] = nx;
            return 1;
        }
    }

    nx = getIdx(v1 * v2);
    if (!vs[nx]) {
        vs[nx] = 1;
        if (R[nx] == -1 || go(R[nx])) {
            R[nx] = ix;
            L[ix] = nx;
            return 1;
        }
    }

    return 0;
}

void solve() {

    memset(L, -1, sizeof(L));
    memset(R, -1, sizeof(R));

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;

        num.push_back(a + b);
        num.push_back(a - b);
        num.push_back(a * b);

        A[i] = mp(a, b);
    }

    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());

    int m = num.size();

    for (int i = 0; i < n; i++) {

        memset(vs, 0, sizeof(vs));

        if (!go(i)) {
            cout << "impossible\n";
            return;
        }

    }

    for (int i = 0; i < n; i++) {

        ll a, b;
        tie(a, b) = A[i];

        ll nx = L[i];
        assert(nx != -1);

        nx = num[nx];



        if (nx == a + b) cout << a << " + " << b << " = " << nx << '\n';
        else if (nx == a - b) cout << a << " - " << b << " = " << nx << '\n';
        else if (nx == a * b) cout << a << " * " << b << " = " << nx << '\n';
        else exit(1);
    }


}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
  //  cin >> t;
    while (t--) {
        solve();
    }
}