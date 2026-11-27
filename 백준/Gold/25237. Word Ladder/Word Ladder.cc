#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) x.begin(), x.end()

vector<int> seq;

void solve(){
    
    int n;
    cin >> n;

    seq.push_back(1);

    for(int i = 2; i <= 10; i++){
        vector<int> tmp;
        for(auto f : seq) tmp.push_back(f);
        tmp.push_back(i);
        reverse(all(seq));
        for(auto f : seq) tmp.push_back(f);
        seq = tmp;
    }
    seq.push_back(10);

    string tmp(10, 'a');

    for(int i = 0; i < n; i++){
        cout << tmp << '\n';

        int dif = seq[i % (int)seq.size()];

        int ix = dif - 1;
        if (tmp[ix] == 'z') tmp[ix] = 'a';
        else tmp[ix]++;
    }

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
