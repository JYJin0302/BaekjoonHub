#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 1000000000

#define x first
#define y second

ll n;
pair<ll, ll> v[20][20];
string s;

void solve(int l, int r){
    
    if (v[l][r].x != -INF) return; 
    if (l == r) {
        v[l][r] = {s[l] - '0', s[l] - '0'};
        return;
    }
    
    
    ll vM = -INF, vm = INF;
    for (int i = l; i < r; i+= 2){
        solve(l, i);solve(i+2, r);
        pair<ll, ll> L = v[l][i];
        pair<ll, ll> R = v[i+2][r];
        
        if (s[i+1] == '+') {
            vM = max(vM, L.x+R.x);
            vm = min(vm, L.y+R.y);
        }
        else if (s[i+1] == '-'){
            vM = max(vM, L.x-R.y);
            vm = min(vm, L.y-R.x);
        }
        else if(s[i+1] == '*') {
            vM = max({vM, L.x*R.x, L.y*R.y});
            vm = min({vm, L.x*R.y, L.y*R.x});
        }
    }
    
    v[l][r] = {vM, vm};
}

int main(){
    
    for (int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            v[i][j] = {-INF, INF};
        }
    }
    
    cin >> n;
    cin >> s;
    solve(0, n-1);
    cout << v[0][n-1].x;
}