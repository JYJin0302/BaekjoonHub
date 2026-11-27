#include <bits/stdc++.h>
#define ll long long
using namespace std;

char c1[] = { 'h', 'b', 'c', 'n', 'o', 'f', 'p', 's', 'k', 'v', 'y', 'i', 'w', 'u' };

string c2[] = {
	"ba", "ca" , "ga", "la", "na", "pa", "ra", "ta", "db", "nb", "pb", "rb", "sb", "tb", "yb", "ac",
	"sc", "tc", "cd", "gd", "md", "nd", "pd", "be", "ce", "fe", "ge", "he", "ne", "re", "se", "te",
	"xe", "cf", "hf", "rf", "ag", "hg", "mg", "rg", "sg", "bh", "rh", "th", "bi", "li", "ni", "si",
	"ti", "bk", "al", "cl", "fl", "tl", "am", "cm", "fm", "pm", "sm", "tm", "cn", "in", "mn", "rn",
	"sn", "zn", "co", "ho", "mo", "no", "po", "np", "ar", "br", "cr", "er", "fr", "ir", "kr", "lr",
	"pr", "sr", "zr", "as", "cs", "ds", "es", "hs", "os", "at", "mt", "pt", "au", "cu", "eu", "lu",
	"pu", "ru", "lv", "dy"
};


void solve(){

    string s;
    cin >>s;

    int n = s.size();

    vector<bool> dp(n+1);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        string tmp = "";
        tmp += s[i-1];

        bool ok = 0;
        for(int j = 0; j < 14; j++) if (c1[j] == s[i-1]) ok = 1;
        if (ok && dp[i-1]) {
            dp[i] = 1;
            continue;
        }

        tmp = "";
        if (i >1 && dp[i-2]){
            tmp += s[i-2];
            tmp += s[i-1];

            ok = 0;
            for(int j = 0; j < 100; j++) if (c2[j] == tmp) ok = 1;
            if (ok) dp[i] = 1;
        }
    }

    if(dp[n])cout <<"YES\n";
    else cout <<"NO\n";

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >>t;
    while(t--){
        solve();
    }
}
