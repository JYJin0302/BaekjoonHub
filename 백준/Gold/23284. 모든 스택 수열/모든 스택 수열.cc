#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int n;
stack<int> st;
vector<int> res;

void backtrack(int nxt, int used = 0) {
    if (nxt > n && used == n) {
        for (auto f : res) cout << f << ' ';
        cout << '\n';
        return;
    }

    if (nxt > used + 1) {
        int x = st.top();
        res.push_back(st.top());
        st.pop();
        backtrack(nxt, used + 1);
        st.push(x);
        res.pop_back();
    }

    if (nxt <= n) {
        st.push(nxt);
        backtrack(nxt + 1, used);
        st.pop();
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    backtrack(1);

}