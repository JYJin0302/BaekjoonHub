#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin, s);
    while(s != "."){
        bool ok = true;
        stack<char> base;
        for (char i : s){
            if (i == '(' || i == '[') base.push(i);
            else if (i == ')'){
                if (base.empty() || base.top() != '(') {ok = false;break;}
                base.pop();
            }
            else if (i == ']'){
                if (base.empty() || base.top() != '[') {ok = false;break;}
                base.pop();
            }
        }
        if (!base.empty()) ok = false;
        
        cout << (ok ? "yes\n" : "no\n");
        getline(cin, s);
    }
}