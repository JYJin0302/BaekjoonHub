#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define x first
#define y second


ll gcd(ll a, ll b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
}

void solve() {

    int n;
    cin >> n;

    stack<pair<int, pair<ll, ll>>> st;
    st.push(mp(0, mp(0, 1)));

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;

        if (c == '(') {
            cnt = 0;
        }
        else if (c == ')') {
            if (cnt != 3) {
                cout << -1;
                return;
            }
            pair<ll, ll> A, B, C;
            C = st.top().second; st.pop();
            B = st.top().second; st.pop();
            A = st.top().second; st.pop();

            pair<ll, ll> tmp = mp(B.x * C.y, B.y * C.x);
            ll g = gcd(tmp.x, tmp.y);
            tmp.x /= g, tmp.y /= g;

            tmp = mp(A.x * tmp.y + A.y * tmp.x, A.y * tmp.y);
            g = gcd(tmp.x, tmp.y);
            tmp.x /= g, tmp.y /= g;
            int nc = st.top().first;

            st.push(mp(nc, tmp));
        }
        else {
            int v = c - '0';
            ++cnt;
            st.push(mp(cnt, mp(v, 1)));
            if (cnt > 3) {
                cout << -1;
                return;
            }
        }
    }

    if (st.size() != 2) {
        cout << -1;
        return;
    }
    cout << st.top().y.x << ' ' << st.top().y.y << '\n';



}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
