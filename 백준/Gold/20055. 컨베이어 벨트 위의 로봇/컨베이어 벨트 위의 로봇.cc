#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int n, k;
int A[222];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n * 2; i++) cin >> A[i];

    vector<int> robots;
    int robot_idx = 0;
    int belt_idx = 0;
    vector<bool> used(n * 2);

    int ans = 0, zeroCnt = 0;
    while (zeroCnt < k) {
        ans++;
        // belt move
        belt_idx = (belt_idx + n * 2 - 1) % (n * 2);

        // robot move
        for (int i = robot_idx; i < robots.size(); i++) {
            // check if out point
            int outPoint = belt_idx + n - 1;
            outPoint %= n * 2;

            if (outPoint == robots[i]) {
                robot_idx++;
                used[robots[i]] = 0;
                continue;
            }

            int nxt = robots[i] + 1;
            nxt %= n * 2;

            if (A[nxt] > 0 && !used[nxt]) {
                A[nxt]--;
                if (A[nxt] == 0) zeroCnt++;
                
                used[robots[i]] = 0;
                used[nxt] = 1;
                robots[i] = nxt;

                if (nxt == outPoint) {
                    robot_idx++;
                    used[nxt] = 0;
                }
            }
        }

        // robot add
        if (A[belt_idx] > 0 && !used[belt_idx]) {
            A[belt_idx]--;
            if (A[belt_idx] == 0) zeroCnt++;
            used[belt_idx] = 1;
            robots.push_back(belt_idx);
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}