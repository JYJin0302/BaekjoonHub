#include <bits/stdc++.h>
using namespace std;

void solve(){

    string s;
    getline(cin, s);

    vector<string>lst;
    string tmp = "";
    for(int i = 0; i <s.size(); i++){
        if (s[i] == ' '){
            lst.push_back(tmp);
            tmp = "";
        }
        else tmp += s[i];
    }
    lst.push_back(tmp);

    map<string, bool> ck;

    string w;
    while(cin >>w){
        if (w!= "what"){
            cin >>w >>w;
            ck[w] = 1;
        }
        else{
            cin >> w >> w >>w >> w;
            break;
        }
    }
    cin.ignore();
    for(auto i :lst) if(!ck[i]) cout <<i <<' ';
    cout <<'\n';



}

int main(){
    int t; cin>>t;
    cin.ignore();
    while(t--){

        solve();
    }
}
