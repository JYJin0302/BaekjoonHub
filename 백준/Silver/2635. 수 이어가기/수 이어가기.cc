#include <bits/stdc++.h>
using namespace std;

int cnt;
void cal(int n, int m) {
    if (m > n) return;

    cnt++;
    cal(m, n - m);
}




int main() {

    int n;
    cin >> n;

    int ans = 0, ind = -1;
    for (int i = 1; i <= n+1; i++) {
        cnt = 2;
        cal(n, i);
        if (ans < cnt) {
            ans = cnt;
            ind = i;
        }
    }
    cout << ans << '\n';
    cout << n << ' ' << ind << ' ';
    while (n - ind >= 0) {
        cout << n - ind << ' ';
        int temp = ind;
        ind = n - ind;
        n = temp;
    }
}