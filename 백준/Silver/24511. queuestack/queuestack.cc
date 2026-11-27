#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> A(n), B(n);
    for(auto& i : A) cin >> i;
    for(auto& i : B) cin >> i;
    
    queue<int> q;
    for(int i = n-1; i>= 0; i--){
        if (!A[i]) q.push(B[i]);
    }
    
    int m;
    cin >> m;
    while(m--){
        int a;
        cin >> a;
        q.push(a);
        cout << q.front() << ' ';
        q.pop();
    }
}