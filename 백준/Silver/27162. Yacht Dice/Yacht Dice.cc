#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll fastPow(ll b, ll ex, ll m) {
    ll res = 1;
    while (ex) {
        if (ex % 2) res = res * b % m;
        b = b * b % m;
        ex /= 2;
    }
    return res;
}

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };


vector<int> ans = { 0 };

string s;
void solve(int a, int b, int c, int d, int e) {

    vector<int> cnt(7);
    cnt[a]++, cnt[b]++, cnt[c]++, cnt[d]++, cnt[e]++;

    for (int i = 0; i < 6; i++) {
        if (s[i] == 'Y') ans.push_back(cnt[i + 1] * (i+1));
    }

    if (s[6] == 'Y') {
        for (int i = 1; i <= 6; i++) {
            if (cnt[i] >= 4) ans.push_back(i * 4);
        }
    }

    if (s[7] == 'Y') {
        for (int i = 1; i <= 6; i++) {
            for (int j = 1; j <= 6; j++) {
                if (i == j) continue;
                if (cnt[i] == 3 && cnt[j] == 2) ans.push_back(i * 3 + j * 2);
            }
        }
    }

    if (s[8] == 'Y') {
        if (cnt[1] == 1 && cnt[2] == 1 && cnt[3] == 1 && cnt[4] == 1 && cnt[5] == 1) ans.push_back(30);
    }

    if (s[9] == 'Y') {
        if (cnt[6] == 1 && cnt[2] == 1 && cnt[3] == 1 && cnt[4] == 1 && cnt[5] == 1) ans.push_back(30);
    }

    if (s[10] == 'Y') {
        for (int i = 1; i <= 6; i++) {
            if (cnt[i] == 5) ans.push_back(50);
        }
    }

    if (s[11] == 'Y') {
        ans.push_back(a + b + c + d + e);
    }
}

void solve() {

    cin >> s;

    int a, b, c;
    cin >> a >> b >> c;

    for (int i = 1; i <= 6; i++) {
        for (int j = i; j <= 6; j++) {
            solve(a, b, c, i, j);
        }
    }

    cout << *max_element(ans.begin(), ans.end());

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