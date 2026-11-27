#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> A(k);
    for (auto& i : A) cin >> i;

    vector<bool> c(k + 1);
    int sz = 0;
    vector<int> curr(n);

    int ans = 0;
    for (int i = 0; i < k; i++) {


        int v = A[i];
        if (c[v]) continue;
        c[v] = 1;

        if (sz < n) {
            curr[sz] = v;
            sz++;
        }
        else {

            int ix = -1, pos = -1;

            // 가장 늦게 다시 쓰는 것 찾기
            for (int j = 0; j < n; j++) {
                int val = curr[j];

                int tix = i;
                while (tix < k && A[tix] != val) tix++;

                if (pos < tix) {
                    ix = j;
                    pos = tix;
                }

            }

            c[curr[ix]] = 0;
            curr[ix] = v;
            ans++;
        }
    }

    cout << ans;
}