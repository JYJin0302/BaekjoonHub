#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using ld = long double;
#define all(x) x.begin(), x.end()
#define x first
#define y second
#define mp make_pair

// 3x3, 2x2, 1x1, 1x2, 1x3, 2x3
vector<int> iLst[6];

int ans[3][101010];

void solve() {

    memset(ans, -1, sizeof(ans));
    int k, n;
    cin >> k >> n;

    vector<pair<int, int>> A(k);
    for (int i = 0; i < k; i++) {
        cin >> A[i].x;
    }
    for (int i = 0; i < k; i++) {
        cin >> A[i].y;
    }

    for (int i = 0; i < k; i++) {
        if (A[i].x > A[i].y) swap(A[i].x, A[i].y);
        if (A[i].x == 3) iLst[0].push_back(i);
        else if (A[i].x == 2) {
            if (A[i].y == 2) iLst[1].push_back(i);
            else iLst[5].push_back(i);
        }
        else {
            iLst[1 + A[i].y].push_back(i);
        }
    }

    int cur = 0;
    for (auto f : iLst[0]) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                ans[i][cur + j] = f;
            }
        }
        cur += 3;
    }

    for (auto f : iLst[5]) {
        for (int i = 0; i < 2; i++) {
            ans[0][cur + i] = ans[1][cur + i] = ans[2][cur + i] = f;
        }
        cur += 2;
    }

    int cur2 = cur;

    for (auto f : iLst[1]) {
        for (int i = 0; i < 2; i++) {
            ans[0][cur + i] = ans[1][cur + i] = f;
        }
        cur += 2;
    }

    
    int tx = n - 1;
    while (tx >= cur2) {
        while (tx >= cur2 && ans[0][tx] != -1 && ans[1][tx] != -1 && ans[2][tx] != -1) {
            tx--;
        }
        if (tx < cur2) break;

        if (!iLst[4].empty()) {
            if (ans[0][tx] + ans[1][tx] + ans[2][tx] == -3) {
                ans[0][tx] = ans[1][tx] = ans[2][tx] = iLst[4].back();
            }
            else {
                ans[2][tx] = ans[2][tx - 1] = ans[2][tx - 2] = iLst[4].back();
            }
            iLst[4].pop_back();
        }
        else if (!iLst[3].empty()) {
            if (ans[0][tx] + ans[1][tx] == -2) {
                ans[0][tx] = ans[1][tx] = iLst[3].back();
            }
            else {
                ans[2][tx] = ans[2][tx - 1] = iLst[3].back();
            }
            iLst[3].pop_back();
        }
        else {
            for (int i = 0; i < 3; i++) {
                if (ans[i][tx] == -1) {
                    ans[i][tx] = iLst[2].back();
                    iLst[2].pop_back();
                    break;
                }
            }
        }
    }


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] + 1 << ' ';
        }
        cout << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}