#include <bits/stdc++.h>
using namespace std;

int main(){
    
    string s;
    cin >> s;
    
    deque<char> dq;
    for(char c : s){
        if (dq.empty()) dq.push_front(c);
        else{
            if (dq.front() < c) dq.push_back(c);
            else dq.push_front(c);
        }
    }
    
    while(!dq.empty()){
        cout << dq.front();
        dq.pop_front();
    }
}
