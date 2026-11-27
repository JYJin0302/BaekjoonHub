#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<pair<int, int>> A(n);
    for(auto& i : A) cin >> i.x >> i.y;
    sort(A.rbegin(), A.rend());
    
    priority_queue<pair<int, int>> pq;
    int curr_time = n;
    int idx = 0;
    int ans = 0;
    
    while(curr_time > 0){
        
        while(idx < n && A[idx].x >= curr_time) {
            pq.push({A[idx].y, A[idx].x});
            idx++;
        }
        
        if (!pq.empty()){
            ans += pq.top().x;
            pq.pop();
        }
        
        curr_time--;
    }
    
    cout << ans;
}