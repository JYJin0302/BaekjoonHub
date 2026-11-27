#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = (1 << 20) + 10;
vector<int> adj[MAX_N];

int lv[MAX_N];

vector<int> res;
void dfs(int v, int pv = -1) {

    bool ok = 1;
    lv[v] = 0;
    map<int, int> mp;
    int mv = -1;
    for (auto i : adj[v]) if (i != pv) {
        dfs(i, v);
        mp[lv[i]]++;
        mv = max(mv, lv[i]);
    }
    if (!res.empty()) return;


    bool t1 = 0;
    for (int i = 0; i <= mv; i++) {
        if (mp[i] != 1) ok = 0;
        if (mp[i] == 2) t1 = 1;
    }

    if (!ok) {
        if (t1) {

            for (auto i : adj[v]) if (i != pv) {
                if (mp[lv[i]] == 2) res.push_back(i);
            }

            return;
        }

        res.push_back(v);
    }
    lv[v] = mv + 1;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int sz = pow(2, n);
    vector<int> winCnt(sz + 1), loseCnt(sz+1);

    for (int i = 0; i < sz - 2; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        winCnt[a]++;
        loseCnt[b]++;
    }

    int cnt = 0, t1 = -1, t2 = -1;
    vector<int> tmp;
    for (int i = 1; i <= sz; i++) {
        if (winCnt[i] == n) {
            t1 = i;
        }
        if (loseCnt[i] == 0) {
            cnt++;
            tmp.push_back(i);
            t2 = i;
        }
    }

    if (cnt == 2) {
        int a = tmp[0], b = tmp[1];
        if (winCnt[a] == winCnt[b]) {
            cout << a << ' ' << b << '\n' << b << ' ' << a << '\n';
            return 0;
        }

        dfs(a);
        if (res.empty()) {
            dfs(b);
            swap(a, b);
        }
        sort(res.begin(), res.end());
        for (auto i : res) cout << i << ' ' << b << '\n';
        return 0;
    }
    //cout << "?";
    // root = t1;
    //dfs(t2);
    dfs(t1);

    sort(res.begin(), res.end());

    for (auto i : res) {
        cout << i << ' ' << t2 << '\n';
    }

}