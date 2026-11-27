#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;

string deadmon;
bool deadtrap;

struct Player {

	int sx, sy;  // start point
	int x, y;  // current point

	int LV = 1;
	int maxHP = 20;
	int currHP = 20;
	int ATT = 2;
	int DEF = 2;
	int EXP = 0;

	int Wep = 0;
	int Armor = 0;

	int accCnt = 0;
	map<string, bool> acc;

	void gain_exp(int exp) {
		EXP += exp;
		if (EXP >= LV * 5) {
			EXP = 0;
			LV++;
			maxHP += 5;
			currHP = maxHP;
			ATT += 2;
			DEF += 2;
		}
	}

	void move(char c) {

		int nx = x;
		int ny = y;

		switch (c) {
		case 'D':
			nx++;
			break;
		case 'U':
			nx--;
			break;
		case 'R':
			ny++;
			break;
		case 'L':
			ny--;
			break;
		}

		if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#') {
			x = nx;
			y = ny;
		}
	}

	void revive() {
		acc["RE"] = 0;
		x = sx;
		y = sy;
		currHP = maxHP;
	}

	char position() {
		return grid[x][y];
	}
	
	void status() {
		cout << "LV : " << LV << '\n';
		cout << "HP : " << currHP << '/' << maxHP << '\n';
		cout << "ATT : " << ATT << '+' << Wep << '\n';
		cout << "DEF : " << DEF << '+' << Armor << '\n';
		cout << "EXP : " << EXP << '/' << LV * 5 << '\n';
	}
};
Player player;

struct Item {

	char type;  // weapon, armor, accessory

	int n;  // weapon, armor
	string s;  // accessory;

};
vector<Item> items;

map<pair<int, int>, int> monster_index, item_index;

struct Monster {
	string name;

	int HP, ATT, DEF, EXP;
};
vector<Monster> enemy;


void fight(Monster mon) {
	bool boss = (grid[player.x][player.y] == 'M');

	bool ignore = 0;
	int damageboost = 1;
	if (boss && player.acc["HU"]) {
		ignore = 1;
		player.currHP = player.maxHP;
	}

	if (player.acc["CO"]) {
		if (player.acc["DX"]) damageboost = 3;
		else damageboost = 2;
	}

	player.ATT += player.Wep;
    player.DEF += player.Armor;
    
	while (player.currHP > 0 && mon.HP > 0) {

		mon.HP -= max(1, player.ATT * damageboost - mon.DEF);
		damageboost = 1;

		if (mon.HP > 0) {
			if (ignore) {
				ignore = 0;
			}
			else {
				player.currHP -= max(1, mon.ATT - player.DEF);
			}
		}
	}

	player.ATT -= player.Wep;
    player.DEF -= player.Armor;
    
	bool win = (player.currHP > 0);

	if (win) {
		grid[player.x][player.y] == '.';

		if (player.acc["EX"]) mon.EXP = mon.EXP * 6 / 5;

		if (player.acc["HR"]) player.currHP = min(player.maxHP, player.currHP + 3);

		player.gain_exp(mon.EXP);
	}
	else {
		if (player.acc["RE"]) player.revive();
		else deadmon = mon.name;
	}
}

void trap() {
	if (player.acc["DX"]) player.currHP -= 1;
	else player.currHP -= 5;

	if (player.currHP <= 0) {
		if (player.acc["RE"]) player.revive();
		else deadtrap = 1;
	}
}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		grid.push_back(s);
	}

	string move;
	cin >> move;

	int enemycnt = 0, boxcnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 'M' || grid[i][j] == '&') {
				enemycnt++;
			}
			else if (grid[i][j] == 'B') {
				boxcnt++;
			}
			else if (grid[i][j] == '@') {
				player.x = i; player.y = j;
				player.sx = i; player.sy = j;
				grid[i][j] = '.';
			}
		}
	}

	for (int i = 0; i < enemycnt; i++) {
		int r, c, w, a, h, e;
		string s;
		cin >> r >> c >> s >> w >> a >> h >> e;

		r--, c--;

		Monster mon;
		monster_index[{r, c}] = i;

		mon.name = s;
		mon.ATT = w;
		mon.DEF = a;
		mon.HP = h;
		mon.EXP = e;

		enemy.push_back(mon);
	}

	for (int i = 0; i < boxcnt; i++) {
		int r, c;
		char t;
		cin >> r >> c >> t;

		r--, c--;
		item_index[{r, c}] = i;

		Item item;
		item.type = t;

		if (t == 'W' || t == 'A') {
			int k;
			cin >> k;

			item.n = k;
		}
		else {
			string s;
			cin >> s;

			item.s = s;
		}

		items.push_back(item);
	}

	// ----------------입력 완료--------------

	bool gameover = 0;
	bool gamewin = 0;

	int turn = 0;
	while (turn < move.size()) {

		player.move(move[turn]);
		turn++;
		

		if (player.position() == 'M' || player.position() == '&') {
			fight(enemy[monster_index[{player.x, player.y}]]);

			if (deadmon != "") {
				gameover = 1;
				break;
			}

			if (grid[player.x][player.y] == 'M') {
				gamewin = 1;
				break;
			}

			grid[player.x][player.y] = '.';
		}
		else if (player.position() == 'B') {

			grid[player.x][player.y] = '.';

			Item founditem = items[item_index[{player.x, player.y}]];
			if (founditem.type == 'W') player.Wep = founditem.n;
			else if (founditem.type == 'A') player.Armor = founditem.n;
			else if (player.accCnt == 4);
			else if (player.acc[founditem.s] != 1) {
				player.accCnt++;
				player.acc[founditem.s] = 1;
			}
		}
		else if (player.position() == '^') {
			trap();

			if (deadtrap) {
				gameover = 1;
				break;
			}
		}
	}

	if (!gameover) grid[player.x][player.y] = '@';
	if (deadtrap) deadmon = "SPIKE TRAP";

	for (string s : grid) cout << s << '\n';

	cout << "Passed Turns : " << turn << '\n';
	player.currHP = max(0, player.currHP);
	player.status();

	if (gamewin) cout << "YOU WIN!\n";
	else if (deadmon != "") cout << "YOU HAVE BEEN KILLED BY " << deadmon << "..\n";
	else cout << "Press any key to continue.\n";
}