#include <bits/stdc++.h>
using namespace std;

struct B{
    int s, w, h, idx;
    
    bool operator<(const B& o){
        if (s == o.s) return w < o.w;
        return s < o.s;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    
    vector<B> A(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i].s >> A[i].h >> A[i].w;
        A[i].idx = i;
    }
    
    sort(A.begin(), A.end());
    vector<int> dp(n);
    dp[0] = A[0].h;
    for(int i = 1; i < n; i++){
        dp[i] = A[i].h;
        for(int j = 0; j < i; j++){
            if (A[i].w > A[j].w && A[i].s > A[j].s) dp[i] = max(dp[i], dp[j] + A[i].h);
        }
    }
    
    int nx = max_element(dp.begin(), dp.end()) - dp.begin();
    vector<int> ans;
    ans.push_back(A[nx].idx);
    
    while(nx >= 0){
        int tx = -1;
        for (int x = 0; x < nx; x++){
            if (A[nx].w > A[x].w && A[nx].s > A[x].s && dp[nx] == dp[x] + A[nx].h) {
                tx = x;
                break;
            }
        }
        
        if (tx == -1) break;
        ans.push_back(A[tx].idx);
        nx = tx;
    }
    
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(auto i : ans) cout << i+1 << '\n';
}