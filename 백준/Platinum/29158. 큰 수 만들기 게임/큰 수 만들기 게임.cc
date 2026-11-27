#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmp(ll a, ll b) {
    string sa = to_string(a);
    string sb = to_string(b);
    return sa + sb > sb + sa;

}

string addSt(string a, string b) {

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int pv = 0;
    string res;

    int ix = 0;
    while (ix < a.size() || ix < b.size()) {
        int val = pv;
        pv = 0;
        if (ix < a.size()) {
            val += (a[ix] - '0');
        }
        if (ix < b.size()) {
            val += (b[ix] - '0');
        }

        if (val >= 10) {
            val -= 10;
            pv = 1;
        }

        res += char('0' + val);
        ix++;
    }
    if (pv) res += '1';

    reverse(res.begin(), res.end());
    return res;

}

void solve() {

    ll n;
    cin >> n;

    if (n == 2) {
        cout << 3;
        return;
    }

    ll tn = n;
    vector<ll> A, B;
    for (ll i = 2; i * i <= n; i++) {
        if (tn % i == 0) {
            while (tn % i == 0) {
                tn /= i;
                A.push_back(i);
            }
        }
    }
    if (tn != 1) A.push_back(tn);

    ll tval = 1;
    while (tval*2 < n) {
        tval *= 2;
        B.push_back(2);
    }

    if (tval >= 2) {
        tval /= 2;
        tval *= 3;

        if (tval < n) {
            B.pop_back();
            B.push_back(3);
        }
    }

    sort(A.begin(), A.end(), cmp);
    reverse(B.begin(), B.end());

    string ans1, ans2;
    for (auto i : A) {
        string tmp = to_string(i);
        for (char k : tmp) ans1 += k;
    }

    for (auto i : B) {
        string tmp = to_string(i);
        for (char k : tmp) ans2 += k;
    }

   // cout << ans1 << '\n' << ans2 << '\n';

    string res = addSt(ans1, ans2);
    cout << res;


}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }

}