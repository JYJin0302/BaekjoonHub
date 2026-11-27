#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define all(x) x.begin(), x.end()

int n, m;
int grid[11][11];
int track[11];


vector<vector<int>> go, decode;
int goNumber[101010];
bool aChk[101010];

int stateNum = 0;
void makeState(int cnt, int maxG = 0) {

    if (cnt == m) {

        bool ok = 1;
        for (int i = 1; i < cnt - 1; i++) {
            if (track[i] != 0) {
                int tc = 0;
                if (track[i - 1] != 0 && track[i - 1] != track[i]) tc++;
                if (track[i + 1] != 0 && track[i + 1] != track[i]) tc++;
                if (tc == 2) {
                    ok = 0;
                    break;
                }
            }
        }
        if (!ok) return;

        int b = 0;
        for (int j = 0; j < cnt; j++) {
            if (go[b][track[j]] == -1) {
                go[b][track[j]] = go.size();
                go.push_back(vector<int>(m+1, -1));
            }
            b = go[b][track[j]];
        }
        goNumber[b] = stateNum;
        vector<int> tmp;
        for (int i = 0; i < m; i++) tmp.push_back(track[i]);
        decode.push_back(tmp);

        stateNum++;
        return;
    }

    for (int i = 0; i <= maxG + 1; i++) {
        track[cnt] = i;
        makeState(cnt + 1, max(maxG, i));
    }
}

void modify(vector<int>& v) {
    int pv = 1;
    for (int i = 0; i < m; i++) {
        if (v[i] == 0) continue;
        if (v[i] > pv) {
            int a = v[i], b = pv;
            for (int j = i; j < m; j++) {
                if (v[j] == a || v[j] == b) v[j] = a + b - v[j];
            }
            pv++;
        }
        else if (v[i] == pv) pv++;
    }
}

bool chk(int s) {
    vector<int>& v = decode[s];
    if (*max_element(all(v)) >= 2) return 0;
    if (s == 0) return 0;
    return 1;
}

void solve() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            grid[i][j] *= -1;
        }
    }
    
    // m개에 대한 연결성 state 만들기
    go.push_back(vector<int>(m+1, -1));
    makeState(0);
    //cout << go.size() << ' ' << stateNum << '\n';
    // ~= 23000

    int sz = stateNum;
    for (int i = 0; i < sz; i++) aChk[i] = chk(i);
    vector<int> dp(sz, -1e8), tmp(sz);
    dp[0] = 0;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tmp = vector<int>(sz, -1e8);
           /* cout << '\n';
            cout << "Go: " << i << ' ' << j << '\n';*/
            for (int state = 0; state < stateNum; state++) {

                if (dp[state] < -1e7) continue;
                vector<int> sv = decode[state];

                /*cout << "curr state | ";
                for (auto f : sv) cout << f << ' ';
                cout << '|' << dp[state] << '\n';*/
                // choose this (i, j)

                int mv = *max_element(all(sv)) + 1;
                sv.push_back(mv);
                if (j == 0) {
                    if (sv[0] != 0) sv[m] = sv[0];
                }
                else {
                    if (sv[0] != 0) {
                        int a = sv[0];
                        for (int j = 0; j < m; j++) {
                            if (sv[j] == a) sv[j] = mv;
                        }
                    }
                    if (sv[m - 1] != 0) {
                        int a = sv[m - 1];
                        for (int j = 0; j < m; j++) {
                            if (sv[j] == a) sv[j] = mv;
                        }
                    }
                }
                sv.erase(sv.begin());
                modify(sv);

                /*cout << "Chose: ";
                for (auto f : sv) cout << f << ' ';
                cout << '\n';*/

                int newS = 0;
                for (int k = 0; k < m; k++) {
                    newS = go[newS][sv[k]];
                }
                newS = goNumber[newS];
                tmp[newS] = max(tmp[newS], dp[state] + grid[i][j]);
                if (aChk[newS]) ans = max(ans, tmp[newS]);

                sv = decode[state];
                sv.push_back(0);
                // or not
                if (sv[0] != 0) {
                    int cnt = 0;
                    for (int j = 0; j < m; j++) {
                        if (sv[j] == sv[0]) cnt++;
                    }
                    if (cnt == 1) continue;
                }

                sv.erase(sv.begin());
                modify(sv);
                /*cout << "No chose: ";
                for (auto f : sv) cout << f << ' ';
                cout << '\n';*/

                newS = 0;
                for (int k = 0; k < m; k++) {
                    newS = go[newS][sv[k]];
                }
                newS = goNumber[newS];
                tmp[newS] = max(tmp[newS], dp[state]);
                if (aChk[newS]) ans = max(ans, tmp[newS]);
            }
            swap(dp, tmp);
        }
    }

    ans *= -1;
    cout << ans;

}



int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}
