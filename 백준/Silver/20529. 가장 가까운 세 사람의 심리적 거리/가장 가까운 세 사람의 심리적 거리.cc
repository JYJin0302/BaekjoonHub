#include <bits/stdc++.h>
using ll = long long;
using namespace std;

#define INF 100000000
#define pb push_back
#define all(x) (x).begin(),(x).end()

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

int dist(string a, string b, string c) {

    int res = 0;
    for (int i = 0; i < 4; i++) {
        res += (a[i] != b[i]);
        res += (a[i] != c[i]);
        res += (b[i] != c[i]);
    }

    return res;
}

void solve() {

    int n;
    cin >> n;
    int ans = n*30;
    map<string, int> cnt;
    cnt.clear();

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        cnt[s]++;
    }

    for (auto i = cnt.begin(); i != cnt.end(); i++) {
        if (i->second == 0) continue;
        i->second -= 1;

        for (auto j = cnt.begin(); j != cnt.end(); j++) {
            if (j->second == 0) continue;
            j->second -= 1;
            for (auto k = cnt.begin(); k != cnt.end(); k++) {
                if (k->second == 0) continue;

                ans = min(ans, dist(i->first, j->first, k->first));
            }
            j->second += 1;
        }
        i->second += 1;
    }

    cout << ans << '\n';


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }
}