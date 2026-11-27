#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
        
    int n, l;
    cin >> n >> l;
    
    deque<pair<int, int>> dq;
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        
        while(!dq.empty() && (dq.front().x > num || i - dq.front().y >= l)) dq.pop_front();
        while(!dq.empty() && (dq.back().x > num || i - dq.back().y >= l)) dq.pop_back();
        dq.push_back({num, i});
        
        cout << dq.front().x << ' ';
    }
    
}