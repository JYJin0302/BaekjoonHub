#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int b, n;
char ans[40];

int toInt(char c){
    if (c >= '0' && c <= '9') return c - '0';
    return c - 'A' + 10;
}
char toChar(int x){
    if (x < 10) return char('0' + x);
    return char('A' + x - 10);
}

char oper(char n1, char n2, char op){
    int num1 = toInt(n1);
    int num2 = toInt(n2);
    if (op == '*'){
        int res = num1 * num2 % b;
        return toChar(res);
    }
    else if (op == '+'){
        int res = (num1 + num2) % b;
        return toChar(res);

    }
    else if (op == '-'){
        int res = (num1 - num2 + b) % b;
        return toChar(res);
    }
    else{
        cout << "??";
        return '?';
    }
}

char goSolve(string s, int x){
    int ix = 0;

    stack<char> stk;
    while(ix < (int)s.size()){
        int nx = ix;
        while(nx < (int)s.size() && s[nx] != ' ') nx++;

        char c = s[nx-1];

        if (c == '*' || c == '+' || c == '-'){
            char n2 = stk.top(); stk.pop();
            char n1 = stk.top(); stk.pop();

            char res = oper(n1, n2, c);
            stk.push(res);
        }
        else {
            if (c == 'x') c = toChar(x);
            stk.push(c);
        }

        ix = nx + 1;

    }
    return stk.top();
}


void solve(){
    
    cin >> b>> n;
    cin.ignore();
    string s;
    getline(cin, s);
    
    for(int i =0 ; i< b; i ++){
        ans[i] = goSolve(s, i);
    }

    for(int i =0 ;i < n; i++){
        string s;
        cin >> s;

        int ix = toInt(s.back());

        cout << ans[ix] << '\n';
    }


}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}