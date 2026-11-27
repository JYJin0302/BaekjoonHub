#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >>n >>k;
    cin.ignore();
    vector<string>A(n*3);
    for(int i = 0; i<3*n; i++){
        getline(cin, A[i]);
    }

    map<string, int> cnt;
    map<string, int> idx;
    for(int i = 0; i < n*3; i++){
        cnt[A[i]]++;
        idx[A[i]] = i;
    }

    vector<tuple<int, int, string>> B;
    for(auto i : cnt){
        string ts = i.first;
        B.push_back({-cnt[ts], -idx[ts], ts});
    }
    sort(B.begin(), B.end());

    for(int i = 0; i <min((int)B.size(), k); i++){
        cout << get<2>(B[i]) <<'\n';
    }

}
