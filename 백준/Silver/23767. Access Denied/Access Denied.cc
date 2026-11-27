#include <bits/stdc++.h>
using namespace std;

int getInp(){

    string s;
    cin >> s>>s;
    if (s == "GRANTED"){
        return -1;
    }
    cin >>s;

    string tmp = s.substr(1, 30);
    cin >> s;

    return stoi(tmp);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    int sz = 0;

    for(int i = 1; i<= 20; i++){
        string tmp(i, 'a');
        cout << tmp << endl;
        cout.flush();
        int res = getInp();

        if (res == -1) return 0;

        if(res > 5){
            sz = i;
            break;
        }
    }

    vector<char> lst;
    for(int i = 0; i < 26; i++){
        lst.push_back('a' + i);
        lst.push_back('A' + i);
    }
    for(int i = 0; i < 10; i++){
        lst.push_back('0'+i);
    }

    int m = lst.size();

    s = string(sz, 'a');
    for(int i = 0; i < sz; i++){

        string tans = s;
        int tval = 0;

        for(auto k: lst){
            s[i] = k;
            cout << s << endl;
            cout.flush();
            int res = getInp();

            if (res == -1) return 0;

            if (tval <= res){
                tval = res;
                tans = s;
            }
        }
        
        s = tans;
    }

    return 0;
}
