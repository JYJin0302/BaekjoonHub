#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[100001];

void init(){
    
    for(int i = 1; i < n; i++){
        vector<int> p;
        for (int j = 1; j *j <= i; j++){
            if(i %j == 0) {
                p.push_back(j);
                if (j != i/j) p.push_back(i/j);
            }
        }
        p.push_back(i);
        
        for(int k : p){
            if (k + i <= n) adj[k+i].push_back(i);
        }
    }
    
}

int main(){
    
    cin >> n;
    init();
    
    vector<bool> A(n+1);
    A[n] = 0;
    
    for(int i = n; i >= 1; i--){
        bool b = A[i];
        if (!b) for (auto k : adj[i]) A[k] = 1;
    }
    
    if (A[1]) cout << "Kali";
    else cout << "Ringo";
}