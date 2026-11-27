#include <bits/stdc++.h>
using namespace std;

vector<int> adj[51];
int match[51], co[51];

bool isPrime[2001];

void init(){
    
    memset(isPrime, true, sizeof(isPrime));
    for (int i = 2; i <= 2000; i++){
        if (!isPrime[i]) continue;
        for (int j = i*2; j <= 2000; j+= i) isPrime[j] = 0;
    }
    
}

bool dfs(int l){
    if (co[l]) return 0;
    co[l] = 1;
    
    for (auto i : adj[l]){
        if (match[i] == -1 || dfs(match[i])){
            match[i] = l;
            return 1;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    init();
    
    int n;
    cin >> n;
    
    vector<int> A(n);
    map<int, int> ntoi;
    
    vector<int> L, R; // 인덱스 저장
    for(int i = 0; i < n; i++){
        
        int x;
        cin >> x;
        
        ntoi[x] = i;
        A[i] = x;
        
        if (x % 2 != 0) L.push_back(x);
        else R.push_back(x);
        
    }
    
    if (L.size() != R.size()) {
        cout << -1;
        return 0;
    }
    
    if (A[0] % 2 == 0) swap(L, R);
    
    for(int i = 0; i < n/2; i++){
        for (int j = 0; j < n/2; j++){
            if (isPrime[L[i]+R[j]]) adj[i].push_back(j);
        }
    }
    
    vector<int> ans;
    
    for (auto j : adj[0]){
        memset(match, -1, sizeof(match));
        match[j] = 0;
        int cnt = 1;
        for(int i = 1; i < n/2; i++){
            memset(co, 0, sizeof(co));
            co[0] = 1;
            cnt += dfs(i);
        }
        
        if  (cnt == n/2) ans.push_back(R[j]);
    }
    
    if (ans.size() == 0) cout << -1;
    else{
        sort(ans.begin(), ans.end());
        for (auto i : ans) cout << i<< ' ';
    }
}