#include <bits/allocator.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define mp make_pair
#define x first
#define y second

void solve(){
    
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for(auto& i : A) cin >> i;

    int a = 0, b = 0, c = 0;
    vector<int> B;
    for(auto f : A){
        if (f >= k) c++;
        else B.push_back(f);
    }
    sort(all(B));

    int l = 0, r = int(B.size()) - 1;
    while(l < r){
        while(l < r && B[r] + B[l] >= k) r--;
        if (l < r){
            a++;
            l++, r--;
        }
    }
    b = int(B.size()) - 2 * a;

    vector<pair<int, int>> T, tt;
    T.push_back(mp(a, 0));
    T.push_back(mp(b, 1));
    T.push_back(mp(c, 2));
    sort(all(T));
    
    //reverse(all(T));

    int ans = n, tmp = 0;

    do{
        tt = T;
        int tans = 0;

        tmp = min(T[0].x, T[2].x);
        T[0].x -= tmp, T[2].x -= tmp;
        tans += tmp;

        tmp = min(T[1].x, T[2].x);
        T[1].x -= tmp, T[2].x -= tmp;
        tans += tmp;

        tmp = min(T[0].x, T[1].x);
        a -= tmp, b -= tmp;
        tans += tmp;

        for(auto f : T){
            if (f.y == 0) tans += (2*f.x + 2) / 3;
            if (f.y == 1) tans += (f.x + 1) / 2;
            if (f.y == 2) tans += f.x;
        }

        ans = min(ans, tans);
        T = tt;
    }while(next_permutation(all(T)));

    cout << ans - 1 << '\n';

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}