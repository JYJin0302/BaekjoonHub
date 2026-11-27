#include <bits/stdc++.h>
using namespace std;

int tot = 0, err = 0;
int cnt[10001];
int tot_cnt[10001];

void add_num(int x){
    if (cnt[x] == 0) tot++;
    
    cnt[x]++;
    if (cnt[x] == tot_cnt[x]) err++;
}

void sub_num(int x){
    if (cnt[x] == 1) tot--;
    
    if (cnt[x] == tot_cnt[x]) err--;
    cnt[x]--;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    for(int i : A) tot_cnt[i]++;
    
    int l = 0, r = 0;    
    int ans = n;
    while(l < n && r < n){
        
        while(tot != k){
            while(r < n && tot != k){
                add_num(A[r]);
                r++;
            }
            
            if (r == n) break;
            while(err && l < r){ 
                sub_num(A[l]);
                l++;
            }
        }
        
        if (tot == k) ans = min(ans, r - l);
        sub_num(A[l]);
        l++;
    }
    
    if (ans == n) ans = 0;
    cout << ans;
}