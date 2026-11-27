#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int ans[5];
void getAward(int score) {
    if (score < 35) return;
    if (score < 65) ans[1]++;
    else if (score < 95) ans[2]++;
    else if (score < 125) ans[3]++;
    else ans[4]++;
}

void solve() {

    int n;
    cin >> n;

    int scoreAdd = 1;
    int timeAdd = 4;
    int totTime = 0;
    int totScore = 0;

    for (int i = 0; i < n; i++) {
        if (totTime > 240) {
            getAward(totScore);
            totTime = 0;
            totScore = 0; 
            scoreAdd = 1;
            timeAdd = 4;
        }
        int x;
        cin >> x;
        if (x == 1) {
            getAward(totScore);
            totTime = 0;
            totScore = 0;
            scoreAdd = 1;
            timeAdd = 4;
            continue;
        }

        if (x == 2) {
            if (scoreAdd > 1) scoreAdd >>= 1;
            else timeAdd += 2;
        }
        else if (x == 3) {

        }
        else if (x == 4) {
            totTime += 56;
        }
        else if (x == 5) {
            if (timeAdd > 1) timeAdd--;
        }
        else {
            if (scoreAdd < 32) scoreAdd <<= 1;
        }
        totScore += scoreAdd;
        totTime += timeAdd;
    }

    for (int i = 1; i <= 4; i++) cout << ans[i] << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
   // cin >> t;
    while (t--) solve();
}