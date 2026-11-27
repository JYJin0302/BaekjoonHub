#include <bits/stdc++.h>
using namespace std;

struct P{
    string name;
    long double v1,v2;
    bool operator<(P& other){
        return v2 < other.v2;
    }

};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >>n;

    vector<P> A(n);
    for(auto&i : A){
        cin >> i.name >>i.v1 >>i.v2;
    }


    long double ans = 100000;
    vector<string> ansList;

    for(int i = 0; i< n; i++){


        vector<P> tmp;
        for(int j = 0; j < n; j++){
            if (i == j) continue;
            tmp.push_back(A[j]);
        }
        sort(tmp.begin(), tmp.end());

        long double tans = A[i].v1;
        tans += tmp[0].v2 + tmp[1].v2 + tmp[2].v2;

        if (tans < ans){
            ans = tans;
            ansList = {A[i].name, tmp[0].name, tmp[1].name, tmp[2].name};
        }

    }

    cout <<ans<<'\n';
    for(auto i :ansList) cout << i <<'\n';

}
