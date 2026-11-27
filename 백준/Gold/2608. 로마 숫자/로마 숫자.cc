#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

// I, V, X, L, C, D, M
// 1 5 10 50 100 500 1000

map<char, int> val;
char lst[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };

int s2int(string s) {
    int n = s.size();
    int res = 0;

    for (int i = 0; i < n; i++) {
        if (i == n - 1 || val[s[i]] >= val[s[i + 1]]) res += val[s[i]];
        else res -= val[s[i]];
    }
    return res;
}

string int2s(int v) {
    string res;

    int ix = 0;
    while (v) {
        int tv = v % 10;
        v /= 10;

        string ad;
        if (tv <= 3) ad = string(tv, lst[ix]);
        else if (tv == 4) ad = string(1, lst[ix + 1]) + lst[ix];
        else if (tv <= 8) ad = string(tv - 5, lst[ix]) + lst[ix + 1];
        else ad = string(1, lst[ix + 2]) + lst[ix];
        
        res += ad;
        ix += 2;
    }
    reverse(all(res));
    return res;
}

void solve() {
    val['I'] = 1;
    val['V'] = 5;
    val['X'] = 10;
    val['L'] = 50;
    val['C'] = 100;
    val['D'] = 500;
    val['M'] = 1000;

    string a, b;
    cin >> a >> b;
    int va = s2int(a);
    int vb = s2int(b);
    cout << va + vb << '\n' << int2s(va + vb) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}