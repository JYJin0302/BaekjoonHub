#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int p = 0;

string S[] = {"A", "B"};

vector<string> ans;

void fin(ll a, ll b){
    while(b != 1){
        if (b % 2 == 1) {
            b++;
            ans.push_back(S[1-p] + "+=" + S[p]);
        }
        while(b % 2 == 0){
            ans.push_back(S[p] + "+=" + S[p]);
            b /= 2;
        }
    }
}

void solve(ll a, ll b){
    if (a == b) return;
    
    while(a % 2 == 0) {
        ans.push_back(S[1-p] + "+=" + S[1-p]);
        a /= 2;
    }
    while(b % 2 == 0) {
        ans.push_back(S[p] + "+=" + S[p]);
        b /= 2;
    }
    
    if (a > b) {
        p = 1 - p;
        swap(a, b);
    }
    
    // p : A, 1-p : B
    if (b % a == 0) {
        fin(1, b / a);
        return;
    }
    
    ans.push_back(S[1-p] + "+=" + S[p]);
    solve(a, a+b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a, b;
    cin >> a >> b;
    
    solve(a, b);
    
    cout << ans.size() << '\n';
    for(auto i : ans) cout << i << '\n';
}