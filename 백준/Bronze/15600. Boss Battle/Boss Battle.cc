#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){

    int n;

    cin >>n;

    if (n <= 3) cout << 1;

    else cout << n-2;

}

int main(){

    std::ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    solve();

    return 0;

}

