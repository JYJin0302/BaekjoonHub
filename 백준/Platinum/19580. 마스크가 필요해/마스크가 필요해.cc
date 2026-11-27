#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<pair<ll, ll>> A(n), B(m);
    for(auto& i : A) cin >> i.x >> i.y;
    for(auto& i : B) cin >> i.x >> i.y;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int ai = 0, bi = 0, ans = 0;
    
    priority_queue<ll, vector<ll>, greater<ll>> pq; 
    
    while(bi < m){
        
        while(ai < n && B[bi].x >= A[ai].x) {
            pq.push(A[ai].y);
            ai++;
        }
        
        while(!pq.empty() && pq.top() < B[bi].x) pq.pop();
        
        while (!pq.empty() && B[bi].y > 0){
            pq.pop();
            B[bi].y--;
            ans++;
        }
        
        bi++;
    }
    cout << ans;
}