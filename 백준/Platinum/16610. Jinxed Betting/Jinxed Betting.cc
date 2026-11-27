#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<ll> A(n);
    for (auto& i : A)cin >> i;

    sort(A.rbegin(), A.rend());

    int curr_set = 1;
    while (curr_set < n && A[curr_set] == A[1]) curr_set++;
    // 1 ~ currSet - 1 까지 같은 집합

    ll ans = 0;
    ll loop_cnt = 0;
    ll maxVal = A[1];
    while (curr_set < n && maxVal < A[0] + 1) {
        ll diff = A[1] - A[curr_set] - loop_cnt;
        
        if (diff == 0) {
            curr_set++;
            continue;
        }
        //cout <<curr_set <<' ' <<loop_cnt << ' ' << ans << ' ' <<maxVal<<'\n';

        ll dist = floor(log2(curr_set - 1));
        ll nextVal = maxVal + diff * dist;
        if (nextVal < A[0] + 1) {
            maxVal = nextVal;
            loop_cnt += diff;
            ans += (dist + 1) * diff;
        }
        else {
            ll target = A[0] + 1;
            diff = target - maxVal;

            ans += diff + (diff - 1) / dist;
            maxVal = A[0] + 1;
        }
    }
    //cout <<curr_set <<' ' <<loop_cnt << ' ' << ans << ' ' <<maxVal <<'\n';
    if (maxVal < A[0] + 1) {
        ll diff = A[0] + 1 - maxVal;
        ll dist = floor(log2(n - 1));
        ans += diff + (diff - 1) / dist;
    }

    cout << ans - 1;
}
