#include <bits/stdc++.h>
using namespace std;

int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);    
    int n;
    int ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        
        stack<char> st;
        for (char i : s){
            if (st.empty() || st.top() != i) st.push(i);
            else st.pop();
        }
        
        if (st.empty()) ans++;
    }
    
    cout << ans;
}