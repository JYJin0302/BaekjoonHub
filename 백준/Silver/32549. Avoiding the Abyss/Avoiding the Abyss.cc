#include <bits/allocator.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const int INF = 1e9 - 10;
void solve(){   
    
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int sx, sy;
    cin >> sx >> sy;

    vector<pair<int, int>> path1, path2;
    // path1
    if (x1 < sx){
        path1.push_back(mp(-INF, y1));
    }
    else{
        path1.push_back(mp(INF, y1));
    }

    if(x2 < sx){
        path2.push_back(mp(-INF, y2));
    }
    else {
        path2.push_back(mp(INF, y2));
    }

    if (path2[0].x == path1[0].x){

    }
    else{
        path1.push_back(mp(path1[0].x, INF));
        path2.push_back(mp(path2[0].x, INF));
    }
    reverse(all(path2));

    cout << path1.size() + path2.size() << '\n';
    for(auto [a,b] : path1) cout << a<< ' ' << b << '\n';
    for(auto[a,b] : path2) cout << a << ' '<< b << '\n';

}
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}