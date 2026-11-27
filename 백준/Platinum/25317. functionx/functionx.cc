#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> num, seg;

map<ll, bool> zero;

void update(int l, int r, int n, int u) {

    if (l == u && r == u) {
        seg[n]++;
        return;
    }
    if (l > u || r < u) return;

    int mid = (l + r) / 2;

    update(l, mid, n * 2, u);
    update(mid + 1, r, n * 2+1, u);
    seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int cnt(int l, int r, int n, int sl, int sr) {

    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr) return seg[n];

    int mid = (l + r) / 2;

    return cnt(l, mid, n * 2, sl, sr) + cnt(mid + 1, r, n * 2 + 1, sl, sr);
}


int main() {

    int q;
    cin >> q;

    vector<tuple<ll, ll, ll>> inp;
    while (q--) {

        int t;
        cin >> t;

        if (t == 1) {
            ll a, b, v = -1;
            cin >> a >> b;
            inp.push_back({ t, a, b });

            if (a != 0) {
                if (a < 0) a *= -1, b *= -1;

                ll v = 0;
                if (b >= 0) v = -b / a;
                else v = (-b +a-1)/ a;

                num.push_back(v);
            }            
        }
        else {
            ll x;
            cin >> x;
            inp.push_back({ t, x, 0});
            num.push_back(x);
        }
    }
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());

    // for (auto i : num) cout << i << ' ';

    int n = num.size();
    map<ll, int> idx;
    for (int i = 0; i < n; i++) {
        idx[num[i]] = i;
    }
    int sn = 1;
    while (sn < n) sn *= 2;
    seg = vector<ll>(sn * 2);

    int totNeg = 1, totZero = 1, totNum = 0;
    for (auto i : inp) {

        ll t, a, b;
        tie(t, a, b) = i;
        

        if (t == 1) {
            
            if (a != 0) {
                
                if (a < 0) totNeg *= -1, a*= -1, b*= -1;
                ll v = 0;
                if (b >= 0) v = -b / a;
                else v = (-b + a - 1) / a;

                if (a * v + b == 0) zero[v] = 1;
                int ix = idx[v];
                update(0, sn - 1, 1, ix);
            }
            else {
                if (b == 0) totZero = 0;
                else if (b < 0) totNeg *= -1;
                totNum--;
            }

            totNum++;
        }
        else {

            int ix = idx[a];
            int val = cnt(0, sn - 1, 1, 0, ix);

            int isZero = 1;
            if (zero[a] == 1) isZero = 0;

            int res = 0;
            if ((totNum - val) % 2 == 1) res = -1 * totNeg * totZero * isZero;
            else res = totNeg * totZero * isZero;

            if (res > 0) cout << '+';
            else if (res == 0) cout << 0;
            else cout << '-';
            cout << '\n';
        }
    }
}