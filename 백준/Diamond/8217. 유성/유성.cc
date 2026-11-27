#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second

int n, m, k;
vector<ll> fw_1, fw_2;

void update(int ix, ll num, vector<ll>& fw) {
    while (ix <= m) {
        fw[ix] += num;
        ix += ix & -ix;
    }
}
ll ssum(int ix,vector<ll>&fw) {
    ll res = 0;
    while (ix) {
        res += fw[ix];
        ix -= ix & -ix;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    vector<vector<int>> o(n+1);
    vector<ll> p(n+1);
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        o[x].push_back(i);
    } // 담당구역
    for (int i = 1; i <= n; i++) cin >> p[i]; // 목표량

    int q;
    cin >> q;

    vector<tuple<ll, ll, ll>> inp(q);
    for (int i = 0; i < q; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        inp[i] = { a, b, c };
    }

    vector<pair<ll, ll>> ans(n+1);
    for (int i = 1; i <= n; i++) {
        ans[i] = { 0, q-1 };

    }
    vector<int> res(n + 1, -1);
    vector<vector<int>> md(q);

    while (1) {
        bool is = 0;
        md = vector<vector<int>>(q);
        fw_1 = vector<ll>(m + 3);
        fw_2 = vector<ll>(m + 3);


        for (int i = 1; i <= n; i++) {
            if (ans[i].y >= ans[i].x) {
                is = 1;
                md[(ans[i].x + ans[i].y)/2].push_back(i);
            }
        }
        
        if (!is) break;
        for (int i = 0; i < q; i++) {
            ll l, r, v;
            tie(l, r, v) = inp[i];

            if (l > r) {
                update(1, v, fw_1);
                //update(1, 0, fw_2);
                swap(l, r);
                l++, r--, v *= -1;
            }

            if (l <= r) {
                update(l, v, fw_1); update(r + 1, -v, fw_1);
                update(l, (1 - l) * v, fw_2); update(r + 1, r * v, fw_2);
            }


            for (auto idx : md[i]) {
                ll tot = 0;

                for (auto area : o[idx]) {
                    tot += ssum(area, fw_1) * area + ssum(area, fw_2);
                    tot -= ssum(area - 1, fw_1) * (area - 1) + ssum(area - 1, fw_2);
                    if (tot >= p[idx]) break;
                }

                if (tot >= p[idx]) {
                    res[idx] = i;
                    ans[idx].y = i-1;
                }
                else ans[idx].x = i+1;
            }
        }


    }

    for (int i = 1; i <= n; i++) {
        if (res[i] == -1) cout << "NIE\n";
        else cout << res[i]+1 << '\n';
    }

}