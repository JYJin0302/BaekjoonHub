#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    
    deque<int> dq;
    for (int i = 1; i <= n; i++) dq.push_back(i);
    
    vector<int> ans;
    
    while(!dq.empty()){
        for (int i = 0; i < k - 1; i++){
            dq.push_back(dq.front());
            dq.pop_front();
        }
        
        ans.push_back(dq.front());
        dq.pop_front();
    }
    
    cout << "<" << ans[0];
    for (int i = 1; i < n; i++) cout << ", " << ans[i];
    cout << ">";
}