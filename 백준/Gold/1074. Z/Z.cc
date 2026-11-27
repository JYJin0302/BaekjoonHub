#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, r, c;
    cin >> n >> r >> c;

    int ans = 0;
    while(n){
        int half = pow(2, n - 1);
        if (r >= half && c >= half) {
            ans += pow(half, 2) * 3;
            r -= half;
            c -= half;
        }
        else if (c >= half) {
            ans += pow(half, 2);
            c -= half;
        }
        else if (r >= half) {
            ans += pow(half, 2) * 2;
            r -= half;
        }
        n--;
    } 

    cout << ans;
}