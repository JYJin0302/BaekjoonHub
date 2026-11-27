#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, l, k;

    cin >> n >> l >> k;

    int easy = 0, diff = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        
        if (b <= l) diff++;
        else if (a <= l) easy++;
    }

    int ans = 0;
    ans += 140 * (min(k, diff));
    k -= min(k, diff);
    ans += 100 * (min(k, easy));
    
    cout << ans;
}