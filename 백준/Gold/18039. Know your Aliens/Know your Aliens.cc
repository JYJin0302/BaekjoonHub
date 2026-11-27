#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >>s;

    vector<int> idx;

    int n = s.size();
    for(int i = 1; i < n; i++){
        if(s[i] != s[i-1]){
            idx.push_back(i*2+1);
        }
    }

    int m = idx.size();

    if (m == 0){
        cout <<"0\n";

        if (s[0] == 'H') cout <<1;
        else cout << -1;

        return 0;
    }

    vector<vector<ll>> tmp(m);
    for(int i = 0; i < m;i++){
            tmp[i].push_back(1);
            tmp[i].push_back(-idx[i]);
    }

    vector<ll> curr = tmp[0], tmp2;
    for(int i = 1; i < m; i++){
        vector<ll>& B = tmp[i];

        int an = curr.size(), bn = B.size();

        int newN = an + bn - 1;
        tmp2 = vector<ll>(newN);
        for(int j = 0; j < bn; j++){
            for(int k = 0; k <an; k++){
                tmp2[j+k] += curr[k]*B[j];
            }
        }
        swap(tmp2, curr);
    }

    bool ok = 0;
    if (s[0] == 'A' && m %2 == 0) ok= 1;
    if (s[0] == 'H' && m%2 == 1) ok = 1;

    if(ok){
        for(auto& i :curr) i *= -1;
    }

    cout <<m <<'\n';
    for(auto i :curr)cout <<i <<' ';

}