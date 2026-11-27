#include <bits/stdc++.h>
using namespace std;

int main(){
    string s1, s2;
    cin >> s1  >>  s2;
    
    stack<char> st;
    for (char i : s1){
        st.push(i);
        if (st.size() < s2.size()) continue;
        
        string t;
        
        for(int k = 0; k < s2.size(); k++){
            t += st.top();
            st.pop();
        }
        
        reverse(t.begin(), t.end());
        if (t != s2){
            
            for(char k : t){
                st.push(k);
            }
        }
    }
    
    string ans;
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    
    reverse(ans.begin(), ans.end());
    
    cout << ans;
    
}