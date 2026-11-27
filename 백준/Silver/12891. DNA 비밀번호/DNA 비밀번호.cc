#include <bits/stdc++.h>
using namespace std;



vector<int> A, cnt;

bool check() {
    for (int i = 0; i < 4; i++) {
        if (cnt[i] < A[i]) return 0;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    A = vector<int>(4);
    cnt = vector<int>(4);
    for (auto& i : A) cin >> i;

    map<char, int> idx =
    {
        {'A', 0},
        {'C', 1},
        {'G', 2},
        {'T', 3}
    };

    int ans = 0;
    int l = 0, r = 0;
    while (r < n) {
        int ix = idx[s[r]];
        r++;
        cnt[ix]++;
        if (r-l == k) {
            ans+= check();
            int tx = idx[s[l]];
            cnt[tx]--;
            l++;
        }
    }
    cout << ans;
}