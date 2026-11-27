#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<int> num;
int getIdx(int x) {
    return lower_bound(all(num), x) - num.begin();
}

int S[1010][1010];

void solve() {

    int c, n;
    cin >> c >> n;

    vector<pair<int, int>> A(n);
    for (auto& i : A) {
        cin >> i.x >> i.y;
        num.push_back(i.x);
        num.push_back(i.y);
    }

    num.push_back(0);
    num.push_back(1e7);
    sort(all(num));
    num.erase(unique(all(num)), num.end());

    for (auto& [a, b] : A) {
        a = getIdx(a);
        b = getIdx(b);
        S[a][b]++;
    }

    int sn = num.size();

    for (int i = 1; i < sn; i++) {
        for (int j = 1; j < sn; j++) {
            S[i][j] += S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
        }
    }

    int l = 1, r = 10000, ans = r;
    while(l <= r){
        int md = (l + r) >> 1;

        int mx = 0;
        for (int i = 1; i < sn - 1; i++) {
            for (int j = 1; j < sn - 1; j++) {
                int i2 = getIdx(num[i] + md) - 1;
                int j2 = getIdx(num[j] + md) - 1;

                int cnt = S[i2][j2] - S[i - 1][j2] - S[i2][j - 1] + S[i - 1][j - 1];
                mx = max(mx, cnt);
            }
        }

        if (mx >= c) {
            ans = md;
            r = md - 1;
        }
        else {
            l = md + 1;
        }
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