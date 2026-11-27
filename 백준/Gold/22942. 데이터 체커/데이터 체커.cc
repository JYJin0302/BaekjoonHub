#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    map<int, int> cnt;
    bool ok = 1;
    
    vector<pair<int, int>> A;
    for(int i = 0; i < n; i++){
        int x, r;
        cin >> x >> r;
        A.push_back({x-r, i});
        A.push_back({x+r, i});
        if (cnt[x-r] || cnt[x+r]) ok = 0;
        cnt[x-r]++, cnt[x+r]++;
    }
    
    sort(A.begin(), A.end());
    
    vector<bool> u(n);
    stack<int> st;
    
    for(auto i : A){
        int a, b;
        tie(a, b) = i;
        
        if (!u[b]) {
            st.push(b);
            u[b] = 1;
        }
        else{
            if (st.top() != b) ok = 0;
            else st.pop();
        }
    }
    
    if (ok) cout << "YES";
    else cout << "NO";
}