#include <bits/allocator.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
void solve(){
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edg;
    for(int i =0 ; i< m;i++){
        int a, b;
        cin >> a>> b;
        edg.push_back(mp(a, b));
    }

    cout << "YES\n";
    cout << m*2 << '\n';
    for(auto[a,b] : edg){
        for(int i = 1; i <= n; i++){
            if (i == a || i == b) continue;
            cout << i << ' ';
        }
        cout << a << ' ' << b << '\n';

        cout << a << ' ' << b << ' ';
        for(int i = n; i >= 1; i--){
            if (i == a || i == b) continue;
            cout << i << ' ';
        }
        cout << '\n';
    }


}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}