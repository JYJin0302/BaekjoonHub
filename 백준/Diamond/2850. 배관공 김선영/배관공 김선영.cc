#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define all(x) x.begin(), x.end()


int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

//   0
// 1 X 3
//   2
const int mod = 10007;
vector<int> dir[7];
bool nextConn[7][7], downConn[7][7];


int n, m;
int stateCnt = 0;
int track[22];

char grid[11][11];
vector<vector<int>> go, decode;
int goNumber[202020];

void makeState(int cnt = 0, int mxCnt = 0) {

    if (cnt == m+1) { 
        if (track[m-1] * track[m] != 0 && track[m - 1] != track[m]) return;

        int c1 = 0;
        for (int i = 1; i <= mxCnt; i++) {
            int cc = 0;
            for (int j = 0; j <= m; j++) {
                if (track[j] == i) cc++;
            }

            if (cc == 1) c1++;
            else if (cc >= 3) return;
        }
        if (c1 > 1) return;

        /*cout << "Found: ";
        for (int j = 0; j < cnt; j++) cout << track[j] << ' ';
        cout << '\n';*/
        vector<int> tmp;
        int b = 0;
        for (int i = 0; i < cnt; i++) {
            tmp.push_back(track[i]);
            if (go[b][track[i]] == -1) {
                go[b][track[i]] = go.size();
                go.push_back(vector<int>(m + 1, -1));
            }
            b = go[b][track[i]];
        }
        decode.push_back(tmp);      
        goNumber[b] = stateCnt;
        stateCnt++;
        return;
    }
    for (register int i = 0; i <= mxCnt + 1; i++) {
        track[cnt] = i;
        makeState(cnt + 1, max(mxCnt, i));
    }
}

void modify(vector<int>& v) {
    int sz = v.size();
    int pv = 1;
    for (int i = 0; i < sz; i++) {
        if (v[i] == 0) continue;
        if (v[i] > pv) {
            int a = v[i];
            for (int j = i; j < sz; j++) {
                if (v[j] == a || v[j] == pv) {
                    v[j] = a + pv - v[j];
                }
            }
            pv++;
        }
        else if (v[i] == pv) pv++;
    }
}

int getSnum(vector<int>& v) {
    int b = 0;
    for (int i = 0; i < v.size(); i++) {
        b = go[b][v[i]];
    }
    return goNumber[b];
}

void solve() {

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    go.push_back(vector<int>(m + 1, -1));
    makeState();
   // cout << stateCnt << ' ' << go.size() << '\n';

    int sz = stateCnt;
    vector<int> dp(sz), tmp(sz);

    vector<int> s = { 1 };
    for (int i = 0; i < m; i++) s.push_back(0);
    int sN = getSnum(s);
    dp[sN] = 1;

    for (register int i = 0; i < n; i++) {
        for (register int j = 0; j < m; j++) {
            
            //cout << "Go: " << i << ' ' << j << '\n';
            tmp = vector<int>(sz);
            for (register int s = 0; s < sz; s++) {
                if (dp[s] == 0) continue;


                vector<int> sv = decode[s];
               /* cout << "Curr state : ";
                for (auto f : sv) cout << f << ' ';
                cout << " | " << dp[s] << '\n';*/
                int mv = *max_element(all(sv)) + 1;

                // add sth
                if (j == 0 && sv[m] != 0) continue;

                //cout << "ADD\n";
                if (grid[i][j] == '.') {
                    if (sv[0] == 0 && sv[m] == 0) {
                        sv.pop_back();
                        sv.erase(sv.begin());
                        sv.push_back(mv);
                        sv.push_back(mv);

                        modify(sv);
                        int sN = getSnum(sv);

                        /*cout << "nxt: ";
                        for (auto k : sv) cout << k << ' ';
                        cout << '\n';*/
                        tmp[sN] = (tmp[sN] + dp[s]) % mod;
                    }
                    else if (sv[0] == 0) {
                        sv.push_back(0);
                        sv.erase(sv.begin());

                        modify(sv);
                        int sN = getSnum(sv);
                        tmp[sN] = (tmp[sN] + dp[s]) % mod;
                        /*cout << "nxt: ";
                        for (auto k : sv) cout << k << ' ';
                        cout << '\n';*/

                        swap(sv[m - 1], sv[m]);
                        modify(sv);
                        sN = getSnum(sv);
                        tmp[sN] = (tmp[sN] + dp[s]) % mod;
                        /*cout << "nxt: ";
                        for (auto k : sv) cout << k << ' ';
                        cout << '\n';*/
                    }
                    else if (sv[m] == 0) {
                        sv.pop_back();
                        sv.push_back(sv[0]);
                        sv.push_back(0);
                        sv.erase(sv.begin());

                        modify(sv);
                        int sN = getSnum(sv);
                        tmp[sN] = (tmp[sN] + dp[s]) % mod;
                       /* cout << "nxt: ";
                        for (auto k : sv) cout << k << ' ';
                        cout << '\n';*/

                        swap(sv[m - 1], sv[m]);
                        modify(sv);
                        sN = getSnum(sv);
                        tmp[sN] = (tmp[sN] + dp[s]) % mod;
                        /*cout << "nxt: ";
                        for (auto k : sv) cout << k << ' ';
                        cout << '\n';*/
                    }
                    else {
                        if (sv[m] == sv[0]) {}// no 
                        else {
                            int tv = sv[m];
                            sv.pop_back();
                            for (int j = 1; j < m; j++) {
                                if (sv[j] == tv) sv[j] = sv[0];
                            }
                            sv.erase(sv.begin());
                            sv.push_back(0);
                            sv.push_back(0);
                            modify(sv);
                            int sN = getSnum(sv);
                            tmp[sN] = (tmp[sN] + dp[s]) % mod;
                           /* cout << "nxt: ";
                            for (auto k : sv) cout << k << ' ';
                            cout << '\n';*/
                        }
                    }
                }

                sv = decode[s];
                // add nth
                //cout << "No add\n";
                if (sv[0] == 0 && sv[m] == 0) {
                    sv.erase(sv.begin());
                    sv.push_back(0);
                    modify(sv);
                    int sN = getSnum(sv);
                    tmp[sN] = (tmp[sN] + dp[s]) % mod;
                    /*cout << "nxt: ";
                    for (auto k : sv) cout << k << ' ';
                    cout << '\n';*/
                }
            }

            swap(dp, tmp);
        }
    }

    vector<int> tt(m + 1);
    tt[m - 1] = 1;

    int sM = getSnum(tt);

    cout << dp[sM];
}



int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}
