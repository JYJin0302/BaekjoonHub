#include <bits/stdc++.h>
using namespace std;

int n, d, k, ans;
vector<vector<int>> A;

void solve(int x){
    
    int cnt = 0;
    for(int i = 0; i < n; i++){
        
        bool ok = 1;
        for (int a : A[i]){
            if (((1 << a) & x) == 0) ok = 0;
        }
        cnt += ok;
    }
    ans = max(ans, cnt);
}


void setNum(int pi = 0, int pv = 0, int cnt = 0){
    if(cnt == k){
        solve(pv);
        return;
    }
    
    for (int i = pi; i <= d; i++){
        int nv = pv | (1 << i);
        setNum(i+1, nv, cnt+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> d >> k;
    
    A = vector<vector<int>> (n);
    for(int i = 0; i < n; i++){
        
        int x;
        cin >> x;
        while(x--){
            int a;
            cin >> a;
            A[i].push_back(a-1);
        }
    }
    
    ans = 0;
    setNum();
    cout << ans;
    
}