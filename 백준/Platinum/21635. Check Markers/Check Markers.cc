#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){
    
    int n;
    cin >> n;

    vector<pair<ll, ll>> A(n);
    for(auto& i : A) cin >> i.x;
    for(auto& i : A) cin >> i.y;
    sort(all(A));

    pair<ll, ll> tot;
    for(auto f : A){
        tot.x += f.x;
        tot.y += f.y;
    }

    vector<int> lst;
    for(int i = 0; i < n;i++){
        if (tot.x - A[i].x < A[i].y){
            lst.push_back(i);
        }
    }
    if ((int)lst.size() >= 2){
        cout << "NO\n";
        return;
    }
    
    ll tar = 0;
    if (lst.empty()){
        for(auto f : A) tar= max(tar, f.y);
    }
    else tar = A[lst[0]].y;

    if(tot.x >= tot.y - tar) cout << "YES\n";
    else cout << "NO\n";

}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
