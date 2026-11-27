#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using ld = long double;
#define all(x) x.begin(), x.end()
#define x first
#define y second
#define mp make_pair

ll gcd(ll a, ll b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
}

void solve() {
    ll n;
    cin >> n;

    ll den = 1, num = 0;

    vector<ll> A(n);
    for (auto& i : A) cin >> i;

    stack<pair<ll, ll>> st;
    for(int i = 0; i < n; i++){
        ll f = A[i];
        while (!st.empty()) {
            auto [a, b] = st.top();
            if (a > f) {
                ll tx = A[b + 1];
                if (tx < f) {
                    ll d = f - tx;
                    ll angle = a - tx;

                    ll tden = angle;
                    ll tnum = tden * (i - b - 1) + d;

                    ll g = gcd(tden, tnum);
                    tden /= g;
                    tnum /= g;

                    if (den * tnum > tden * num) {
                        den = tden;
                        num = tnum;
                    }
                }

                break;
            }
            else st.pop();
        }
        st.push(mp(A[i], i));
    }
    while (!st.empty()) st.pop();

    reverse(all(A));
    for (int i = 0; i < n; i++) {
        ll f = A[i];
        while (!st.empty()) {
            auto [a, b] = st.top();
            if (a > f) {
                ll tx = A[b + 1];
                if (tx < f) {
                    ll d = f - tx;
                    ll angle = a - tx;

                    ll tden = angle;
                    ll tnum = tden * (i - b - 1) + d;
                    ll g = gcd(tden, tnum);
                    tden /= g;
                    tnum /= g;
                    if (den * tnum > tden * num) {
                        den = tden;
                        num = tnum;
                    }
                }

                break;
            }
            else st.pop();
        }
        st.push(mp(A[i], i));
    }
    while (!st.empty()) st.pop();

    if (num == 0) cout << 0 << '\n';
    else cout << num << '/' << den << '\n';

}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}