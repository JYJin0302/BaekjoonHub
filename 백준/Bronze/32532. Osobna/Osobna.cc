#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){
 
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    string PIN;
    for(int i = 0; i < 11;i ++){
        PIN += s1[i + 15];
    }

    string Y, M, D;
    Y = s2.substr(0, 2);
    M = s2.substr(2, 2);
    D = s2.substr(4, 2);

    if(Y[0]< '2' || (Y[0] == '2' && Y[1] < '5')) {
        Y = "20" + Y;
    }
    else Y= "19" + Y;

    string FN, LN;
    int ix = 0;
    int len = (int)s3.size();
    while(s3[ix] != '<'){
        FN += s3[ix];
        ix++;
    }
    ix += 2;
    while(ix < len && s3[ix] != '<') LN += s3[ix++];

    for(int i = 1; i < (int)FN.size(); i++){
        if ('A' <= FN[i]  && FN[i] <= 'Z'){
            FN[i] = FN[i] + 'a' - 'A';
        }
    }    
    for(int i = 1; i < (int)LN.size(); i++){
        if ('A' <= LN[i]  && LN[i] <= 'Z'){
            LN[i] = LN[i] + 'a' - 'A';
        }
    }
    if ('a' <= FN[0]  && FN[0] <= 'z'){
        FN[0] = FN[0] + 'A' - 'a';
    }
    if ('a' <= LN[0]  && LN[0] <= 'z'){
        LN[0] = LN[0] + 'A' - 'a';
    }

    cout << "Ime: " << FN << '\n';
    cout << "Prezime: " << LN << '\n';
    cout << "Datum rodjenja: " << D << '-' << M <<'-'<< Y << '\n';
    cout << "OIB: " << PIN << '\n';
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    int t = 1;
   // cin >> t;
    for(int i =0 ;i < t;i ++){
        solve();
    }


    return 0;
}