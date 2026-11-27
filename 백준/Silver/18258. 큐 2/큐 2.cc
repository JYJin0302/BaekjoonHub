#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t;
    cin >> n;
    
    queue<int> base;
    while(n--){
        string s;
        cin >> s;
        if (s == "push") {
            cin >> t;
            base.push(t);
        }
        else if (s == "pop"){
            if (base.empty()) cout << -1 << '\n';
            else{
                cout << base.front() << '\n';
                base.pop();
            }
        }
        else if (s == "size") cout << base.size() << '\n';
        else if (s == "front") {
            if (base.empty()) cout << -1 << '\n';
            else cout << base.front() << '\n';
        }
        else if (s == "back"){
            if (base.empty()) cout << -1 << '\n';
            else cout << base.back() << '\n';
        }
        else if (s == "empty") cout << base.empty() << '\n';
    }
}