// 참고 : https://jwvg0425-ps.tistory.com/98

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<ll> A(n);
    for(auto&i  : A) cin >> i;
    
    ll min_val = 0, t = 0;
    priority_queue<ll> pq;
    
    pq.push(A[0]);
    for(int i = 1; i < n; i++){
        
        t++;
        ll x = A[i];
        ll min_pos = pq.top() + t;
        
        if (x >= min_pos) pq.push(x - t);
        else{
            min_val += min_pos - x;
            pq.push(x-t);
            pq.pop();
            pq.push(x-t);
        }
    }
    cout << min_val;
}