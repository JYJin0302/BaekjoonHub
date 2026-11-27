#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t;
    cin >> n;
    
    priority_queue<int> pq;
    
    while(n--){
        cin >> t;
        if (t == 0){
            if (pq.empty()) cout << 0 << '\n';
            else{
                cout<< pq.top() << '\n';
                pq.pop();
            }
        }
        else pq.push(t);
    }
}