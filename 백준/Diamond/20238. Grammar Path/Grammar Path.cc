#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct BigInt {

    // reversed
    string val;

    BigInt() : val("0") {}
    BigInt(string _val) : val(_val) {}
    BigInt(int v) {
        val = "";
        while (v) {
            val += '0' + (v % 10);
            v /= 10;
        }
        if (val.empty()) val = "0";
    }


    BigInt operator+(const BigInt& o) const {
        string res = "";

        int c = 0;
        for (int i = 0; i < max(o.val.size(), val.size()); i++) {
            int curr = c;
            c = 0;
            if (i < val.size()) {
                curr += val[i] - '0';
            }
            if (i < o.val.size()) {
                curr += o.val[i] - '0';
            }
            if (curr >= 10) {
                curr -= 10;
                c = 1;
            }
            res.push_back('0' + curr);
        }
        if (c) res.push_back('1');

        return BigInt(res);
    }

    bool operator<(const BigInt& o) const {
        if (val.size() != o.val.size()) {
            return val.size() < o.val.size();
        }

        int tn = val.size();
        for (int i = tn - 1; i >= 0; i--) {
            if (val[i] != o.val[i]) return val[i] < o.val[i];
        }
        return 0;
    }
};

vector<pair<int, int>> TT[30];
vector<int> tT[30], adj[30];

BigInt dp[30][30][30];
set<int> dist[26][30];

struct Data {
    BigInt v;
    int c, a, b;

    Data(BigInt _v, int _c, int _a, int _b) : v(_v), c(_c), a(_a), b(_b) {}

    bool operator<(const Data& o) const {
        return tie(v, c, a, b) < tie(o.v, o.c, o.a, o.b);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int p;
    cin >> p;
    while (p--) {

        string a, b, c;
        cin >> a >> b >> c;
        if (c.size() == 2) {

            int v1 = c[0] - 'A';
            int v2 = c[1] - 'A';

            TT[a[0] - 'A'].push_back({ v1, v2 });
        }
        else {
            tT[c[0] - 'a'].push_back(a[0] - 'A');
        }
    }

    set<Data> st;


    int n, m, s, e;
    cin >> n >> m >> s >> e;
    s--, e--;
    while (m--) {
        int a, b;
        char c;
        cin >> a >> b >> c;

        a--, b--;
        adj[a].push_back(b);
        dist[a][1].insert(b);
        for (auto i : tT[c - 'a']) {
            dp[i][a][b] = BigInt(1);
            st.insert(Data(dp[i][a][b], i, a, b));
        }
    }

    while (!st.empty()) {
        Data curr = *st.begin();
        st.erase(st.begin());

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < 26; k++) {

                for (auto f : TT[k]) {
                    // curr.a -> curr.b -> i
                    if (f.first == curr.c && dp[f.second][curr.b][i].val != "0") {
                        BigInt newV = curr.v + dp[f.second][curr.b][i];
                        if (dp[k][curr.a][i].val == "0" || newV < dp[k][curr.a][i].val) {
                            if(st.find(Data(dp[k][curr.a][i], k, curr.a, i)) != st.end()) 
                                st.erase(st.find(Data(dp[k][curr.a][i], k, curr.a, i)));
                            st.insert(Data(newV, k, curr.a, i));
                            dp[k][curr.a][i] = newV;
                        }
                    }
                    // i -> curr.a -> curr.b
                    if (f.second == curr.c && dp[f.first][i][curr.a].val != "0") {
                        BigInt newV = curr.v + dp[f.first][i][curr.a];
                        if (dp[k][i][curr.b].val == "0" || newV < dp[k][i][curr.b].val) {
                            if (st.find(Data(dp[k][i][curr.b], k, i, curr.b)) != st.end())
                                st.erase(st.find(Data(dp[k][i][curr.b], k, i, curr.b)));
                            st.insert(Data(newV, k, i, curr.b));
                            dp[k][i][curr.b] = newV;
                        }
                    }
                }
            }
        }
    }


    string ans = dp['S' - 'A'][s][e].val;
    reverse(ans.begin(), ans.end());
    if (ans == "0") ans = "NO";
    cout << ans;
}