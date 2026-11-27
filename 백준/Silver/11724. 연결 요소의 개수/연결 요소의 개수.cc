#include <bits/stdc++.h>
using namespace std;

int n ,m, n1, n2, cnt;
vector<vector<int>> base;
vector<bool> check;
void dfs(int v){
    check[v] = true;
    for (int i : base[v]){
        if(check[i]) continue;
        dfs(i);
    }
}


int main(){
    cin >> n >> m;
    base = vector<vector<int>>(n + 1);
    check = vector<bool> (n + 1);
    check[0] = 1;
    while(m--){
        cin >> n1 >> n2;
        base[n1].push_back(n2);
        base[n2].push_back(n1);
    }
    for (int i = 1; i <= n; i++){
        if (check[i] == 0){
            dfs(i);
            cnt++;
        }
    }
    cout << cnt;
}