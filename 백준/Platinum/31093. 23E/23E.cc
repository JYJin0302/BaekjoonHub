#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair


void solve() {

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int ans = 0;
    vector<int> cnt = { 0, 0, 0, 0 };
    for (int i = 0; i < n / 2; i++) {
        string ts = "";
        ts += s[i];
        ts += s[n - 1 - i];

        if (ts == "23" || ts == "32") cnt[0]++;
        else if (ts == "22" || ts == "E3" || ts == "3E") ans += 2;
        else if (ts == "2E" || ts == "E2") cnt[2]++;
        else if (ts == "EE") cnt[3]++;
        else if (ts == "33") cnt[1]++;
    }

    cout << ans << '\n';
    for (int i = 1; i <= k; i++) {
        if (cnt[0] && cnt[2]) {
            cnt[0]--;
            cnt[2]--;
            ans += 4;
        }
        else if (cnt[1] && cnt[3]) {
            cnt[1]--;
            cnt[3]--;
            ans += 4;
        }
        else if (cnt[0] && cnt[3]) {
            cnt[0]--;
            cnt[3]--;
            cnt[2]++;
            ans += 2;
        }
        else if (cnt[1] && cnt[2]) {
            cnt[1]--;
            cnt[2]--;
            cnt[0]++;
            ans += 2;
        }
        else if (cnt[0] >= 2) {
            cnt[0] -= 2;
            ans += 2;
            cnt[1]++;
        }
        else if (cnt[2] >= 2) {
            cnt[2] -= 2;
            ans += 2;
            cnt[3]++;
        }
        cout << ans << '\n';
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}