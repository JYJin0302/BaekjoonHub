#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

enum Parameter {
    IDX,
    HP,
    ATK,
    DEF,
    SPECIAL_ATK,
    SPECIAL_DEF,
    SPEED
};
map<string, int> pdx = {
    {"idx", 0},
    {"hp", 1},
    {"atk", 2},
    {"def", 3},
    {"special_atk", 4},
    {"special_def", 5},
    {"speed", 6}
};

vector<pair<int, int>> sortOrder;

void sortAdd(string t, string d) {
    int ix = pdx[t];
    for (auto iter = sortOrder.begin(); iter != sortOrder.end(); iter++) {
        if ((*iter).x == ix) {
            sortOrder.erase(iter);
            break;
        }
    }
    sortOrder.push_back(mp(ix, (d == "asc")));
    // 1: asc, 0 : desc
}

struct Pokemon {
    int val[7];
    string name, type1, type2;
    int ord;

    bool operator<(Pokemon& o) {
        for (int i = (int)sortOrder.size() - 1; i >= 0; i--) {
            auto [a, b] = sortOrder[i];
            if (val[a] == o.val[a]) continue;
            if (b) return val[a] < o.val[a];
            return o.val[a] < val[a];
        }
        return ord < o.ord;
    }
};

vector<Pokemon> P_list;

struct Filter {

    map<string, bool> type = {
        {"bug", 1 }, { "dark", 1 }, { "dragon", 1 }, { "electric", 1 }, { "fairy", 1 }, { "fighting", 1 }, { "fire", 1 }, { "flying", 1 }, { "ghost", 1 },\
    { "grass", 1 }, { "ground", 1 }, { "ice", 1 }, { "normal", 1 }, { "poison", 1 }, { "psychic", 1 }, { "rock", 1 }, { "steel", 1 }, { "water", 1 }
    };
    string preFix = "BLANK";
    int val[7][2];
    Filter() {
        for (int i = 0; i < 7; i++) {
            val[i][0] = 1;
            val[i][1] = 200000;
        }
    }

    void setVal(string t, string m, int v) {
        int ix = pdx[t];
        if (m == "min") val[ix][0] = v;
        else val[ix][1] = v;
    }

    bool check(Pokemon& p) {
        if (!type[p.type1] && !type[p.type2]) return 0;
        if (preFix != "BLANK" && p.name.substr(0, preFix.size()) != preFix) return 0;
        for (int i = 0; i < 7; i++) {
            if (val[i][0] <= p.val[i] && p.val[i] <= val[i][1]) {}
            else return 0;
        }
        return 1;
    }

} filter;

struct Window {
    int W = 5, H = 5;
    int cursor = 0;
    int pokeCnt = 0;

    void move(char c, int w) {
        if (c == 'l') cursor--;
        else if (c == 'r') cursor++;
        else if (c == 'u') cursor -= w;
        else if (c == 'd') cursor += w;

        cursor = max(cursor, 0);
        cursor = min(cursor, pokeCnt - 1);
    }
} window;

int Grid[11][11];

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        Pokemon p;
        cin >> p.name >> p.type1 >> p.type2;
        for (int j = 1; j < 7; j++) cin >> p.val[j];
        p.val[IDX] = i + 1;
        p.ord = i + 1;
        P_list.push_back(p);
    }

    queue<pair<char, int>> mv;
    int q;
    cin >> q;
    while (q--) {

        string s, s1, s2;
        cin >> s;

        if (s == "sort") {
            cin >> s1 >> s2;
            sortAdd(s1, s2);
            window.cursor = 0;
            while (!mv.empty()) mv.pop();
            continue;
        }
        else if (s == "filter") {
            cin >> s1 >> s2;

            if (s1 == "name") {
                filter.preFix = s2;
            }
            else if (s1 == "type") {
                filter.type[s2] ^= 1;
            }
            else {
                int x;
                cin >> x;
                int i1 = pdx[s1];
                int i2 = (s2 == "max");
                filter.val[i1][i2] = x;
            }
            window.cursor = 0;
            while (!mv.empty()) mv.pop();
        }
        else if (s == "resize") {
            cin >> s1;
            int x;
            cin >> x;

            if (s1 == "W") window.W = x;
            else window.H = x;
        }
        else if (s == "cursor") {
            char c;
            cin >> c;
            mv.push(mp(c, window.W));
        }
        else if (s == "flush") {

            sort(all(P_list));
            sortOrder.clear();

            for (int i = 0; i < n; i++) {
                P_list[i].ord = i + 1;
            }
            // filter에 걸리는 포켓몬 수 세기

            vector<Pokemon> res;
            for (int i = 0; i < n; i++) {
                if (filter.check(P_list[i])) res.push_back(P_list[i]);
            }
            int sz = res.size();
            window.pokeCnt = sz;


            while (!mv.empty()) {
                auto [c, w] = mv.front(); mv.pop();
                window.move(c, w);
            }

            for (int i = 0; i < window.H; i++) {
                for (int j = 0; j < window.W; j++) Grid[i][j] = 0;
            }

            if (sz != 0) {
                int tdx = window.cursor - window.cursor % window.W;
                int cx = 0, cy = 0;
                while (tdx < sz && cx < window.H) {
                    Grid[cx][cy] = res[tdx].val[IDX];
                    cy++;
                    tdx++;
                    if (cy == window.W) {
                        cy = 0;
                        cx++;
                    }
                }


            }

            for (int i = 0; i < window.H; i++) {
                for (int j = 0; j < window.W; j++) cout << Grid[i][j] << ' ';
                cout << '\n';
            }
            cout << '\n';
        }

    }


}