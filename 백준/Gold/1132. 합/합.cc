#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll INF = 1e13;
    int n;
    string s;
    cin >> n;
    vector<bool> front(10);
    vector<ll> base(10);
    for (int i = 0; i < n; i++) {
        cin >> s;
        front[(int)(s[0] - 'A')] = true;
        int size = s.size();
        for (char i : s) {
            base[i - 'A'] += pow(10, size - 1);
            size--;
        }
    }
    ll frontcnt = 0;
    for (auto i : front) { if (i == 1) frontcnt++; }


    ll cnt = 0;
    for (ll i : base) if (i != 0) cnt++;
    ll ans = 0;


    if (cnt == 10) {
        bool zeroused = false;
        while (cnt>1) {
            int minn = min_element(base.begin(), base.end()) - base.begin();
            if (!zeroused && !front[minn]) {
                ans += 0;
                zeroused = true;
                cnt++;
            }
            else {
                ans += base[minn] * (11 - cnt);
            }

            base[minn] = INF;
            cnt--;
        }
        cout << ans;
        return 0;
    }


    for (ll i = 0; i < cnt; i++) {
        int maxx = max_element(base.begin(), base.end()) - base.begin();

        ans += base[maxx] * (9 - i);
        base[maxx] = 0;
    }
    cout << ans;

}