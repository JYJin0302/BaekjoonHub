#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a;
    cin >> n;
    
    priority_queue<int> pq;
    while(n--) {
        cin >> a;
        if (a == 0){
            if (pq.empty()) cout << "0\n";
            else {
                cout << -pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            pq.push(-a);
        }
    }
    
}