#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

int A[505][505];
int Z[505][505];

void solve() {

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
            if (A[i][j] == 0) Z[i][j]++;

            A[i][j] += A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1];
            Z[i][j] += Z[i - 1][j] + Z[i][j - 1] - Z[i - 1][j - 1];
        }
    }

    int k;
    cin >> k;
    vector<int> B(k);
    for (auto& i : B) cin >> i;
    sort(all(B));
    reverse(all(B));

    for (int i = 1; i < k; i++) B[i] += B[i - 1];

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int l = 1, r = min(n - i + 1, n - j + 1);
            while (l <= r) {
                int md = (l + r) >> 1;

                int totA = A[i + md - 1][j + md - 1] - A[i - 1][j + md - 1] - A[i + md - 1][j - 1] + A[i - 1][j - 1];
                int totZ = Z[i + md - 1][j + md - 1] - Z[i - 1][j + md - 1] - Z[i + md - 1][j - 1] + Z[i - 1][j - 1];

                if (totZ <= k) {
                    ans = max(ans, totA + (totZ ? B[totZ - 1] : 0));
                    l = md + 1;
                }
                else r = md - 1;
            }
        }
    }

    cout << ans << '\n';
}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

}