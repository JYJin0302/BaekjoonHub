#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int main(){
    
    int n;
    cin >> n;
    
    stack<pair<int, int>> st; // val, pos
    st.push({0, -1});
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        
        int ti = i;
        while(!st.empty()){
            
            int a, b;
            tie(a, b) = st.top();
            
            if (a > m) {
                ans = max(ans, (i - b) * a);
                ti = b;
                st.pop();
            }
            else{
                st.push({m, ti});
                break;
            }
        }
    }
    
    while(!st.empty()){
        int a, b;
        tie(a, b) = st.top();
        st.pop();
        
        ans = max(ans, (n - b) * a);
    }
    
    cout << ans;
    
}