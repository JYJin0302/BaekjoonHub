#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

bool cmp(pair<double, double> p1, pair<double, double> p2){
    if ((p1.x <0) != (p2.x <0)){
        return p1.x < p2.x;
    }
    if (p1.x == 0 && p2.x == 0) return p1.y < p2.y;

    return p1.x * p2.y - p2.x * p1.y > 0;
}

void solve(){
    
    int n;
    cin >> n;

    vector<pair<double, double>> A;
    double tx = 0, ty = 0;
    for(int i = 0;  i < n; i++){
        double x ,y;
        cin >> x >> y;
        A.push_back(mp(x, y));
        tx += x;
        ty += y;
    }
    tx /= n, ty /= n;

    for(auto&[a,b]: A) a -= tx, b -= ty;

    sort(all(A), cmp);

    ld ans = 1e15;
    for(int i = 0; i < n; i++){
        int pi = (i+1)% n;
        ld dx = A[i].x - A[pi].x;
        ld dy = A[i].y - A[pi].y;
        ans = min(ans, dx*dx + dy*dy);
    }
    cout << setprecision(20);
    cout << sqrtl(ans) << '\n';
    
}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}