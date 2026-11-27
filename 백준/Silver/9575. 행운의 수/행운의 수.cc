#include <bits/stdc++.h>
using ll = long long;
using namespace std;

#define INF 100000000
#define pb push_back
#define all(x) (x).begin(),(x).end()

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

bool valid(int x) {
    while (x) {
        if ((x % 10 != 5) && (x % 10 != 8)) return false;
        x /= 10;
    }
    return true;
}

void solve() {

    int a, b, c;
    cin >> a;
    vector<int> A(a);
    for (auto& i : A) cin >> i;

    cin >> b;
    vector<int> B(b);
    for (auto& i : B) cin >> i;

    cin >> c;
    vector<int> C(c);
    for (auto& i : C) cin >> i;

    int ans = 0;
    map<int, bool> cnt;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            for (int k = 0; k < c; k++) {
                int tt = A[i] + B[j] + C[k];
                if (valid(tt) && cnt[tt] == 0) {
                    cnt[tt] = 1;
                    ans++;
                }
            }
        }
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