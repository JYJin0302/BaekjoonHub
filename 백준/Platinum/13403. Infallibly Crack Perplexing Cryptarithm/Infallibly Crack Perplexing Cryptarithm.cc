#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

char cList[] = { '(', ')', '0', '1', '+', '-', '*', '=' };
string str;
map<char, bool> isV;

bool invalid;


int N(int st, int en) {
    if (en < st) {
        invalid = 1;
        return 0;
    }

    if (str[st] == '0') {
        if (st != en) invalid = 1;
        return 0;
    }

    int res = 0;

    for (int i = st; i <= en; i++) {
        if (str[i] != '0' && str[i] != '1') {
            invalid = 1;
            return 0;
        }

        res = res * 2 + char(str[i] - '0');
    }
    return res;

}

int E(int st, int en);

int F(int st, int en) {
    if (st > en) {
        invalid = 1;
        return 0;
    }

    //cout << "GO F: " << st << ' ' << en << '\n';
    if (str[st] == '(') {
        if (str[en] == ')') return E(st + 1, en - 1);
        else {
            invalid = 1;
            return 0;
        }
    }
    else if (str[st] == '-') return -F(st + 1, en);
    else return N(st, en);
}


int T(int st, int en) {
    if (st > en) {
        invalid = 1;
        return 0;
    }

    //cout << "Go T: " << st << ' ' << en << '\n';

    int mid = en + 1;
    int cnt = 0;
    for (int i = st; i <= en; i++) {
        if (str[i] == '(') cnt++;
        else if (str[i] == ')') cnt--;
        else {
            if (str[i] == '*') {
                if (cnt == 0) {
                    mid = i;
                }
            }
        }
    }
    if (mid == en + 1) return F(st, en);
    else return T(st, mid - 1) * F(mid + 1, en);
}

int E(int st, int en) {
    if (st > en) {
        invalid = 1;
        return 0;
    }

    //cout << "Go E: " << st << ' ' << en << '\n';
    int mid = en + 1;
    int cnt = 0;

    int i = st;
    while(i <=en){
        //Sleep(10);
        //cout << "Go: " << i << '\n';
        if (str[i] == '(') cnt++;
        else if (str[i] == ')') cnt--;
        else if (str[i] == '+') {
            if (cnt == 0) {
                mid = i;
            }
        }
        else if (str[i] == '-'){


            if (i == st || (i > st && str[i-1] != '0' && str[i-1] != '1' && str[i-1] != ')')) {
                while (i <= en && str[i] == '-') i++;
                i--;
            }
            else if (cnt == 0) {
                mid = i;
            }
        }
        i++;
    }

    if (mid == en + 1) return T(st, en);
    else if (str[mid] == '+') {
        if (mid == st) invalid = 1;
        return E(st, mid - 1) + T(mid + 1, en);
    }
    else return E(st, mid - 1) - T(mid + 1, en);
}

bool Q(int st, int en) {
    int cnt = 0;
    int mid = -1;
    for (int i = st; i <= en; i++) {
        if (str[i] == '=') {
            mid = i;
            cnt++;
        }
    }
    if (cnt != 1 || mid == st || mid == en) {
        invalid = 1;
        return false;
    }

    int v1 = E(st, mid - 1);
    int v2 = E(mid + 1, en);

    if (!invalid) {
        //cout << str <<' ' << v1 <<' ' <<v2 <<'\n';
        return v1 == v2;
    }
    return 0;
}


void solve() {

    for (int i = 0; i < 8; i++) {
        isV[cList[i]] = 1;
    }

    string s;
    cin >> s;

    int n = s.size();

    vector<char> vList;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (!isV[c]) {
            vList.push_back(s[i]);
        }
    }

    sort(vList.begin(), vList.end());
    vList.erase(unique(vList.begin(), vList.end()), vList.end());

    while (vList.size() < 8) vList.push_back('0');
    sort(vList.begin(), vList.end());

    if (vList.size() > 8) {
        cout << 0;
        return;
    }


    int ans = 0;
    do {

        //for(auto f :vList) cout <<f;
        //cout << '\n';

        map<char, char> conv;
        for (int f = 0; f < 8; f++) conv[vList[f]] = cList[f];

        string newS;
        for (int i = 0; i < n; i++) {
            if (isV[s[i]]) newS += s[i];
            else newS += conv[s[i]];
        }

       // cout << "Solve: " << newS << '\n';
        str = newS;
        invalid = 0;
        if (Q(0, newS.size() - 1) && !invalid) {
           // cout << "Found: " << newS << '\n';
            ans++;
        }
        else if (!invalid) {
            //cout << "valid: " << str << '\n';
        }
        

    } while (next_permutation(vList.begin(), vList.end()));

    cout << ans;
}



int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
    // cin >>t;
    while (t--) {

        solve();
    }

}
