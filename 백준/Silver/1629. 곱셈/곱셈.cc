#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string bin = "";
void binary(int n) {
    if (n == 1) { bin += '1'; return; }
    binary(n / 2);

    bin += '0' + n % 2;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    ll ans = 1;
    binary(b);

    int size = bin.size();

    vector<ll> base(size);
    base[0] = a % c;
    for (int i = 1; i < size; i++) {
        base[i] = (base[i - 1] * base[i - 1]) % c;
    }

    for (int i = 0; i < size; i++) {
        if (bin[i] == '1') ans = (ans * base[size - 1 - i]) % c;
    }
    cout << ans;
}