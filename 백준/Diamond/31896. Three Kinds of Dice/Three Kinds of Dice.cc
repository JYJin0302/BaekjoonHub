#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

pair<ll, ll> S;
bool cmp(pair<ll, ll> p1, pair<ll, ll> p2) {
    ll val = 1ll * (p1.x - S.x) * (p2.y - S.y) - 1ll * (p1.y - S.y) * (p2.x - S.x);
    if (val != 0) return val > 0;
    ll d1 = 1ll * (p1.x - S.x) * (p1.x - S.x) + 1ll * (p1.y - S.y) * (p1.y - S.y);
    ll d2 = 1ll * (p2.y - S.y) * (p2.y - S.y) + 1ll * (p2.x - S.x) * (p2.x - S.x);
    return d1 < d2;
}

int ccw(pair<ll, ll> v1, pair<ll, ll> v2, pair<ll, ll> v3) {
    ll res = 0;
    res += v1.x * v2.y + v2.x * v3.y + v3.x * v1.y;
    res -= v1.y * v2.x + v2.y * v3.x + v3.y * v1.x;
    if (res) res /= abs(res);
    return res;
}

void solve() {

    int n, m;
    cin >> n;
    vector<ll> A(n);
    for (auto& i : A) cin >> i;

    cin >> m;
    vector<ll> B(m);
    for (auto& i : B) cin >> i;

    sort(all(A));
    sort(all(B));


    // winner check
    ll cnt = 0;
    for (auto f : A) {
        int ix = lower_bound(all(B), f) - B.begin();
        int ix2 = upper_bound(all(B), f) - B.begin();

        cnt += ix;
        cnt -= m - ix2;
    }

    if (cnt < 0) {
        swap(A, B);
        swap(n, m);
    }

    /* cout << "d1: ";
     for (auto f : A) cout << f << ' ';
     cout << '\n';

     cout << "d2: ";
     for (auto f : B) cout << f << ' ';
     cout << '\n';*/

     // d2 >= **d3** >= d1 
    vector<ll> num = { 1 };
    for (auto f : A) num.push_back(f);
    for (auto f : B) num.push_back(f);


    sort(all(num));

    int sz = num.size();
    for (int i = 1; i < sz; i++) {
        num.push_back((num[i] + num[i - 1]) >> 1);
    }
    num.push_back(num[sz - 1] + 1);

    sort(all(num));
    num.erase(unique(all(num)), num.end());

    vector<pair<ll, ll>> v;
    for (auto f : num) {
        int ix1 = lower_bound(all(A), f) - A.begin();
        int ix2 = upper_bound(all(A), f) - A.begin();
        int val1 = ix1 * 2 + ix2 - ix1;

        ix1 = lower_bound(all(B), f) - B.begin();
        ix2 = upper_bound(all(B), f) - B.begin();
        int val2 = ix1 * 2 + ix2 - ix1;

        v.push_back(mp(val1, val2));
    }

    sort(all(v));
    v.erase(unique(all(v)), v.end());

    S = v[0];
    sort(1 + all(v), cmp);
    v.push_back(v[0]);

    //for (auto [a, b] : v) cout << a << ' ' << b << '\n';

    vector<pair<ll, ll>> ch;
    for (auto f : v) {
        while (ch.size() >= 2) {
            int sz = ch.size();
            pair<ll, ll> v2 = ch[sz - 1];
            pair<ll, ll> v1 = ch[sz - 2];
            if (ccw(v1, v2, f) < 0) {
                ch.pop_back();
            }
            else break;
        }
        ch.push_back(f);


        //cout << "convex : ";
       // for (auto [a, b] : ch) cout << a << ' ' << b << " | ";
       // cout << '\n';
    }

    sz = ch.size();

    ld ans1 = 1e18;
    ld ans2 = -1e18;
    for (int i = 1; i < sz; i++) {
        pair<ll, ll> p1, p2;
        p1 = ch[i - 1], p2 = ch[i];

        if (p1.x > p2.x) swap(p1, p2);
        if (p1.x < n && p2.x > n) {
            ld val = (n - p1.x) * p2.y + (p2.x - n) * p1.y;
            val /= p2.x - p1.x;

            ans1 = min(ans1, val);
            // cout << "Check1: " << i << '\n';
        }

        if (p1.y > p2.y) swap(p1, p2);
        if (p1.y < m && p2.y > m) {
            ld val = (m - p1.y) * p2.x + (p2.y - m) * p1.x;
            val /= p2.y - p1.y;

            ans2 = max(ans2, val);
            //cout << "Check2 : " << i << '\n';
        }

    }

    for (auto [a, b] : ch) {
        if (a >= n) ans1 = min(ans1, (ld)b);
        if (b <= m) ans2 = max(ans2, (ld)a);
    }

    ans1 *= 0.5 / m;
    ans2 *= 0.5 / n;

    cout << ans1 << ' ' << ans2 << '\n';


}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}