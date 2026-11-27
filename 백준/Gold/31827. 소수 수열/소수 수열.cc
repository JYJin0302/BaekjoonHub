#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

bool isP[1001010];
vector<int> res[11];
void solve() {

    vector<int> p;
    for (int j = 2; j <= 1000000; j++) {
        if (isP[j]) continue;
        p.push_back(j);
        for (int k = j * 2; k <= 1000000; k += j) {
            isP[k] = 1;
        }
    }

    int n, k;
    cin >> n >> k;

    int cnt = 0;
    for (auto f : p) {
        if (f % k == 1) {
            cout << f << ' ';
            cnt++;
            if (cnt == n) break;
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}