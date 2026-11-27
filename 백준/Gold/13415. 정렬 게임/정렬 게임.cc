#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    vector<int> inp;
    int k;
    cin >> k;
    while(k--){
        int a, b;
        cin >> a >> b;
        inp.push_back(a);
        inp.push_back(-b);
    }
    
    reverse(inp.begin(), inp.end());
    
    int pv = 0;
    vector<int> res;
    for (int i : inp){
        if (abs(i) > abs(pv)){
            res.push_back(pv);
            pv = i;
        }
    }
    res.push_back(pv);
    
    reverse(res.begin(), res.end());
    
    sort(A.begin(), A.begin() + abs(res[0]));
    
    vector<int> ans = A;
    deque<int> q;
    for (int i = 0; i < abs(res[0]); i++){
        q.push_back(A[i]);
    }
    
    for (int i = 0; i < res.size()-1; i++){
        
        int c = abs(res[i]);
        int nxt = abs(res[i+1]);
        
        
        if (res[i] > 0){
            for (int j = c-1; j >= nxt; j--){
                ans[j] = q.back();
                q.pop_back();
            }
        }
        else{
            for (int j = c-1; j >= nxt; j--){
                ans[j] = q.front();
                q.pop_front();
            }
        }
    }
    
    for(int i : ans) cout << i << ' ';
}