#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

const ll INF = 1e10;

ll gcd(ll a, ll b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
}

ll ansp = 1, ansq = 0;

void ansSet(ll p2, ll q2) {
    ll g = gcd(p2, q2);
    p2 /= g, q2 /= g;
    if (ansp * q2 >= ansq * p2) {
        ansp = p2;
        ansq = q2;
    }
}

void solve() {

    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& i : A) cin >> i;

    int tn = n;
    vector<int> p;
    for (int i = 2; i * i <= tn; i++) {
        if (tn % i == 0) {
            p.push_back(i);
            while (tn % i == 0) tn /= i;
        }
    }
    if (tn != 1) p.push_back(tn);

    ansp = 1, ansq = 0;
    for (auto k : p) {
        ll tp = 0, tq = 0;
        vector<ll> g(k);
        for (int i = 0; i < n; i++) g[i % k] += A[i];

        multiset<ll> ms;
        for (auto f : g) ms.insert(f);

        tp = *ms.rbegin();
        tq = *ms.begin();
        ansSet(tp, tq);        
        for (int i = 1; i < n; i++) {
            int dif = A[i] - A[0];
            int pg = (i - 1) % k;

            ms.erase(ms.lower_bound(g[pg]));
            g[pg] += dif;
            ms.insert(g[pg]);

            pg = i % k;
            ms.erase(ms.lower_bound(g[pg]));
            g[pg] -= dif;
            ms.insert(g[pg]);

            tp = *ms.rbegin();
            tq = *ms.begin();
            ansSet(tp, tq);
        }
    }

    assert(ansq != 0);
    cout << ansp << ' ' << ansq << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}