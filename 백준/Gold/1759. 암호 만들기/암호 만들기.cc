#include <bits/stdc++.h>
using namespace std;


int l, c;
vector<char> base;
void select(int f = 0, string st = "") {
    if (st.size() == l) {
        int cntv = 0;

        for (char i : st) {
            if (i == 'a' || i == 'o' || i == 'u' || i == 'i' || i == 'e') cntv++;
        }
        if (cntv >= 1 && st.size() - cntv >= 2) cout << st << '\n';
        return;
    }
    for (int i = f; i < c; i++) {
        select(i + 1, st + base[i]);
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> l >> c;
    base = vector<char>(c);
    for (auto& i : base) cin >> i;

    sort(base.begin(), base.end());
    select();

}