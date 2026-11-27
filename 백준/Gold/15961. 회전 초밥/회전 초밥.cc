#include <bits/stdc++.h>
using namespace std;

int val = 0;
int cnt[3001];

void add_num(int x){
    if (cnt[x] == 0) val++;
    cnt[x]++;
}

void sub_num(int x){
    if(cnt[x] == 1) val--;
    cnt[x]--;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, d, k, c;
    cin >> n >> d >> k >> c;
    
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    int l = 0, r = k-1;
    int cnt = 1, ans = 0;
    val = 0;
    
    add_num(c);
    for (int i = l; i <= r; i++){
        add_num(A[i]);
    }
    ans = max(ans, val);
    
    while(cnt < n){
        
        sub_num(A[l]);
        l = (l+1)%n;
        r = (r+1)%n;
        add_num(A[r]);
        ans = max(ans, val);
        
        cnt++;
    }
    cout << ans;
}