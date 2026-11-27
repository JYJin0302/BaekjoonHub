#include <bits/stdc++.h>
#define ll long long
using namespace std;

int root[200010];
int find(int n){
    if (root[n] == n)return n;
    return root[n] = find(root[n]);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >>n;

    map<int, int> conn;
    for(int i =1 ; i <= n; i++){
        root[i] = i;
    }

    vector<tuple<int ,int, int>>ans;
    for(int i= 1; i <= n; i++){
        int m;
        cin >>m;
        while(m--){

            int s;
            cin >>s;

            if (conn[s] != 0){
                int tar = find(conn[s]);
                int ts = find(i);
                if (ts != tar){
                    root[ts] = tar;
                    ans.push_back({i, conn[s], s});
                }
            }
            conn[s] = i;
        }
    }

    if (ans.size() != n-1){
        cout <<"impossible";
        return 0;
    }

    for(auto i :ans){

        int a, b, c;
        tie(a, b, c) = i;
        cout <<a<<' '  <<b <<' ' <<c <<'\n';

    }

}
