#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    vector<ll> A(n), sA(n+1), B(n), sB(n+1);
    for (auto& i : A) cin >> i;
    for (auto& i : B) cin >> i;
    A.push_back(1e10);
    B.push_back(1e10);

    sA[0] = A[0];
    sB[0] = B[0];
    for (int i = 1; i <= n; i++) {
        sA[i] += sA[i - 1] + A[i];
        sB[i] += sB[i - 1] + B[i];
    }

    ll curr_time = 0;
    int idx_a = 0, idx_b = 0;

    int fin_a = 0;
    while (fin_a <= n && sA[fin_a] <= m) fin_a++;

    if (fin_a == 0) {
        cout << -1;
        return 0;
    }
    vector<ll> rmax(n+1);
    rmax[fin_a - 1] = fin_a - 1;
    for (int i = fin_a - 2; i >= 0; i--) {
        if (B[i] >= B[rmax[i + 1]]) {
            rmax[i] = i;
        }
        else rmax[i] = rmax[i + 1];
    }

    vector<ll> ans;
    vector<int> pop_cnt(n);
    ll pop_b = 0;
    while (curr_time < m) {
        //idx_a < fin_a&& idx_b < fin_a
        ll rm_a = sA[idx_a] - curr_time;
        ll rm_b = sB[idx_b] + pop_b - curr_time;

        //cout << "Curr:" << idx_a << ' ' << idx_b << ' ' << rm_a << ' ' << rm_b  << ' ' << curr_time << ' ' << pop_b << '\n';

        if (min(rm_a, rm_b) > m - curr_time) break;

        if (rm_a <= rm_b) {
            idx_a++;
            int tx = rmax[idx_b];
            pop_cnt[tx]++;

            if (rm_b == rm_a) {
                if (pop_cnt[idx_b] > 0) {
                    pop_cnt[idx_b]--;
                    ans.push_back(curr_time + rm_b);
                    pop_b += B[idx_b];
                }
                else idx_b++;
            }

            curr_time += rm_a;
        }
        else {
            if (pop_cnt[idx_b] > 0) {
                pop_cnt[idx_b]--;
                ans.push_back(curr_time + rm_b);
                pop_b += B[idx_b];
            }
            else idx_b++;

            curr_time += rm_b;
        }

    }

    if (idx_b >= idx_a) cout << -1;
    else {
        cout << ans.size() << '\n';
        for (auto i : ans) cout << i << ' ';
    }
}