#include <bits/stdc++.h>
using namespace std;
int L[1000001], R[1000001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    for (int i = 1; i < n; i++){
        int l = A[i-1], r = A[i];
        L[r] = l;
        R[l] = r;
    }
    L[A[0]] = A[n-1];
    R[A[n-1]] = A[0];
    
    while(m--){
        
        string s;
        int a, b;
        cin >> s >> a;
        
        if (s == "BN"){
            cin >> b;
            int nx = R[a];
            cout << nx << '\n';
            
            R[a] = b;
            L[b] = a;
            R[b] = nx;
            L[nx] = b;
        }
        else if (s == "BP"){
            cin >> b;
            int nx = L[a];
            cout << nx << '\n';
            
            R[nx] = b;
            L[b] = nx;
            R[b] = a;
            L[a] = b;
        }
        else if (s == "CN"){
            int nx = R[a];
            cout << nx << '\n';
            
            nx = R[nx];
            R[a] = nx;
            L[nx] = a;
        }
        else{
            int nx = L[a];
            cout << nx << '\n';
            
            nx = L[nx];
            R[nx] = a;
            L[a] = nx;
        }
    }
    
    
}