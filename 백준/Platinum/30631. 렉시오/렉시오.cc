#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

vector<ll> num;
int getIdx(ll x) {
    return lower_bound(num.begin(), num.end(), x) - num.begin();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    vector<ll> A(n);
    for (auto& i : A)cin >> i;

    vector<ll> nCnt(1010101), nSum(1010101);
    for (auto f : A) {
        nCnt[f]++;
        nSum[f] += f;
    }

    for (int i = 1; i <= 1000000; i++) {
        nCnt[i] += nCnt[i - 1];
        nSum[i] += nSum[i - 1];
    }

    for (auto& i : A) {
        ll nval = 0;
        nval += (nSum[1000000] - nSum[i]) - i * (nCnt[1000000] - nCnt[i]);
        nval -= i * nCnt[i] - nSum[i];
        i = nval;
    }
    for (int i = 1; i < n; i++) A[i] += A[i - 1];

    vector<ll> zCnt(n);
    for (int i = 0; i < n; i++) {
        if (A[i] == 0) zCnt[i]++;
        if (i) zCnt[i] += zCnt[i - 1];
    }
    num = A;
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());

    int sz = num.size();

    vector<vector<int>> numList(sz);
    for (int i = 0; i < n; i++) {
        if (A[i] != 0) {
            int ix = getIdx(A[i]);
            numList[ix].push_back(i);
        }
    }

    ll ans = n - zCnt[n - 1];
    for (int i = 0; i < sz; i++) {

        int pv = numList[i][0];
        ll curr = 1, mx = 1;
        for (int j = 1; j < numList[i].size(); j++) {
            curr -= zCnt[numList[i][j]] - zCnt[numList[i][j - 1]];
            curr = max(1ll, curr + 1);
            mx = max(mx, curr);
        }

        ans = min(ans, n - zCnt[n - 1] - mx + 1);
    }
    cout << ans;

}