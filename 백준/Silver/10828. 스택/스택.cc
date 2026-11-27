#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, temp;
    string s;
    cin >>n;
    stack<int> base;
    while(n--){
        cin >> s;
        if (s == "push") {cin >> temp; base.push(temp);}
        else if (s == "top") {if(base.empty()) cout << -1 << endl; else cout << base.top() << endl;}
        else if (s == "size") cout << base.size() << endl;
        else if (s == "empty") cout << (base.empty() ? 1 : 0) << endl;
        else if (s == "pop") {if(base.empty()) cout << -1 << endl; else {cout << base.top() << endl; base.pop();}}
    }
    
    
}