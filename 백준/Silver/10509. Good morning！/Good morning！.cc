#include <bits/stdc++.h>
using namespace std;

bool vs[1001];
bool tp[1001][10];

void solve() {

    int n;
    cin >> n;

    int ans1 = 0, ans2 = 0;
    int tn = n;
    while (!vs[tn]) tn++;
    ans1 = tn - n;

    tn = n;
    while (!vs[tn]) tn--;
    ans2 = n - tn;

    if (ans1 < ans2) cout << n + ans1 << '\n';
    else cout << n - ans2 << '\n';
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    
    queue<pair<int, int>> q;
    tp[0][1] = 1;
    q.push({ 0, 1 });
    while (!q.empty()) {
        int a, b;
        tie(a, b) = q.front();
        q.pop();

        vs[a] = 1;
       // cout << a << ' ' << b << '\n';
        if (a >= 200) continue;

        int ta = a * 10 + b;
        if (ta <= 1000 && !tp[ta][b]) {
            tp[ta][b] = 1;
           // cout << "Press: " << ta << ' ' << b << '\n';
            q.push({ ta, b });
        }

        if (b % 3 != 0) {
            if (!tp[a][b + 1]) {
                tp[a][b + 1] = 1;
               // cout << "Right: " << a << ' ' << b + 1 << '\n';
                q.push({ a, b + 1 });
            }
            
        }

        if (b != 0 && b + 3 < 10) {
            if (!tp[a][b + 3]) {
                //cout << "Down: " << a << ' ' << b + 3 << '\n';
                tp[a][b + 3] = 1;
                q.push({ a, b + 3 });
            }
            
        }

        if (b == 8) {
            if (!tp[a][0]) {
                tp[a][0] = 1;
              //  cout << "Down: " << a << ' ' << 0 << '\n';
                q.push({ a , 0 });
            }
        }
    }

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

}