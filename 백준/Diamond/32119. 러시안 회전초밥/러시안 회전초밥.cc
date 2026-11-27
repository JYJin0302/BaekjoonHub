#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second
#define pi pair<char, int>

vector<int> sa, lcp, c;

void get_sa(const string& A) {
    string a = A;
    a.push_back('A');
    int N = a.size();
    sa = vector<int>(N);
    c = vector<int>(N);
    vector<pi> tmp(N), new_tmp(N);
    for (int i = 0; i < N; i++) {
        tmp[i] = { a[i],i };
    }
    sort(tmp.begin(), tmp.end());

    for (int i = 0; i < N; i++) {
        sa[i] = tmp[i].second;
    }
    c[sa[0]] = 0;
    for (int i = 1; i < N; i++) {
        if (tmp[i].first == tmp[i - 1].first) {
            c[sa[i]] =
                c[sa[i - 1]];
        }
        else { c[sa[i]] = c[sa[i - 1]] + 1; }
    }
    for (ll k = 1; k < N; k <<= 1) {
        vector<pair<pair<int, int>, int>> tmp(N), new_tmp(N);
        for (int i = 0; i < N; i++) {
            tmp[i].first = { c[(sa[i] - k + N) % N],c[sa[i]]
            };
            tmp[i].second = (sa[i] - k + N) % N;
        }
        vector<int> cnt(N), p(N);
        for (int i = 0; i < N; i++) {
            cnt[tmp[i].first.first]++;
        }
        for (int i = 1; i < N; i++) {
            p[i] = p[i - 1] + cnt[i - 1];
            if (p[i] == N) { break; }
        }
        for (int i = 0; i < N; i++) {
            new_tmp[p[tmp[i].first.first]] = tmp[i];
            p[tmp[i].first.first]++;
        }
        swap(tmp, new_tmp);
        for (int i = 0; i < N; i++) { sa[i] = tmp[i].second; }
        c[sa[0]] = 0;
        for (int i = 1; i < N; i++) {
            if (tmp[i].first == tmp[i - 1].first) {
                c[sa[i]] = c[sa[i - 1]];
            }
            else {
                c[sa[i]] = c[sa[i - 1]] + 1;
            }
        }
        if (c[sa[N - 1]] == N - 1) { break; }
    }

}
void get_lcp(const string& A) {
    string a = A;
    a.push_back('A');
    int N = a.size();
    lcp = vector<int> (N);
    int d = 0;
    for (int j = 0; j < N - 1; j++) {
        int x = c[j]; int i = sa[x - 1];
        while (a[j + d] == a[i + d]) { ++d; }
        lcp[x] = d;
        d = max(d - 1, 0);
    }
}

int n, k;
int seg[404040];
const int INF = 0x3f3f3f3f;

void update(int ix, int val, vector<int>& v) {
    int tx = ix;
    for (ix += n; ix; ix >>= 1) {
        if (seg[ix] == INF || v[seg[ix]] > val) seg[ix] = tx;
    }
}

int getMin(int l, int r, vector<int>& v) {
    int res = INF;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
            if (res == INF || (seg[l] != INF && v[res] > v[seg[l]])) res = seg[l];
            ++l;
        }
        if (r & 1) {
            r--;
            if (res == INF || (seg[r] != INF && v[res] > v[seg[r]])) res = seg[r];
        }
    }
    return res;
}

int ans = 0;
int C[404040];
void goSolve(int l, int r, int cnt, int pos) {
    if (r < l) return;

    //cout << l << ' ' << r << " | " << cnt << ' ' << pos << '\n';
    if (l == r) {
        int nd = k - cnt;
        int s = sa[l];

        int res = -1;
        int tl = pos, tr = n - 1;
        while (tl <= tr) {
            int md = (tl + tr) >> 1;
            int val = C[s + md] - ((s + pos) ? C[s + pos - 1] : 0);
            if (val >= nd) {
                res = md;
                tr = md - 1;
            }
            else tl = md + 1;
        }

        if (res == -1) {
            cout << -1;
            exit(0);
        }
        //cout << "Done 2 : " << l << " => " << res << '\n';
        ans = max(ans, res - k + 1);
        return;
    }
    int ix = getMin(l + 1, r + 1, lcp);
    int val = lcp[ix];

    int npos = val - 1;
    int s = sa[l];

    if (s + npos >= 0 && C[s + npos] - ((s + pos) ? C[s + pos - 1] : 0) >= k - cnt) {
        //cout << "DONE: " << l << ' ' << r << " | " << cnt << ' ' << pos << '\n';
        //cout << npos << ' ' << " || " << C[s + npos] << ' ' << C[s + pos - 1] << '\n';
        int tl = pos, tr = npos;
        int res = -1;
        while (tl <= tr) {
            int md = (tl + tr) >> 1;
            int val = C[s + md] - ((s + pos) ? C[s + pos - 1] : 0);
            if (val >= k - cnt) {
                res = md;
                tr = md - 1;
            }
            else tl = md + 1;
        }

        ans = max(ans, res + 1 - k);
        return;
    }
    int ncnt = cnt;
    if (s + npos >= 0) ncnt += C[s + npos] - ((s + pos) ? C[s + pos - 1] : 0);
    goSolve(l, ix - 1, ncnt, val + 1);
    goSolve(ix, r, ncnt, val + 1);
}

void solve() {

    cin >> n >> k;

    string s;
    cin >> s;

    s += s;
    get_sa(s);
    get_lcp(s);

    vector<int> nsa, nc, nlcp;
    vector<int> iLst;
    for (int i = 0; i < n * 2 + 1; i++) {
        if (sa[i] < n) {
            iLst.push_back(i);
            nsa.push_back(sa[i]);
        }
    }

    nc = vector<int>(n);
    for (int i = 0; i < n; i++) nc[nsa[i]] = i;

    nlcp = vector<int>(n);
    int pre = iLst[0];
    for (int i = 1; i < n; i++) {
        int res = n;
        for (int j = pre + 1; j <= iLst[i]; j++) {
            res = min(res, lcp[j]);
        }
        nlcp[i] = res;
        pre = iLst[i];
    }

    sa = nsa;
    c = nc;
    lcp = nlcp;


    /*vector<string> tA;
    for (int i = 0; i < n; i++) {
        string ts;

        for (int j = 0; j < n; j++) {
            ts += s[(i + j) % n];
        }
        tA.push_back(ts);
    }
    sort(all(tA));
    cout << '\n';
    for (auto f : tA) cout << f << '\n';
    cout << '\n';*/

    for (int i = 0; i < n * 2; i++) {
        if (s[i % n] == 'X') C[i]++;
        if (i) C[i] += C[i - 1];
    }

   /* for (auto f : sa) cout << f << ' ';
    cout << '\n';
    for (auto f : c) cout << f << ' ';
    cout << '\n';
    for (auto f : lcp) cout << f << ' ';
    cout << '\n';*/
    memset(seg, INF, sizeof seg);
    for (int i = 0; i < n; i++) {
        update(i, lcp[i], lcp);
    }

    goSolve(0, n - 1, 0, 0);

    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}