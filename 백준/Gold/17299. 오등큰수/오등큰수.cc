#include <bits/stdc++.h>
using namespace std;

int cnt[1000001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> A(n);
    for(auto& i : A) {
        cin >> i;
        cnt[i]++;
    }
    
    stack<pair<int, int>> st;
    vector<int> ans(n);
    
    for (int i = n-1; i >=0 ;i --){
        int val = cnt[A[i]];
        
        while(!st.empty() && st.top().first <= val) st.pop();
        
        if (st.empty()) ans[i] = -1;
        else ans[i] = st.top().second;
        st.push({val, A[i]});
    }
    
    for(int i = 0; i < n; i++){
        cout << ans[i] << ' ';
    }
    
}