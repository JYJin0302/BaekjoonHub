#include <bits/stdc++.h>
using ll = long long;
using namespace std;

#define INF 100000000
#define pb push_back
#define all(x) (x).begin(),(x).end()

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

void solve() {

    int l, ml, mk, c_ammo;
    cin >> l >> ml >> mk >> c_ammo;

    vector<int> A(l);
    for (auto& i : A) cin >> i;

    queue<int> q;

    for (int i = 0; i < l; i++) {
        while (!q.empty() && q.front() + ml <= i) q.pop();

        int b = min(i+1, ml) - q.size();
        if (b * mk >= A[i]) {
            // 기관총 발사
            // ok
        }
        else {
            c_ammo--;

            q.push(i);
        }
    }
    if (c_ammo < 0) cout << "NO";
    else cout << "YES";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

}