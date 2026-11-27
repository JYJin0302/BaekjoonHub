#include<bits/stdc++.h>
using ll = long long;
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    for (int i = 10; i >= 1; i--) {
        if (a % i == 0 && b % i == 0) a /= i, b /= i;
    }
    vector<string> ans;

    bool ov = 0;
    if (a > b) {
        ov = 1;
    }
    else swap(a, b);

    a = a * a, b = b * b;
    while (a + b != 2) {
        int c = a - b;

        //cout << a << ' ' << b << '\n';
        if (c > b) {
            ans.push_back("sin");
            ans.push_back("atan");
            a = c;
        }
        else {
            ans.push_back("cos");
            ans.push_back("atan");
            a = c;
            swap(a, b);
        }

        
    }

    ans.push_back("cos");
    reverse(ans.begin(), ans.end());

    if (ov) {
        for (auto i : { "atan", "sin", "acos", "tan"}) ans.push_back(i);
    }

    cout << ans.size() << '\n';
    for (auto i : ans) cout << i << ' ';

}
