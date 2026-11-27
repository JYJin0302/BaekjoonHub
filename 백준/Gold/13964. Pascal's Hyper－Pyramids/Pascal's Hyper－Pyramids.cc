#include<bits/stdc++.h>
using ll = long long;
using namespace std;

vector<vector<ll>> lst;

vector<pair<ll, ll>> pList[33];

int d, h;
void solve(int ix, int sum, int pMax, vector<ll> curr) {
    if (ix == d) {
        if (sum == h) lst.push_back(curr);
        return;
    }

    vector<ll> tmp = curr;
    for (int i = pMax; i <= min(h - sum, h); i++) {
        tmp.push_back(i);
        solve(ix + 1, sum + i, i, tmp);
        tmp.pop_back();
    }
}

ll getVal(vector<ll>& v) {
    map<ll, ll> cnt;
    for (int i = 2; i <= h; i++) {
        for (auto k : pList[i]) {
            cnt[k.first] += k.second;
        }
    }

    for (auto i : v) {
        for (int j = 2; j <= i; j++) {
            for (auto k : pList[j]) {
                cnt[k.first] -= k.second;
            }
        }
    }

    ll res = 1;
    for (auto iter = cnt.begin(); iter != cnt.end(); iter++) {
        if (iter->second != 0) {
            for (int i = 0; i < iter->second; i++) res *= iter->first;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> d >> h;
    h--;
    solve(0, 0, 0, {});

    
    for (int i = 2; i <= 31; i++) {
        int ti = i;
        for (int j = 2; j * j <= ti; j++) {
            if (ti % j == 0) {
                int tcnt = 0;
                while(ti % j == 0) {
                    ti /= j;
                    tcnt++;
                }
                pList[i].push_back({ j, tcnt });
            }
        }

        if (ti != 1) pList[i].push_back({ ti, 1 });
    }

    set<ll> ansList;
    for (auto i : lst) {
        ansList.insert(getVal(i));
    }

    for (auto i : ansList) cout << i << '\n';
}