#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n, m, k;
vector<bool> rmv;
vector<vector<char>> A;
void choose(vector<int>& lst, int cnt, int pos) {
    if (cnt == 0) return;
    if (pos == n) {
        assert(cnt <= lst.size());
        for (int j = 0; j < cnt; j++) {
            rmv[lst[j]] = 1;
        }
        return;
    }
    stack<pair<char, int>> st;
    vector<int> cc(26);
    int cur = 0;
    for (auto f : lst) {
        char c = A[pos][f];
        while (!st.empty()) {
            char tc = st.top().x;
            if (tc <= c) break;
            if (cc[tc - 'a'] > cnt) {
                vector<int> nlst;
                while (!st.empty() && st.top().x == tc) {
                    nlst.push_back(st.top().y);
                    st.pop();
                }
                reverse(all(nlst));
                choose(nlst, cnt, pos + 1);
                return;
            }
            else {
                cnt -= cc[tc - 'a'];
                cc[tc - 'a'] = 0;
                while (!st.empty() && st.top().x == tc) {
                    rmv[st.top().y] = 1;
                    st.pop();
                }

                if (cnt == 0) return;
            }
        }
        st.push(mp(c, f));
        cc[c - 'a']++;
    }

    while (!st.empty()) {
        char tc = st.top().x;
        if (cc[tc - 'a'] > cnt) {
            vector<int> nlst;
            while (!st.empty() && st.top().x == tc) {
                nlst.push_back(st.top().y);
                st.pop();
            }
            reverse(all(nlst));
            choose(nlst, cnt, pos + 1);
            return;
        }
        else {
            cnt -= cc[tc - 'a'];
            cc[tc - 'a'] = 0;
            while (!st.empty() && st.top().x == tc) {
                rmv[st.top().y] = 1;
                st.pop();
            }

            if (cnt == 0) return;
        }
    }
}

void solve() {

    cin >> n >> m >> k;

    A = vector<vector<char>> (n, vector<char>(m));
    rmv = vector<bool>(m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> A[i][j];
    }

    vector<int> lst;
    for (int i = 0; i < m; i++) lst.push_back(i);

    choose(lst, k, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!rmv[j]) cout << A[i][j];
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}