#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, sz;
string board;

int solve(int pos, int currSize, int mov = 0) {
    // pos : 현재 토끼 위치
    // mov : 이전의 토끼의 움직임 : 0 오른쪽으로 이동, 1 왼쪽으로 이동

    if (currSize == 2) {
        int res = 0;
        for (int i = 0; i < 2; i++) if (pos & (1 << i)) res++;
        return res;
    }

    vector<int> tmp(currSize);
    int newMove = 0;

    for (int i = 0; i < currSize; i++) {
        if (pos & (1 << i)) {

            if (i == 0) {
                tmp[i + 1]++;
            }
            else if (i >= currSize - 2) {
                tmp[i - 1]++;
                if (newMove & (1 << (i - 1))) {}
                else newMove += (1 << (i - 1));
            }
            else {

                if (board[i] == 'B') {
                    // move right
                    tmp[i + 1]++;

                }
                else if (board[i] == 'W') {
                    // move left
                    tmp[i - 1]++;
                    if (newMove & (1 << (i - 1))) {}
                    else newMove += (1 << (i - 1));
                }
                else {
                    if (mov & (1 << i)) {
                        tmp[i + 1]++;
                    }
                    else {
                        tmp[i - 1]++;
                        if (newMove & (1 << (i - 1))) {}
                        else newMove += (1 << (i - 1));
                    }
                }

            }
        }
    }

    int res = 0;
    for (int i = 0; i < currSize; i++) {
        if (tmp[i] >= 2) {
            tmp[i] = 0;
            if (newMove & (1 << i)) newMove -= (1 << i);
        }
        else if (tmp[i] == 1) res += (1 << i);
    }
    return solve(res, currSize - 1, newMove);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);

    cin >> board;

    cin >> n;
    sz = board.size();

    vector<int> pos(sz);
    for (int i = 0; i < n; i++) {
        pos[sz - 1 - i] = 1;
    }

    int tot = 0,cnt = 0;
    do {
        int ps = 0;
        for (int i = 0; i < sz; i++) {
            if (pos[i]) {
                ps += (1 << i);
            }
        }

        int val =solve(ps, sz);
        tot += val;
        cnt++;
    } while (next_permutation(pos.begin(), pos.end()));

    long double ans = tot;
    ans /= cnt;
    cout << ans;
}