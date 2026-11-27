#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll a, b;
    cin >> a >> b;

    if ((a-1) % (b+1) == 0) cout << "Can't win\n";
    else cout << "Can win\n";
}