#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

vector<ll> A;
struct Data {
    map<int, ld> p;
    // idx, winning rate
};

void solve() {

    int n;
    cin >> n;

    A = vector<ll>(n);
    for (auto& i : A) cin >> i;
    sort(1 + all(A));
    reverse(all(A));

    /*for (auto f : A) cout << f << ' ';
    cout << '\n';*/
    queue<Data> q;
    int tn = 1 << (int)log2(n);
    for (int i = 0; i < n; i++) {
        if (i < 2 * (n - tn)) {
            // get A[i], A[i+1]
            ld p1 = 1.0 * A[i] / (A[i] + A[i + 1]);
            ld p2 = 1 - p1;
            Data d1;
            d1.p[i] = p1;
            d1.p[i + 1] = p2;
            q.push(d1);
            i++;
        }
        else {
            Data d1;
            d1.p[i] = 1.0;
            q.push(d1);
        }
    }

    while (q.size() > 1) {
        Data d1 = q.front(); q.pop();
        Data d2 = q.front(); q.pop();
        /*cout << "Combine: ";
        for (auto& f : d1.p) cout << '{' << f.first << ' ' << f.second << "} ";
        cout << " | ";
        for (auto& f : d2.p) cout << '{' << f.first << ' ' << f.second << "} ";
        cout << '\n';*/
        Data nD;
        for (auto& [i1, p1] : d1.p) {
            for (auto& [i2, p2] : d2.p) {
                ld np = p1 * p2 * A[i1] / (A[i1] + A[i2]);
                nD.p[i1] += np;
                nD.p[i2] += p1 * p2 - np;
            }
        }
        /*for (auto& f : nD.p) cout << '{' << f.first << ' ' << f.second << "} ";
        cout << '\n';*/
        q.push(nD);
    }

    Data res = q.front(); q.pop();
    // for (auto f : res.p) cout << f.first << ' ' << f.second << " | ";

    cout << setprecision(15);
    cout << res.p[n - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}