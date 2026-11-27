#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second



void solve() {

    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& i : A) cin >> i;

    ld val = 1e18;
    int as, aa, ac;
    as = aa = ac = -1;

    int m = 256;
    for (int s = 0; s <= 15; s++) {
        for (int a = 0; a <= 15; a++) {
            for (int c = 0; c <= 15; c++) {

                ld res = 0;
                int ts = s;
                vector<int> nA;
                for (int i = 0; i < n; i++) {
                    ts = ts * a + c;
                    ts %= m;
                    nA.push_back((A[i] + ts) % m);
                }

                sort(all(nA));

                int ix = 0;
                while (ix < n) {
                    int nx = ix;
                    while (nx < n && nA[nx] == nA[ix]) nx++;

                    int cnt = nx - ix;
                    res += -1.0 * cnt / n * log(1.0 * cnt / n);

                    ix = nx;
                }

                if (val > res) {
                    val = res;
                    as = s;
                    aa = a;
                    ac = c;
                }

            }
        }
    }

    cout << as << ' ' << aa << ' ' << ac << '\n';
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}