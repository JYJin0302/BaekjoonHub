#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

int n, a, b, sz;
const int INF = 1e8;

pair<int, int> segL[555555], segR[555555];
int dist[202020];

void update(int ix, pair<int, int> seg[], int val, bool p, int l = 0, int r = sz-1, int tn = 1) {

    if (l > ix || r < ix) return;

    if (l == ix && r == ix) {
        seg[tn] = mp(val, ix);
        return;
    }

    int mid = (l + r) >> 1;
    update(ix, seg, val, p, l, mid, tn * 2);
    update(ix, seg, val, p, mid+1, r, tn * 2 + 1);

    if (p) seg[tn] = min(seg[tn * 2], seg[tn * 2 + 1]);
    else seg[tn] = max(seg[tn * 2], seg[tn * 2 + 1]);

}

pair<int, int> getVal(int sl, int sr, pair<int, int> seg[], bool p, int l = 0, int r = sz-1, int tn = 1) {
    if (l > sr || r < sl) {
        if (p) return mp(INF, -1);
        return mp(-INF, -1);
    }

    if (l >= sl && r <= sr) return seg[tn];

    int mid = (l + r) >> 1;

    pair<int, int> p1 = getVal(sl, sr, seg, p, l, mid, tn * 2);
    pair<int, int> p2 = getVal(sl, sr, seg, p, mid+1, r, tn * 2 + 1);

    if (p) return min(p1, p2);
    return max(p1, p2);

}

void solve() {


    cin >> n >> a >> b;
    a--, b--;

    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    sz = 1;
    while (sz < n) sz *= 2;

    for (int i = 1; i < sz * 2; i++) {
        segR[i] = mp(INF, -1); // min
        segL[i] = mp(-INF, -1); // max
    }
    for (int i = 0; i < n; i++) dist[i] = -1;

    for (int i = 0; i < n; i++) {
        update(i, segL, i + A[i], 0);
        update(i, segR, i - A[i], 1);
    }


    update(a, segL, -INF, 0);
    update(a, segR, INF, 1);

    dist[a] = 0;
    queue<int> q;
    q.push(a);
    while (!q.empty()) {

        int x = q.front();
        q.pop();

       // cout << "Go: " << x << ' ' << dist[x] << '\n';

        while (1) {
            pair<int, int> res = getVal(x, min(n-1 ,x + A[x]), segR, 1);

            //cout << "Get min : " << x << " - " << min(n-1, x + A[x]) << " -> " << res.first << ' ' << res.second << '\n';
            if (res.first <= x) {
                dist[res.second] = dist[x] + 1;

                update(res.second, segR, INF, 1);
                update(res.second, segL, -INF, 0);
                q.push(res.second);
            }
            else break;
        }

        while (1) {
            pair<int, int> res = getVal(max(0, x-A[x]), x, segL, 0);
            //cout << "Get max : " << max(0, x - A[x]) << " - " << x << " -> " << res.first << ' ' << res.second << '\n';
            if (res.first >= x) {
                dist[res.second] = dist[x] + 1;

                update(res.second, segL, -INF, 0);
                update(res.second, segR, INF, 1);
                q.push(res.second);
            }
            else break;
        }
    }

    cout << dist[b] << '\n';

}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}