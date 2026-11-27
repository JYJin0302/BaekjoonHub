#include <bits/stdc++.h>
using namespace std;

int main(){
    
    map<string, int> val;
    val["black"] = 0;
    val["brown"] = 1;
    val["red"] = 2;
    val["orange"] = 3;
    val["yellow"] = 4;
    val["green"] = 5;
    val["blue"] = 6;
    val["violet"] = 7;
    val["grey"] = 8;
    val["white"] = 9;
    
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    
    if (s1 == "black" && s2 == "black") cout << 0;
    else if (s1 == "black") cout << val[s2] << string(val[s3], '0');
    else cout << val[s1] << val[s2] << string(val[s3], '0');
}