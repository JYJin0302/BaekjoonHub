#include <bits/stdc++.h>
using namespace std;

int n, m;
string ans;
vector<int>base;
vector<bool> check;
set<string> st;

void p(int f = 0, int cnt = 0, string temp = "") {
    if (cnt == m) {
        int tt = st.size();
        st.insert(temp);
        if (st.size() == tt) return;
        cout << temp << '\n';
        return;
    }

    for (int i = f; i < n; i++) {
        p((int)i, (int)cnt + 1, (string)(temp + to_string(base[i]) + " "));
        
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    check = vector<bool>(n);
    base = vector<int>(n);
    for (auto& i : base)cin >> i;
    sort(base.begin(), base.end());

    p();
}