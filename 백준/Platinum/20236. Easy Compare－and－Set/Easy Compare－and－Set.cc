#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>>adj[202020];

vector<int>num;
int getIdx(int n){
    return lower_bound(num.begin(), num.end(), n)- num.begin();
}

int adx[202020];
vector<int>ans;

void dfs(int v){

    while(adx[v] < adj[v].size()){
        int a, b;
        tie(a, b)= adj[v][adx[v]++];

        dfs(a);
        ans.push_back(b);
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >>n >>k;

    vector<tuple<int, int, int>>inp;

    for(int i = 0; i <n; i++){
        int a, b, c;
        cin >>a >>b >>c;

        num.push_back(a);
        if (c == 1) num.push_back(b);
        inp.push_back({a, b, c});
    }
    num.push_back(k);

    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());

    vector<int> tmp1, tmp2;



    for(int i= 0; i < n; i++){
        int a, b, c;
        tie(a, b, c) = inp[i];


        if(c == 0){
            if(a == k) tmp2.push_back(i);
            else tmp1.push_back(i);
        }
        else{
            a = getIdx(a);
            b = getIdx(b);
            adj[a].push_back({b, i});
            //cout <<"EDGE:"<<a <<' ' << b <<' ' <<i <<'\n';
        }
    }

    dfs(getIdx(k));

    reverse(ans.begin(), ans.end());
    //for(auto i :ans)cout <<i <<' ';

    bool ok = 1;
    if (ans.size() + tmp1.size() + tmp2.size() != n) ok = 0;

    for(int i = 1; i <ans.size(); i++){
        int a = get<1>(inp[ans[i-1]]);
        int b =get<0>(inp[ans[i]]);

        if (a != b) ok = 0;
    }

    if(ans.empty() && !tmp2.empty()) ok = 0;

    if(!ok){
        cout <<"No\n";
        return 0;
    }

    vector<int> res;
    for(int i : tmp1) res.push_back(i+1);
    for(int i = 0; i < ans.size();i++){
        res.push_back(ans[i]+1);
        int a, b, c;
        tie(a, b, c) = inp[ans[i]];

        if(a != b && !tmp2.empty()){
            for(auto j :tmp2)res.push_back(j+1);
            tmp2.clear();
        }
    }

    if (!tmp2.empty()) {
        cout << "No\n";
        return 0;
    }

    cout <<"Yes\n";
    for(auto i : res)cout <<i <<' ';

}
