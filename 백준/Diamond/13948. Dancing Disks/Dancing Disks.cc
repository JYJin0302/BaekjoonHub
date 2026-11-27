#include <bits/stdc++.h>
using namespace std;
#define mp make_pair

int dp[7][7];

stack<int> curr[7][7];
priority_queue<pair<int , pair<int, int>>> q;

void goMove(int sx, int sy, int ex, int ey) {
    while (sx != ex) {
        cout << sx << ' ' << sy << ' ' << 'D' << ' ' << 1 << '\n';
        sx++;
    }
    while (sy != ey) {
        cout << sx << ' ' << sy << ' ' << 'R' << ' ' << 1 << '\n';
        sy++;
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        curr[1][1].push(x);
    }

    dp[1][1] = 1;
    dp[1][2] = 2;
    dp[2][1] = 2;

    int tix = 0;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {

            if (dp[i][j]) continue;

            int val = 0;
            for (int ti = 1; ti <= i; ti++) {
                for (int tj = 1; tj <= j; tj++) {
                    val += dp[ti][tj];
                }
            }
            dp[i][j] = val;
        }
    }

    q.push(mp(1, mp(1, n)));
    
    while (!q.empty()) {

        int s, e, x;
        x = q.top().first;
        tie(s, e) = q.top().second;
        q.pop();

        if (x == 36) continue;

        int i = (x - 1) / 6 + 1;
        int j = (x - 1) % 6 + 1;

        int ti = 7 - i, tj = 7 - j;

        if (e == s + 1 && ( x == 35 || x == 30)) {
            int a = curr[i][j].top();
            curr[i][j].pop();

            int b = curr[i][j].top();
            curr[i][j].pop();
            
            if (a < b) {
                cout << i << ' ' << j << ' ' << char(x == 35 ? 'R' : 'D') << ' ' << 2 << '\n';
            }
            else {
                cout << i << ' ' << j << ' ' << char(x == 35 ? 'R' : 'D') << ' ' << 1 << '\n';
                cout << i << ' ' << j << ' ' << char(x == 35 ? 'R' : 'D') << ' ' << 1 << '\n';
            }
            if (a < b) swap(a, b);

            curr[6][6].push(a);
            curr[6][6].push(b);
            continue;
        }

        while (!curr[i][j].empty()) {
            int currx = curr[i][j].top();

            if (currx > e || currx < s) break;
            curr[i][j].pop();

            int ord = e - currx + 1;

            bool found = 0;
            int tot = 0;
            for (int ni = 1; ni <= ti; ni++) {
                for (int nj = 1; nj <= tj; nj++) {
                    tot += dp[ni][nj];

                    if (tot >= ord) {

                        // goto 6-ni+1, 6-nj+1;
                       // cout << "move: " << currx << ' ' << i << ' ' << j << " ->  " << 7 - ni << ' ' << 7 - nj << '\n';
                        goMove(i, j, 7 - ni, 7 - nj);
                        curr[7 - ni][7 - nj].push(currx);

                        found = 1;
                        break;
                    }
                }
                if (found) break;
            }
        }

        int te = e;
        for (int ni = 1; ni <= ti; ni++) {
            for (int nj = 1; nj <= tj; nj++) {
                
                if (te < s) break;
                int ne = te - dp[ni][nj];
                ne = max(ne, s - 1);

                int tx = 7 - ni;
                int ty = 7 - nj;

                q.push(mp((tx - 1) * 6 + ty, mp(ne + 1, te)));
                te = ne;
            }
        }
    }


}