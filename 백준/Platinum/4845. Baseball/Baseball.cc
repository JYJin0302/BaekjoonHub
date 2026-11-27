#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int x_n;
void randx(){
    x_n = (x_n * 25173 + 13849) % 65536;
}

struct Player{
    
    Player(): name("-"), hit(0), sac(0) {};
    
    string name;
    double hit;
    double sac;
};

string v, h;
vector<Player> visitTeam, homeTeam;
int vi, hi;
int scoreV, scoreH;

pair<int, int> stateV, stateH;

void game(int inning){
    
    int outCnt = 0;
    vector<string> base(4, "-");
    vector<pair<string, string>> Hit, Run; // team, name
    
    // visitTeam attack
    while(outCnt < 3){
        
        Player& batter = visitTeam[vi];
        vi = (vi + 1) % 9;
        randx();
        
        // check sacrifice
        bool isSac = (outCnt <= 1 && base[3] != "-") || (outCnt == 0 && base[2] != "-");
        
        double chance = isSac ? batter.sac : batter.hit;
        
        bool isHit = (chance * 65536 >= x_n);
        
        if (isHit){
            
            if (base[3] != "-") {
                Run.push_back({v, base[3]});
                scoreV++;
                stateV.x++;
            }
            base[3] = base[2];
            base[2] = base[1];
            base[1] = "-";
            
            if (isSac){
                 outCnt++;
            }
            else{
                Hit.push_back({v, batter.name});
                base[1] = batter.name;
                stateV.y++;
            }
        }
        else outCnt++;
    }
    
    // homeTeam attack
    base = vector<string>(4, "-");
    outCnt = 0;
    if (inning >= 9 && scoreV < scoreH) outCnt = 3;
    
    while(outCnt < 3){
        
        
        Player& batter = homeTeam[hi];
        hi = (hi + 1) % 9;
        randx();
        
        // check sacrifice
        bool isSac = (outCnt <= 1 && base[3] != "-") || (outCnt == 0 && base[2] != "-");
        
        double chance = isSac ? batter.sac : batter.hit;
        
        bool isHit = (chance * 65536 >= x_n);
        
        if (isHit){
            
            if (base[3] != "-") {
                Run.push_back({h, base[3]});
                scoreH++;
                stateH.x++;
            }
            base[3] = base[2];
            base[2] = base[1];
            base[1] = "-";
            
            if (isSac){
                outCnt++;
            }
            else{
                Hit.push_back({h, batter.name});
                base[1] = batter.name;
                stateH.y++;
            }
            
        }
        else outCnt++;
        
        
    }
    
    // print result
    cout << "Inning " << inning << ":\n";
    cout << "Hits:\n";
    
    if (Hit.size() == 0){
        cout << "  none\n";
    }
    else{
        for (auto i : Hit){
            int sx = i.x.size(), sy = i.y.size();
            
            cout << string(17 - sy, ' ') << i.y << string(16 - sx, ' ') << i.x << '\n'; 
        }
    }
    
    cout << "\nRuns:\n";
    
    if (Run.size() == 0){
        cout << "  none\n";
    }
    else{
        for (auto i : Run){
            int sx = i.x.size(), sy = i.y.size();
            
            cout << string(17 - sy, ' ') << i.y << string(16 - sx, ' ') << i.x << '\n'; 
        }
    }
    cout << '\n';
}


int main(){
    
    int t;
    cin >> t;
    
    visitTeam = vector<Player>(9);
    homeTeam = vector<Player>(9);
    for(int game_cnt = 1; game_cnt <= t; game_cnt++){
        
        cin >> v;
        for(int i = 0; i < 9; i++) cin >> visitTeam[i].name >> visitTeam[i].hit >> visitTeam[i].sac;
        
        cin >> h;
        for(int i = 0; i < 9; i++) cin >> homeTeam[i].name >> homeTeam[i].hit >> homeTeam[i].sac;
        // --------------------- 입력 끝 -------------------
        
        // init
        x_n = 1;
        vi = hi = 0;
        scoreV = scoreH = 0;
        stateV = stateH = {0, 0};
        
        cout << "Game " << game_cnt << ": " << v << " vs. " << h << "\n\n";
        
        int inning = 1;
        while(inning <= 9 || scoreV == scoreH){
            game(inning);
            inning++;
        }
        
        // End of Game
        cout << "End of Game:\n";
        cout << string(17 - v.size(), ' ') << v << ' ' << stateV.x << " runs, " << stateV.y << " hits\n";
        cout << string(17 - h.size(), ' ') << h << ' ' << stateH.x << " runs, " << stateH.y << " hits\n";
        
        
        
        if (game_cnt != t){
            cout << string(60, '=') << '\n';
        }
        
    }
    
    cout << '\n';
}