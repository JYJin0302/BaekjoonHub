#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define all(x) x.begin(), x.end()

int gcd(int a, int b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
}

int n, m, ans = 101;
vector<int> ansv;
int frog[222];
vector<int> mat[222];
bool chk[22];

vector<int> mult(const vector<int>& v, const int k) {
    int s = v.size();
    vector<int> res(s);
    for (int i = 0; i < s; i++) res[i] = v[i] * k;
    return res;
}

vector<int> add(const vector<int>& v, const vector<int>& v2) {
    int s = v.size();
    vector<int> res(s);
    for (int i = 0; i < s; i++) res[i] = v[i] + v2[i];
    return res;
}

int fIdx[222];
int currVal[22];



void backtrack(int r, int c, int cnt = 0) {
    if (cnt >= ans) return;
    if (r == -1) {
        ans = cnt;
        ansv.clear();
        for (int j = 0; j < m; j++) ansv.push_back(currVal[j]);
        /*cout << "Found : ";
        for (int j = 0; j < m; j++) {
            cout << currVal[j] << ' ';
        }
        cout << '\n';*/
        return;
    }

    //cout << "Go: " << r << ' ' << c << ' ' << cnt << '\n';
    int tj = fIdx[r];
    if (tj == -1) {
        backtrack(r - 1, c, cnt);
        return;
    }


    if (c > tj) {
        for (register int j = 0; j < ans - cnt; j++) {
            currVal[c] = j;

            int k = 0;
            bool ok = 1;
            for (k = 0; k <= r; k++) {
                mat[k][m] -= mat[k][c] * j;
                if (abs(mat[k][m]) + cnt + j >= ans) {
                    ok = 0;
                    break;
                }
            }
            //cout << "SEt: " << c << ' ' << j << '\n';
            if (ok) backtrack(r, c - 1, cnt + j);

            k = min(k, r);
            for (; k >= 0; k--) {
                mat[k][m] += mat[k][c] * j;
            }
        }
        return;
    }

    int j = mat[r][m];
    bool ok = 1;
    int k = 0;
    for (; k < r; k++) {
        mat[k][m] -= mat[k][c] * j;
        if (abs(mat[k][m]) + cnt + j >= ans) {
            ok = 0;
            break;
        }
    }
    if (mat[r][m] < 0 || cnt + mat[r][m] >= ans) ok = 0;
    
    currVal[c] = mat[r][m];
    //cout << "set: " << c << ' ' << j << '\n';
    if (ok) backtrack(r - 1, c - 1, cnt + j);
    k = min(k, r-1);
    for (; k >= 0; k--) {
        mat[k][m] += mat[k][c] * j;
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> frog[i];

    // ( start, jump }
    vector<pair<int, int>> valid;
    for (int j = 1; j <= 6; j++) {
        for (int s = 0; s < j; s++) {
            if (s + j >= n) continue; // atleast two
            valid.push_back(mp(s, j));
        }
    }
    
    m = valid.size();
    for (int i = 0; i < n; i++) {        
        vector<int> t(m);
        for (int j = 0; j < m; j++) {
            if (i % valid[j].second == valid[j].first) t[j] = 1;
        }
        t.push_back(frog[i]);
        mat[i] = t;

       /*for (auto f : t) cout << f << ' ';
        cout << '\n';*/
    }

    int pv = 0;
    // gauss elimination..
    for (int j = 0; j < m; j++) {
        int ix = pv;
        while (ix < n && mat[ix][j] == 0) ix++;

        if (ix == n) continue;
        //cout << "Go gauss\n";
        swap(mat[ix], mat[pv]);
        if (mat[pv][j] < 0) mat[pv] = mult(mat[pv], -1);
        
        for (int k = pv + 1; k < n; k++) {
            // eliminate
            if (mat[k][j] == 0) continue;

            int g = mat[pv][j] * abs(mat[k][j]) / gcd(mat[pv][j], abs(mat[k][j]));

            
            vector<int> t1 = mult(mat[pv], g / mat[pv][j]); 
            vector<int> t2 = mult(mat[k], g / abs(mat[k][j]));
            
            if (mat[k][j] > 0) {
                t2 = mult(t2, -1);
            }
            mat[k] = add(t1, t2);            

            int tg = 0;
            for (int f = 0; f <= m; f++) {
                tg = gcd(tg, abs(mat[k][f]));
            }
            if (tg != 0) {
                for (int f = 0; f <= m; f++) mat[k][f] /= tg;
            }
        }
        pv++;

        /*cout << string(30, '-') << '\n';
        for (int x = 0; x < n; x++) {
            for (auto f : mat[x]) cout << f << ' ';
            cout << '\n';
        }
        cout << '\n';*/

    }

    //cout << "Stage 2\n";
    for (int i = n - 1; i >= 0; i--) {

        int j = 0;
        while (j < m && mat[i][j] == 0) j++;

        fIdx[i] = -1;
        if (j == m) continue;
        fIdx[i] = j;
        chk[j] = 1;
        if (mat[i][j] < 0) mat[i] = mult(mat[i], -1);
        for (int k = i - 1; k >= 0; k--) {
            if (mat[k][j] == 0) continue;

            int g = mat[i][j] * abs(mat[k][j]) / gcd(mat[i][j], abs(mat[k][j]));

            vector<int> t1 = mult(mat[i], g / mat[i][j]);
            vector<int> t2 = mult(mat[k], g / abs(mat[k][j]));

            if (mat[k][j] > 0) {
                t2 = mult(t2, -1);
            }
            mat[k] = add(t1, t2);

            int tg = 0;
            for (int f = 0; f <= m; f++) {
                tg = gcd(tg, abs(mat[k][f]));
            }
            if (tg != 0) {
                for (int f = 0; f <= m; f++) mat[k][f] /= tg;
            }
        }

        /*cout << string(30, '-') << '\n';
        for (int x = 0; x < n; x++) {
            for (auto f : mat[x]) cout << f << ' ';
            cout << '\n';
        }
        cout << '\n';*/
    }

    backtrack(n - 1, m - 1);
    assert(ans <= 100);
    cout << ans << '\n';
    for (int j = 0; j < m; j++) {
        while (ansv[j]--) {
            cout << valid[j].first + 1 << ' ' << valid[j].second << '\n';
        }
    }
}



int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}
