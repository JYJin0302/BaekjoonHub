#include <bits/stdc++.h>
#include "spirit.h"
#include "semia.h"
using namespace std;

vector<vector<int>> play_spirit(vector<pair<int, int>>& h) {
    vector<vector<int>> res(200, vector<int>(200));

    int n = 9;

    res[0][0] = 24;
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {

            if (res[i][j]) continue;
            if (i >= 50 && i < 150 && j >= 50 && j < 150) {

                int val = 0;
                for (int k = 0; k < n; k++) {
                    int tval = 0;

                    bool v1 = (h[k].first <= i);
                    bool v2 = (h[k].second <= j);

                    tval = v1 * 2 + v2;
                    val = val * 4 + tval;
                }

                vector<int> tmp;
                for (int k = 0; k < 4; k++) {
                    tmp.push_back((val % 23) + 1);
                    val /= 23;
                }

                res[i + 1][j + 1] = tmp[0];
                res[i + 1][j] = tmp[1];
                res[i][j + 1] = tmp[2];
                res[i][j] = tmp[3];
            }
            else {
                res[i][j] = 1;
            }

        }
    }

    return res;
}

vector<int> play_semia() {
    vector<int> res;

    int x, y;
    tie(x, y) = Find(24);

    int val = 0;
    bool b1 = x & 1;
    bool b2 = y & 1;

    val += 23 * 23 * 23 * (Get(0 - b1, 0 - b2) - 1);
    val += 23 * 23 * (Get(0 - b1, 1 - b2) - 1);
    val += 23 * (Get(1 - b1, 0 - b2) - 1);
    val += Get(1 - b1, 1 - b2) - 1;

    vector<int> c = { 1, 4, 2, 3 };
    for (int i = 0; i < 9; i++) {
        res.push_back(c[val % 4]);
        val /= 4;
    }
    reverse(res.begin(), res.end());

    return res;
}
