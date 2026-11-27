#include <bits/stdc++.h>
using namespace std;
using ll = long long;


vector<int> ans;
vector<int> adj[1001010];
int ndx[1001010];
ll n, m, k, N, M;

stack<int>st;
void dfs(int v){
    //cout <<"Go: " <<v <<'\n';
    if (ndx[v] == m) return;

    while(ndx[v] < m){
        int nv = v % M;
        nv = nv * m + ndx[v];
        st.push(ndx[v]);
        ndx[v]++;
        dfs(nv);

        ans.push_back(st.top());
        st.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >>n >>m >>k;
    vector<int>num(m);
    for(auto&i :num) cin>>i;

    if (n == 1){
            for(int i = 0; i <k; i++){
                cout <<num[i];
            }
            return 0;
    }

    if (m == 1){
        for(int i = 0; i < n; i++) cout << num[0];
        return 0;
    }

    if (k <= m){
        for(int i = 0; i < n-1; i++)cout <<num[0];
        for(int i = 0; i < k; i++) cout <<num[i];
        return 0;
    }

    N = 1;
    M = m;

   while(M < k){
        M *= m;
        N++;
        //cout <<M <<' ' <<N <<'\n';
    }
    N = min(N, n);
    M = pow(m, N-2);

    //cout << N <<' ' <<M <<'\n';

    dfs(0);

    reverse(ans.begin(), ans.end());

    for(int i = 0; i <n-1; i++) cout << num[ans[0]];
    for(int i = 0; i < k; i++){
        cout << num[ans[i]];
    }


    return 0;
}
