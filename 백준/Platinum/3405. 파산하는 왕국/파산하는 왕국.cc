
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int A[25][25];

void solve(){

    int n;
    cin >>n;

    vector<bool> dp(1 << n);
    vector<int> tot(n);
    for(int i = 0; i <n;i++){
        for(int j = 0; j < n; j++){
            cin >>A[i][j];
            tot[i] += A[i][j];
        }
    }

    dp[0] = 1;
    queue<int>q;
    for(int i = 0; i < n; i++){
        if (tot[i] >0){
            dp[1 <<i] = 1;
            q.push(1 <<i);
        }
    }

    while(!q.empty()){

        int a = q.front();
        q.pop();

        vector<int> cost(n);
        for(int i = 0; i <n; i++){
            if (a &(1 << i))continue;
            for(int j = 0; j <n; j++){
                if(a &(1 << j))continue;
                cost[i] += A[i][j];
            }
        }

        for(int i = 0; i <n; i++){
            if (a &(1 << i))continue;

            if (cost[i] > 0){
                int na = a | (1 << i);
                if (!dp[na]){
                    dp[na] = 1;
                    q.push(na);
                }
            }
        }
    }

    vector<int>ans;
    for(int i = 0; i <n; i++){
        int ta = (1 << n) - 1;
        ta ^= (1 << i);
        if (dp[ta]) ans.push_back(i+1);
    }

    if(ans.empty()) cout << 0;
    else for(auto i : ans)cout <<i <<' ';
    cout <<'\n';

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >>t;
    while(t--){
        solve();
    }

}

