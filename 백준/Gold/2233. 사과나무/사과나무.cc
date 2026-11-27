#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    vector<int> L(n, -1), R(n, -1);
    vector<int> In(n), Out(n), p(n), d(n);
    vector<int> num(n*2);
    stack<int> st;
    
    int x = 0;
    st.push(x);
    for(int i = 1; i < n*2; i++){
        int tx = st.top();
        if (s[i] == '0'){
            
            x++;
            if (L[tx] != -1){
                R[tx] = x;
            }
            else L[tx] = x;
            In[x] = i;
            st.push(x);
            num[i] = x;
            p[x] = tx;
            d[x] = d[tx] + 1;
        }
        else {
            st.pop();
            Out[tx] = i;
            num[i] = tx;
        }
    }
        
    
    int a, b;
    cin >> a >> b;
    a-- ,b--;
    a = num[a], b = num[b];
    if (d[a] > d[b]) swap(a, b);
    while(d[b] > d[a]){
        b = p[b];
    }
    while(a != b){
        a = p[a], b = p[b];
    }
    
    cout << In[a]+1 << ' ' << Out[a]+1;
}