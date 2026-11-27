#include <bits/stdc++.h>
using ll = long long;
using namespace std;

string A[9];

vector<int> dp, tmp;
// 0-8 열, 9-11 박스

string pf(int x) {
    string s;
    for (int i = 0; i < 12; i++) {
        int v = (x & (1 << i));
        s += char('0' + (v > 0));
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 9; i++) cin >> A[i];

    dp = vector<int>(1 << 12, 100);
    dp[0] = 0;

    for (int i = 0; i < 9; i++) {
        tmp = vector<int>(1 << 12, 100);

        for (int j = 0; j < (1 << 9); j++) {
            // i행을 j에 해당하는 배열로 바꿈
            int cost = 0, cnt = 0;
            for (int k = 0; k < 9; k++) {
                bool c1 = (j & (1 << k));
                bool c2 = (A[i][k] == '1');
                cost += c1 ^ c2;
                cnt += c1;
            }

            if (cnt % 2 == 1) continue;

            for (int k = 0; k < (1 << 12); k++) {
                int tk = k;
                for (int w = 0; w < 9; w++) {
                    if (j & (1 << w)) {
                        tk ^= (1 << w);
                        tk ^= (1 << (w / 3 + 9));
                    }
                }
                tmp[tk] = min(tmp[tk], dp[k] + cost);
            }

        }


        if (i % 3 == 2) {
            for (int j = 0; j < (1 << 12); j++) {
                int cnt = 0;
                cnt += ((j & (1 << 9)) != 0);
                cnt += ((j & (1 << 10)) != 0);
                cnt += ((j & (1 << 11)) != 0);

                if (cnt) tmp[j] = 100;
            }
        }

        swap(tmp, dp);
    }
    cout << dp[0];

}