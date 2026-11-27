#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int n, l;
vector<string> A;

bool isPrefix(string& a, string& s) {
    if (a.size() < s.size()) return 0;
    for (int i = 0; i < s.size(); i++) if (s[i] != a[i]) return 0;
    return 1;
}

bool isSuffix(string& a, string& s) {
    if (a.size() < s.size()) return 0;
    int l = a.size() - s.size();
    for (int i = 0; i < s.size(); i++) if (s[i] != a[l + i]) return 0;
    return 1;
}

map<tuple<int, int, string>, int> dp;

tuple<int, int, string> preCal[55][55];

bool chk(string& s, string& rem) {
    int len = s.size();

    int tl = len / 2, tr = len / 2;
    if (len % 2 == 0) tl--;

    while (tl >= 0 && tr < len) {
        if (s[tl] == '.' || s[tr] == '.' || s[tl] == s[tr]) {
            tl--, tr++;
        }
        else return 0;
    }

    tl = 0, tr = len - 1;
    while (tl < tr && s[tl] != '.' && s[tl] == s[tr]) tl++, tr--;
    if (tl >= tr) return 1;

    if (s[tl] == '.') {
        while (tl < tr && s[tl] == '.' && s[tr] != '.') {
            rem += s[tr];
            tl++, tr--;
        }
    }
    else {
        while (tl < tr && s[tr] == '.' && s[tl] != '.') {
            rem += s[tl];
            tl++, tr--;
        }
        reverse(all(rem));
    }
    return 1;
}

int solve(int len, int side = 0, string need = "", int dep = 0) {
    int szN = need.size();
    if (szN == 0) side = 0;
    // 안채워진 칸수, 채워야하는 substring 과 그 방향
    string tts(dep * 3, '-');
    //cout << tts << "Call: " << len << ' ' << side << ' ' << need << '\n';
    if (len < need.size()) return 0;
    tuple tmp = make_tuple(len, side, need);
    int res = dp[tmp];
    if (res != 0) {
        return max(0, res);
    }
    if (len == 0 && need.empty()) return 1;


    if (side == 0) {
        for (int i = 0; i < n; i++) {
            if (A[i].size() > len) continue;
            if (isPrefix(A[i], need)) {
                string curr(len - szN, '.');
                for (int j = szN; j < A[i].size(); j++) {
                    curr[j - szN] = A[i][j];
                }
                // check palindrome
                string nnd = "";

                bool ok = chk(curr, nnd);
                if (ok) {
                    //cout << tts << "Use: " << A[i] << ' ' << nnd << '\n';
                    res += solve(len - A[i].size(), 1, nnd, dep+1);
                }
            }
            else if (isPrefix(need, A[i])) {
                string nnd = need.substr(A[i].size(), szN);
               // cout <<tts << "Use: " << A[i] <<' ' << nnd << '\n';
                res += solve(len - A[i].size(), 0, nnd, dep+1);
            }
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            if (A[i].size() > len) continue;
            if (isSuffix(A[i], need)) {

                string curr(len - szN, '.');
                int st = curr.size() - A[i].size() + szN;
                for (int j = 0; j < A[i].size() - szN; j++) {
                    curr[st + j] = A[i][j];
                }
                // check palindrome
                string nnd = "";
                bool ok = chk(curr, nnd);
               // cout << nnd << '\n';
                if (ok) {
                    //cout << tts << "use: " << A[i] << ' ' << nnd << '\n';
                    res += solve(len - A[i].size(), 0, nnd , dep+1);
                }
            }
            else if (isSuffix(need, A[i])) {
                string nnd = need.substr(0, szN - A[i].size());
               // cout << tts << "use: " << A[i] << ' ' << nnd << '\n';
                res += solve(len - A[i].size(), 1, nnd, dep+1);
            }
        }
    }

    if (res == 0) res = -1;
    //cout << tts << "Call end: " << len << ' ' << side << ' ' << need << " | " << res << '\n';
    dp[tmp] = res;
    return max(res, 0);
}

void solve() {
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        A.push_back(s);
    }

    cout << solve(l);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}