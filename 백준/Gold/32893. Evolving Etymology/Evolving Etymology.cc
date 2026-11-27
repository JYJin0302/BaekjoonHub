#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    
    ll v = 1, b = 2;
    while (k) {
        if (k & 1) {
            v = v * b % n;
        }
        k >>= 1;
        b = b * b % n;
    }

    for (int i = 0; i < n; i++) {
        int ix = (i * v) % n;
        cout << s[ix];
    }

}