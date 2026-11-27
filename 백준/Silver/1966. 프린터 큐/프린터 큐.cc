#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, a;
        cin >> n >> m;
        
        vector<int> prior(n);
        for(auto& i : prior) cin >> i;
        
        int maxn = *max_element(prior.begin(), prior.end());
        queue<int> q;
        for (int i = 0; i < n; i++) q.push(i);
        
        int cnt = 0;
        while(1){
            a = q.front();
            q.pop();
            if (prior[a] < maxn) q.push(a);
            else{
                cnt++;
                prior[a] = 0;
                maxn = *max_element(prior.begin(), prior.end());
                if (a == m) break;
            }
        }
        cout << cnt << '\n';
    }
    
    
}