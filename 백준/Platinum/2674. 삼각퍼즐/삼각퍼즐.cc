#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()


int n;
vector<int> row[22], col[22];

int ans[22][22];
int need[22][22];
// need[a][b] : a열에서 b번째 그룹을 채울때 필요한 최소 나머지 칸 수 

bool goSolve(int x, int y, int r = 0, int idx = 0) {
    /*cout << "Curr: " << x << ' ' << y << ' ' << r << ' ' << idx << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j + i < n; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }*/
    if (x == n) {
       // cout << "Ans found\n";
        return 1;
    }

    if (x + y == n) {
        if (idx == row[x].size() - 1 && row[x][idx] == r) idx++;
        if (idx != row[x].size()) return 0;
        vector<int> tmp;
        int pv = 0;
        for (int j = 0; j <= x; j++) {
            if (ans[j][y-1] == 1) pv++;
            else if (pv) {
                tmp.push_back(pv);
                pv = 0;
            }
        }
        if (pv) tmp.push_back(pv);

        /*cout << "Check : " << y - 1 << " | \n";
        for (auto f : col[y - 1]) cout << f << ' ';
            cout << '\n';
            for (auto f : tmp) cout << f << ' ';
            cout << '\n';*/
        if (tmp != col[y - 1]) {
           // cout << "Failed\n";
            return 0;
        }
       // cout << "Success\n";
        return goSolve(x + 1, 0);
    }



    if (idx != row[x].size() && row[x][idx] != r) {
        // try fill
        
        ans[x][y] = 1;
       // cout << "Go fill\n";

        // sub check
        vector<int> tmp;
        int pv = 0;
        for (int j = 0; j <= x; j++) {
            if (ans[j][y] == 1) pv++;
            else if (pv) {
                tmp.push_back(pv);
                pv = 0;
            }
        }
        if (pv) tmp.push_back(pv);

        vector<int>& t2 = col[y];

        bool ok = 1;
        if (tmp.empty()) ok = 1;
        else if (t2.empty()) ok = 0;
        else if (t2.size() < tmp.size()) ok = 0;
        else {
            int f = 0;
            while (f < tmp.size() && tmp[f] == t2[f]) f++;
            if (f < tmp.size() - 1 || (f == tmp.size() - 1 && tmp[f] > t2[f])) ok = 0;
        }

        if (ok && goSolve(x, y + 1, r + 1, idx)) return 1;
        ans[x][y] = 0;
    }
    if (r != 0 && r != row[x][idx]) return 0;
    if (y - r > need[x][idx]) return 0;
   // cout << "No fill\n";
    if (idx < row[x].size() && row[x][idx] == r) {
        return goSolve(x, y + 1, 0, idx + 1);
    }
    else return goSolve(x, y + 1, 0, idx);

}

void solve() {

    cin >> n;

    bool ok = 1;
    for (int i = 0; i < n; i++) {
        // row
        int k;
        cin >> k;
        vector<int> A(k);
        int sum = k-1;
        for (auto& f : A) {
            cin >> f;
            sum += f;
        }
        if (sum > n-i) ok = 0;
        row[i] = A;
    }
    for (int i = 0; i < n; i++) {
        // col
        int k;
        cin >> k; 
        vector<int> A(k);
        int sum = k - 1;
        for (auto& f : A) {
            cin >> f;
            sum += f;
        }
        if (sum > n-i) ok = 0;
        col[i] = A;
    }
    if (!ok) {
        cout << "No Answer\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < row[i].size(); j++) {
            int nd = -1;
            for (int k = j; k < row[i].size(); k++) {
                nd += row[i][k] + 1;
            }
            need[i][j] = n - i - nd;
            //cout << need[i][j] << ' ';
        }
        //cout << '\n';
        need[i][row[i].size()] = n + 10;
    }
    
    if (!goSolve(0, 0)){
        cout << "No Answer\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j + i < n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}