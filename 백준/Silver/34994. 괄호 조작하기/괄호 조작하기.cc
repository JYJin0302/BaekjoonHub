#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

bool simul(string s){
    
    int n = (int)s.size();

    vector<pair<char, int>> A;
    for(int i = 0; i < n;i++){
        char c = s[i];
        if (A.empty() || c == '(' || c== '[' || c == '{') A.push_back(mp(c, i));
        else if (c == ')' && A.back().x == '(') A.pop_back();
        else if (c == ']' && A.back().x == '[') A.pop_back();
        else if (c == '}' && A.back().x == '{') A.pop_back();
        else A.push_back(mp(c, i));
    }

    bool res = A.empty();
    A.clear();
    vector<pair<char, int>>().swap(A);
    return res;
}



void solve(){

    string s;
    cin >> s;

    if (simul(s)){
        cout << "YES 0\n";
        return;
    }

    int n = (int)s.size();
    string tar = "({[]})";

    for(int i = 0; i < n; i++){
        char c = s[i];
        for(int j = 0 ;j < 6; j++){
            if (tar[j] == c) continue;

            s[i] = tar[j];

            if (simul(s)){
                cout << "YES 1\n";
                cout << i+1 << ' ' << tar[j] << '\n';
                return;
            }
        }
        s[i] = c;
    }
    cout << "NO\n";
}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}