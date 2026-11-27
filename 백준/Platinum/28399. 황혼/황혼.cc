#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
using ll = long long;

vector<pair<ll, ll>> adj[200010];
int prevInf[200010];
bool isStart[200010];
bool isEnd[200010];

ll dp[200010][2];

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n >>m >>k;

    for(int i = 1; i <= n; i++){
        dp[i][0] = 1e16;
        dp[i][1] = 1e16;
    }

    while(m--){

        int a, b, c;
        cin >>a>>b>>c;
        adj[a].push_back({b, c});
    }

    while(k--){

        int x;
        cin >>x;
        vector<int> tmp(x);
        for(auto&i : tmp)cin >>i;

        isStart[tmp[0]] = 1;
        for(int i = 1; i <x; i++){
            prevInf[tmp[i]] = tmp[i-1];
        }
        isEnd[tmp[x-1]] = 1;
    }


    priority_queue<tuple<ll, ll, ll>> pq;

    if (!isStart[1]) {
            pq.push({0, 1, 0});
    }
    else {
            pq.push({0, 1, 1});
    }

    while(!pq.empty()){

        ll a, b, c;
        tie(a, b,c)= pq.top();
        pq.pop();

        if (dp[b][c] != 1e16) continue;
        dp[b][c] = -a;

        //cout << "CURR:"<< a <<' ' <<b <<' ' <<c <<'\n';

        for(auto i :adj[b]){
            ll x, y;
            tie(x, y)= i;
            if(c == 1){
                    //cout <<x <<' ' << b << ' ' <<prevInf[x] <<'\n';
                if(prevInf[x] == b){
                    if (!isEnd[x] && dp[x][1] == 1e16) {
                        pq.push({a-y, x, 1});
                        //cout <<"ADD:"<< x <<' ' <<1 <<'\n';
                    }
                }
                else{
                    if(isStart[x] && dp[x][1] == 1e16){
                        pq.push({a-y, x, 1});
                        //cout <<"Add:"<<x <<' ' <<1 <<'\n';
                    }
                    else if (!isStart[x] && dp[x][0] == 1e16){
                        pq.push({a-y, x, 0});
                        //cout <<"add:"<< x <<' ' <<0 <<'\n';
                    }
                }
            }
            else{
                if(isStart[x] && dp[x][1] == 1e16){
                    pq.push({a-y, x, 1});
                    //cout <<"ADD:"<<x <<' ' <<1 <<'\n';
                }
                else if (!isStart[x] && dp[x][0] == 1e16){
                    pq.push({a-y, x, 0});
                    //cout <<"ADD:"<<x <<' ' <<0 <<'\n';
                }

            }

        }

    }

    for(int i = 1;i <= n; i++){
            ll val = min(dp[i][0], dp[i][1]);
    if (val == 1e16) val = -1;
        cout << val <<' ';
    }
}
