#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n, a, b, c, d;
        cin >> n;
        
        vector<bool> check(n+2);
        vector<pair<int, int>> place;
        for (int i = 0; i < n+2; i++){
            cin >> a>> b;
            place.push_back({a, b});
        }
        
        queue<pair<int ,int>> q;
        q.push(place[0]);
        check[0] = 1;
        while(!q.empty()){
            tie(a, b) = q.front();
            q.pop();
            for (int i = 0; i < n+2; i++){
                if(check[i]) continue;
                tie(c, d) = place[i];
                if (abs(c-a)+abs(d-b) <= 1000) {
                    check[i] = 1;
                    q.push({c, d});
                }
            }
        }
        
        if (check[n+1]) cout << "happy\n";
        else cout << "sad\n";
        
    }    
}