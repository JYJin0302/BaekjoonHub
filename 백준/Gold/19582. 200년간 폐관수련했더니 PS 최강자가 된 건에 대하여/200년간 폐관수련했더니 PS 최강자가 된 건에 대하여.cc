#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second

ll dp[100001][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;
    cin >> n;
    
    vector<pair<ll,ll>> A(n);
    for(auto& i : A)cin >> i.x >> i.y;
    
    ll a = 0, b = 0;
    
    bool ok = 1;
    
    int cnt = 1;
    for(int i = 0; i < n; i++){
        if (A[i].x >= a) {
            a += A[i].y;
            b = max(b, A[i].y);
        }
        else{
            if (cnt == 0){
                ok = 0;
                break;
            }
            cnt--;
            
            if (a - b > A[i].x){
                continue;
            }
            
            a += min(0ll, A[i].y - b);
        }
    }
    
    if (ok) cout << "Kkeo-eok";
    else cout << "Zzz";    
}