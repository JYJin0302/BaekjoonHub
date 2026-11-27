#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const int INF = 0x3f3f3f3f;

int n, m;
vector<int> num;
int getIdx(int x) {
    return lower_bound(all(num), x) - num.begin();
}
int seg[202020];

void update(int ix, int val) {
    ix += n + 10;
    seg[ix] = min(seg[ix], val);

    for (; ix > 1; ix >>= 1) {
        seg[ix >> 1] = min(seg[ix], seg[ix ^ 1]);
    }
}

int getVal(int l, int r) {
    int res = INF;
    for (l += n + 10, r += n + 10; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = min(res, seg[l++]);
        if (r & 1) res = min(res, seg[--r]);
    }
    return res;
}

void solve() {

    cin >> n >> m;
    vector<int> A(n), rA(n);
    for (auto& i : A) {
        cin >> i;
        num.push_back(i);
    }
    rA = A;
    reverse(all(rA));

    num.push_back(0);
    num.push_back(INF);
    sort(all(num));
    num.erase(unique(all(num)), num.end());

    int l = 0, r = 1e9, ans = r;
    while (l <= r) {
        int md = (l + r) >> 1;
        vector<int> L(n), R(n);

        memset(seg, INF, sizeof seg);
        update(0, 0);
        for (int i = 0; i < n; i++) {
            L[i] = getVal(0, getIdx(A[i] + md + 1)) + i;
            update(getIdx(A[i]), L[i] - i - 1);
        }

        memset(seg, INF, sizeof seg);
        update(0, 0);
        for (int i = 0; i < n; i++) {
            R[i] = getVal(0, getIdx(rA[i] + md + 1)) + i;
            update(getIdx(rA[i]), R[i] - i - 1);
        }

        /*cout << "Go: " << md << '\n';
        for (int i = 0; i < n; i++) {
            cout << L[i] << ' ';
        }
        cout << '\n';
        for (int i = 0; i < n; i++) {
            cout << R[n - 1 - i] << ' ';
        }
        cout << '\n';*/
        bool ok = 0;
        for (int i = 0; i < n; i++) {
            if (L[i] + R[n - 1 - i] <= m) {
                ok = 1;
                break;
            }
        }

        if (ok) {
            ans = md;
            r = md - 1;
        }
        else l = md + 1;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
    // cin >> t;
    while (t--) solve();
}