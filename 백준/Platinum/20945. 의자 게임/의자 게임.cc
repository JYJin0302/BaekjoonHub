#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    
    vector<int> A(n * 2);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        A[i + n] = A[i];
    }

    int l = 0, r = 0;
    vector<int> cnt(n + 1);

    int ans = k;
    priority_queue<pair<int, int>> Mx, mx;
    while (l < n * 2) {

        while (!Mx.empty() && Mx.top().second < l) {
            Mx.pop();
        }
        while (!mx.empty() && mx.top().second < l) {
            mx.pop();
        }

        while (r < n * 2 && r < l+k) {
            // insert A[r]
            Mx.push(mp(A[r], r));
            mx.push(mp(-A[r], r));

            if (cnt[A[r]] == 1) break;
            if (Mx.top().first + mx.top().first >= k) break;
            cnt[A[r]]++;
            r++;
        }

        ans = min(ans, k - (r - l));
        cnt[A[l]]--;
        l++;
    }
    cout << ans;

}