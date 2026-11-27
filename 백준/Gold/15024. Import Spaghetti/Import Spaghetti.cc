#include <bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define ll long long

map<string, int> sdx;

vector<int>adj[505], rev[505];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<string>A(n);
    for(int i= 0; i < n;i++){
        cin >> A[i];
        sdx[A[i]] = i;
    }

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;

        int x;
        cin >>x;

        while(x--){
            cin >> s;
            cin>> s;

            while(1){
                if (s.back() != ','){
                    int curr = sdx[s];
                    adj[curr].push_back(i);
                    rev[i].push_back(curr);
                    break;
                }
                else{
                    string tmp = s.substr(0, s.size()-1);
                    int curr = sdx[tmp];
                    adj[curr].push_back(i);
                    rev[i].push_back(curr);
                    cin >> s;
                }
            }
        }
    }

    for(int i = 0; i < n;i++){
        for(auto j : adj[i]){
            if (i == j) {
                cout << A[i];
                return 0;
            }
        }
    }
    int ansDist = n+10, ans1 = -1, ans2 = -1;

    for(int i = 0; i < n; i++){
        vector<int>dist(n,-1);
        dist[i] = 0;

        int mdist = n+10, mi = i;

        queue<int>q;
        q.push(i);
        while(!q.empty()){
            int a = q.front();
            q.pop();

            for(auto j :adj[a]){
                if(j == i){
                    if (dist[a] + 1 < mdist){
                        mdist = dist[a]+1;
                        mi = a;
                    }
                }
                else if (dist[j] == -1){
                    dist[j] = dist[a] +1;
                    q.push(j);
                }
            }
        }

        if (mdist <ansDist){
            ansDist = mdist;
            ans1 = i, ans2 = mi;
        }
    }

    if (ansDist == n+10){
        cout <<"SHIP IT";
        return 0;
    }

    vector<int>dist(n,-1);
    dist[ans1] = 0;

    int mdist = n+10;

    queue<int>q;
    q.push(ans1);
    while(!q.empty()){
        int a = q.front();
        q.pop();

        for(auto j :adj[a]){
            if (dist[j] == -1){
                dist[j] = dist[a] +1;
                q.push(j);
            }
        }
    }

    int curr = ans2;
    vector<int>res = {ans2};
    while(curr != ans1){
        for(auto i: rev[curr]){
            if (dist[i] +1 == dist[curr]){
                res.push_back(i);
                curr = i;
                break;
            }
        }

    }

    for(auto i : res) cout << A[i]<< ' ';

}
