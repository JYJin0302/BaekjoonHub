#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n, m;
int ord[1 << 20];
int bcnt[1 << 20];
vector<pair<int, int>> dp[1 << 20];

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.x == p2.x) return p1.y < p2.y;
    return p1.x > p2.x;
}

void init() {

    int o = 1;
    queue<int> q;
    q.push(0);
    ord[0] = 1;
    while (!q.empty()) {
        int a = q.front(); q.pop();

        //  cout << a << " | " << bcnt[a] << ' ' << ord[a] << '\n';
        for (int j = 0; j < m; j++) {
            int b = a ^ (1 << j);
            if (ord[b] == 0) {
                ord[b] = ++o;
                bcnt[b] = bcnt[a] + 1;
                q.push(b);
            }
        }
    }

}

void update(int ix) {
    for (int i = 0; i < m; i++) {
        if (ix & (1 << i)) continue;
        int ti = ix ^ (1 << i);

        // cout << "checl " << ix << " => " << ti << " ? " << dp[ix].x << ' ' << dp[ti].x << '\n';;
        for(auto f : dp[ti]) dp[ix].push_back(f);
    }
    sort(all(dp[ix]), cmp);
    while (dp[ix].size() >= 2) dp[ix].pop_back();
}

struct Data {
    int val, idx;
    Data(int v = 0) {
        val = v;
        idx = -1;
    }

    bool operator<(Data& d) {
        return ord[val] < ord[d.val];
    }
};

void solve() {


    cin >> n >> m;
    init();
    vector<Data> A(n);
    vector<int> idx;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int val = 0;
        for (int j = 0; j < m; j++) {
            if (s[j] == 'Y') val += 1 << j;
        }
        A[i] = Data(val);
        A[i].idx = i;

        if (val == (1 << m) - 1) idx.push_back(i);
    }

    int ansVal = -1;
    int i1 = -1, i2 = -1;

    for (auto f : A) {
        dp[f.val].push_back(mp(bcnt[f.val], f.idx));
    }

    for (int i = (1 << m) - 1; i >= 0; i--) {
        update(i);
    }


    for (auto f : A) {

        int v2 = (1 << m) - f.val - 1;
        // update dp[v2]

        int res = -1, rdx = -1;
        for (auto [a, b] : dp[v2]) {
            if (b == f.idx) continue;
            res = a - bcnt[v2];
            rdx = b;
            break;
        }

        if (res >= 0) {
            int tans = res;
            int ix1 = rdx;
            int ix2 = f.idx;
            if (ix1 > ix2) swap(ix1, ix2);

            if (tans > ansVal || (tans == ansVal && mp(ix1, ix2) < mp(i1, i2))) {
                ansVal = tans;
                i1 = ix1;
                i2 = ix2;

                //cout << "Ans update: " << ansVal << ' ' << i1 << ' ' << i2 << '\n';
            }
        }
    }

    if (ansVal == -1) cout << "No\n";
    else {
        cout << i1 + 1 << ' ' << i2 + 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}