#include <bits/stdc++.h>
using namespace std;

int n, m, sn;
vector<int> A;

void update(int i, int v){
    while(i <= sn){
        A[i] += v;
        i += (i & -i);
    }
}

int ssum(int i){
    if (i == 0) return 0;
    
    int r = 0;
    while(i > 0){
        r += A[i];
        i -= (i & -i);
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    sn = 1;
    while(sn < n) sn *= 2;
    
    vector<pair<int, int>> B(n);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        B[i] = {a, i+1};
    }
    sort(B.begin(), B.end());
    
    vector<int> idx(n+1);
    for (int i = 0; i < n; i++){
        idx[B[i].second] = i+1;
    }
     
    A = vector<int> (sn+1);
    
    for (int i = 1; i <= n; i++){
        
        int x = idx[i];
        
        cout << i - ssum(x-1) << '\n';
        update(x, 1);
    }
}