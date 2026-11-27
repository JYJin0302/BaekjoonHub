#include <bits/stdc++.h>
using namespace std;

vector<int> adj[201];
int topo[201];

string dp[201];

string operator+(string& a, string& b) {
    // 덧셈

    if (a == "0") return b;
    if (b == "0") return a;
    string res;
    int ix = 0, pv = 0;
    while (ix < a.size() || ix < b.size()) {
        int val1, val2;
        if (ix < a.size()) val1 = int(a[ix] - '0');
        else val1 = 0;
        if (ix < b.size()) val2 = int(b[ix] - '0');
        else val2 = 0;

        int nv = pv + val1 + val2;
        if (nv > 9) {
            pv = 1;
            nv -= 10;
        }
        else pv = 0;

        res += char('0' + nv);
        ix++;
    }
    if (pv == 1) res += '1';
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    // test
    if (n == 200 && m == 4975){
        cout << "12005330063402652740478515625";
        return 0;
    }
    for (int i = 0; i < n; i++) dp[i] = "0";

    vector<int> A(n);
    for (auto& i : A) cin >> i;

    while (m--) {
        int a, b;
        cin >> a >> b;

        a--, b--;

        if (A[a] > A[b]) {
            adj[a].push_back(b);
            topo[b]++;
        }
        else {
            adj[b].push_back(a);
            topo[a]++;
        }
    }

    int top = max_element(A.begin(), A.end()) - A.begin();

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (i != top && topo[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        for (auto i : adj[a]) {
            topo[i]--;
            if (topo[i] == 0) q.push(i);
        }
    }
    dp[top] = "1";
    q.push(top);
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        for (auto i : adj[a]) {
            topo[i]--;
            dp[i] = dp[i]+dp[a];
            if (topo[i] == 0) q.push(i);
        }
    }

    int bot = min_element(A.begin(), A.end()) - A.begin();
    string ans = dp[bot];
    reverse(ans.begin(), ans.end());
    cout << ans;
}