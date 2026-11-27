#include <bits/stdc++.h>
using namespace std;

vector<int> A;
vector<vector<int>> ans;
void solve(int l,int r, int d){
    int mid = (l+r)/2;
    ans[d].push_back(A[mid]);
    
    if (l == r) return;
    solve(l, mid-1, d+1);
    solve(mid+1, r, d+1);
}

int main(){
    
    int k;
    cin >> k;
    
    int size = pow(2, k) - 1;
    A = vector<int> (size);
    for(auto& i : A) cin >> i;
    
    ans = vector<vector<int>> (k);
    
    solve(0, size - 1, 0);
    
    
    for (int i = 0; i < k; i++){
        for (int j : ans[i]) cout << j << ' ';
        cout << '\n';
    }
    
}