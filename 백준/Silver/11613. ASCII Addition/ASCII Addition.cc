
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> tmp = {"xxxxxx...xx...xx...xx...xx...xxxxxx"};

vector<string> A;
int check(int ix){
    // 0


    string curr;
    for(int i  =0; i <7; i++){
        curr += A[i].substr(ix, 5);
    }

    for(int i = 0; i <= 9; i++) if(tmp[i] == curr) return i;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    tmp.push_back("....x....x....x....x....x....x....x");
    tmp.push_back("xxxxx....x....xxxxxxx....x....xxxxx");
    tmp.push_back("xxxxx....x....xxxxxx....x....xxxxxx");
    tmp.push_back("x...xx...xx...xxxxxx....x....x....x");
    tmp.push_back("xxxxxx....x....xxxxx....x....xxxxxx");
    tmp.push_back("xxxxxx....x....xxxxxx...xx...xxxxxx");
    tmp.push_back("xxxxx....x....x....x....x....x....x");
    tmp.push_back("xxxxxx...xx...xxxxxxx...xx...xxxxxx");
    tmp.push_back("xxxxxx...xx...xxxxxx....x....xxxxxx");

    for(int i = 0; i <7; i++){
        string s;
        cin >>s;
        A.push_back(s);
    }


    int n = A[0].size();

    ll num1 = 0, num2 = 0;
    bool nx = 0;
    for(int i = 0; i <n; i += 6){

        if(A[1][i+2] == 'x'){
            // +
            nx = 1;
        }
        else{
            int val = check(i);

            if (nx) num2 = num2*10 + val;
            else num1 = num1 *10 + val;

        }

    }
    ll res = num1 +num2;
    vector<int> num;
    while(res != 0){
        num.push_back(res % 10);
        res /= 10;
    }
    reverse(num.begin(), num.end());

    vector<string>ans(7);
    for(auto i :num){
        for(int j = 0; j < tmp[i].size(); j += 5){
            ans[j/5] += tmp[i].substr(j, 5);
            ans[j/5] += '.';
        }

    }

    for(auto i : ans){
        for(int j = 0; j <i.size()-1; j++) cout <<i[j];
        cout <<'\n';
    }


}
