#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using ld = long double;
#define all(x) x.begin(), x.end()
#define x first
#define y second
#define mp make_pair

vector<int> getfail(const string& A) {
    int N = A.size();
    vector<int> fail(N);
    fail[0] = 0;
    for (int i = 1; i < N; i++) {
        int j = fail[i - 1];
        while (j > 0 && A[j] != A[i]) { j = fail[j - 1]; }
        if (A[j] == A[i]) { fail[i] = j + 1; }
    }
    return fail;
}


int mx = 0;
void kmp(string& s1, string& s2) {

    int n = s1.size();
    int m = s2.size();
    if (m == 0) return;
    vector<int> fail = getfail(s2);
    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && s1[i] != s2[j]) {
            j = fail[j - 1];
        }

        if (s1[i] == s2[j]) {
            j++;
            mx = max(mx, j);
            if (j == m) j = fail[j-1];
        }
    }
}

void solve() {


    string s;
    cin >> s;

    int n = s.size();

    string s1, s2;
    for (int i = 0; i < n; i++) {
        if (i & 1) s2 += s[i];
        else s1 += s[i];
    }

    int ans = 0;

    kmp(s, s1);
    ans = min(n, mx * 2);

    mx = 0;
    kmp(s, s2);
    ans = max(ans, min(n, mx * 2 + 1));

    cout << ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}