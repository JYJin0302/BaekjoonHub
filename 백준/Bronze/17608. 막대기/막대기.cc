#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    stack<int> st;
    for(int i = 0; i < n;i++){
        int x;
        cin >> x;
        
        while(!st.empty() && st.top() <= x) st.pop();
        st.push(x);
    }
    cout << st.size();
}