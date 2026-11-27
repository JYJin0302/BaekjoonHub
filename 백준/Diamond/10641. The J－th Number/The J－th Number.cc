#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
using ll = long long;

struct Node {
    ll val;
    int ldx, rdx;

    Node() {
        ldx = rdx = -1;
        val = 0;
    }
} root;

ll lazy[20001010];
Node lst[20001010];
int sz = 0;

void goLazy(int l, int r, Node& curr, int cdx) {
    if (lazy[cdx]) {
        curr.val += lazy[cdx] * ((ll)r - l + 1);

        if (l != r) {
            if (curr.ldx == -1) {
                curr.ldx = ++sz;
            }
            lazy[curr.ldx] += lazy[cdx];
            if (curr.rdx == -1) {
                curr.rdx = ++sz;
            }
            lazy[curr.rdx] += lazy[cdx];
        }
        lazy[cdx] = 0;
    }
}

ll update(int l, int r, int sl, int sr, int val, Node& curr, int cdx) {
    goLazy(l, r, curr, cdx);
    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr) {
        lazy[cdx]++;
        goLazy(l, r, curr, cdx);
        //cout << "Go upd: " << l << ' ' << r << ' ' << curr.val << '\n';
        return (ll)r - l + 1;
    }

    int md = (l + r) >> 1;
    ll df = 0;
    if (curr.ldx == -1) {
        curr.ldx = ++sz;
    }
    df += update(l, md, sl, sr, val, lst[curr.ldx], curr.ldx);
    if (curr.rdx == -1) {
        curr.rdx = ++sz;
    }
    df += update(md + 1, r, sl, sr, val, lst[curr.rdx], curr.rdx);
    curr.val += df;
    //  cout << "go upd: " << l << ' ' << r << ' ' << curr.val << '\n';
    return df;
}

ll getSum(int l, int r, int n, int sl, int sr, Node& curr, int cdx) {
    goLazy(l, r, curr, cdx);
    //cout << "getsum: " << l << ' ' << r << '\n';
    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr) {
         //cout << "Get val: " << l << ' ' << r << ' ' << curr.val << '\n';
        return curr.val;
    }

    int md = (l + r) >> 1;
    ll res = 0;
    if (curr.ldx != -1) res += getSum(l, md, n * 2, sl, sr, lst[curr.ldx], curr.ldx);
    if (curr.rdx != -1) res += getSum(md + 1, r, n * 2 + 1, sl, sr, lst[curr.rdx], curr.rdx);
    return res;
}

vector<ll> num;
int getIdx(ll x) {
    return lower_bound(num.begin(), num.end(), x) - num.begin();
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, q;
    cin >> n >> m >> q;

    vector<pair<ll, pair<ll, ll>>> edge;
    for (register int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;

        edge.push_back(mp(c, mp(a, b)));
        num.push_back(c);
    }
    sort(edge.begin(), edge.end());

    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());

    vector<pair<ll, pair<ll, ll>>> query(q);
    for (register int i = 0; i < q; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        query[i] = mp(c, mp(a, b));
    }

    vector<pair<ll, ll>> md(q, mp(0, num.size() - 1));
    vector<ll> ans(q, -1);

    while (1) {

        //cout << "-----------------Go pst\n";
        bool ck = 0;
        vector<vector<ll>> qList(num.size());

        for (register int i = 0; i < q; i++) {
            if (md[i].first <= md[i].second) {
                ck = 1;
                qList[(md[i].first + md[i].second) / 2].push_back(i);
            }
        }

        if (!ck) break;

        for (register int i = 0; i <= sz; i++) {
            lst[i] = Node();
            lazy[i] = 0;
        }
        root = lst[0];
        sz = 0;

        register ll currx = 0;
        register ll ix = 0;

        while (ix < m) {

           // cout << "curr: " << ix << ' ' << num[currx] << '\n';
            while (ix < m && currx < num.size() && edge[ix].first == num[currx]) {
                int a, b;
                tie(a, b) = edge[ix].second;

               // cout << "upd: " << a << ' ' << b << '\n';
                update(1, n, a, b, 0, root, 0);
                ix++;
            }

            /*cout << "Track: ";
            for (int f = 1; f <= n; f++) cout << track[f] << ' ';
            cout << '\n';*/

            for (auto idx : qList[currx]) {
                ll l, r, w;
                tie(l, r) = query[idx].second;
                w = query[idx].first;
                ll sval = getSum(1, n, 1, l, r, root, 0);
               // cout << "check: " << idx << ' ' << l << ' ' << r << ' ' << w << '\n' << sval << '\n';

                if (sval >= w) {
                    // ok
                    //cout << "ok\n";

                    ans[idx] = num[currx];
                    md[idx].second = currx - 1;
                }
                else {
                    //cout << "no\n";
                    md[idx].first = currx + 1;
                }
            }


            currx++;
        }

    }

    for (int i = 0; i < q; i++) {
        assert(ans[i] != -1);
        cout << ans[i] << '\n';
    }
}