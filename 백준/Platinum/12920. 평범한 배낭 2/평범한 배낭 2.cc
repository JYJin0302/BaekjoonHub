#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Data {
    int v, c, k;
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<Data> A(n);
    for (auto& i : A) cin >> i.v >> i.c >> i.k;


    vector<int> dp(m + 1), tmp(m + 1);

    for (int i = 0; i < n; i++) {
        tmp = dp;

        deque<pair<int, int>> dq;
        
        for (int j = 0; j < A[i].v; j++) {

            for (int tj = 0; j + tj*A[i].v <= m; tj++) {
                int currval = dp[j + tj * A[i].v] - A[i].c * tj;
                while (!dq.empty() && dq.back().first <= currval) {
                    dq.pop_back();
                }
                dq.push_back({ currval, tj });

                while (!dq.empty() && dq.front().second + A[i].k < tj) dq.pop_front();
                /*cout << "Curr idx :" << j + tj * A[i].v << '\n';
                for (auto k = dq.begin(); k != dq.end(); k++) cout << '{' << k->first << ", " << k->second << "} ";
                cout << '\n';*/

                tmp[j + tj * A[i].v] = dq.front().first + A[i].c * tj;
            }
            while (!dq.empty()) dq.pop_back();
        }

        swap(tmp, dp);

       /*for (int j = 0; j <= m; j++) cout << dp[j] << ' ';
       cout << '\n';*/
    }

    cout << dp[m];
}