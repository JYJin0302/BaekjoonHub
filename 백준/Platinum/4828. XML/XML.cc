#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool validHEX(char c) {

    if (c >= '0' && c <= '9') return 1;
    if (c >= 'a' && c <= 'f') return 1;
    if (c >= 'A' && c <= 'F') return 1;
    return 0;
}

void solve(string s) {

    //& < >

    stack<string> tag;

    bool open_tag = 0, close_tag = 0;

    int l= -1, r = -1;

    bool valid = 1;
    int idx = 0;
    while (idx < s.size()) {

        char c = s[idx];
        if (c == '<') {
            if (open_tag || close_tag) {
                valid = 0;
                break;
            }
            if (idx + 1 < s.size() && s[idx + 1] == '/') close_tag = 1, l = idx + 2, idx++;
            else open_tag = 1, l = idx + 1;
        }
        else if (c == '>') {
            if (!open_tag && !close_tag) {
                valid = 0;
                break;
            }

            r = idx - 1;
            if (l > r) {
                valid = 0;
                break;
            }


            string curr_tag = s.substr(l, r-l+1);

            if (open_tag) tag.push(curr_tag), open_tag = 0;
            else if (close_tag) {
                if (!tag.empty() && tag.top() == curr_tag) tag.pop();
                else {
                    valid = 0;
                    break;
                }
                close_tag = 0;
            }
        }
        else if (c == '&') {
            bool ok = 0;
            if (idx + 3 < s.size() && s[idx + 2] == 't' && (s[idx + 1] == 'g' || s[idx + 1] == 'l') && s[idx + 3] == ';') ok = 1, idx += 3;
            // '<' , '>' check
            else if (idx + 4 < s.size() && s.substr(idx + 1, 4) == "amp;") ok = 1, idx += 4;
            else if (idx + 1 < s.size() && s[idx + 1] == 'x') {
                // hex test

                int tl = idx + 1;
                idx += 2;
                while (idx < s.size() && s[idx] != ';') {
                    if (!validHEX(s[idx])) {
                        valid = 0;
                        break;
                    }
                    idx++;
                }
                if (idx == s.size()) {
                    valid = 0;
                    break;
                }
                int tr = idx;
                if ((tr - tl) % 2 == 0 || tr == tl + 1) {
                    valid = 0;
                    break;
                }
            }
            else {
                valid = 0;
                break;
            }
        }
        else {
            if (open_tag || close_tag) {
                if (s[idx] >= 'a' && s[idx] <= 'z') {}
                else if (s[idx] >= '0' && s[idx] <= '9') {}
                else if (idx + 1 < s.size() && s[idx] == '/' && s[idx + 1] == '>') {
                    if (close_tag) {
                        valid = 0;
                        break;
                    }
                    open_tag = 0;
                    idx++;
                }
                else{
                    valid = 0;
                    break;
                }
            }
        }

        idx++;
    }


    if (!tag.empty() || open_tag || close_tag) valid = 0;
    if (valid) cout << "valid\n";
    else cout << "invalid\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while (getline(cin, s)) {
        solve(s);
    }
}