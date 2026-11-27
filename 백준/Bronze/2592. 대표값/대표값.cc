#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {    
    vector<int> A(10);
    for (auto& i : A) cin >> i;
    sort(all(A));

    int tot = 0;
    for (auto f : A) tot += f;
    tot /= 10;

    int val = 0, cnt = 0;
    int ix = 0;
    while (ix < 10) {
        int nx = ix;
        while (nx < 10 && A[nx] == A[ix]) nx++;

        if (cnt < nx - ix) {
            cnt = nx - ix;
            val = A[ix];
        }
        ix = nx;
    }

    cout << tot << '\n' << val << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}