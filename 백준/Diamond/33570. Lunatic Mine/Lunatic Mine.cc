#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second
 
const int MinLuna[] = { 1, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1200, 1500, 1900, 2400, 3000, 3500, 4000, 4500, 5000, 5500, 7000, 8000, 9000, 10000, 11000, 13000, 15000,17000, 19000, 20000, 22000, 24000, 26000, 29000, 32000, 35000, 40000, 45000, 50000 };
const int MaxLuna[] = { 100, 200, 400, 600, 800, 1000, 1200, 1400, 1600, 1800, 2000, 2400, 3000, 3800, 4800, 6000, 7000, 8000, 9000, 10000, 11000, 14000, 16000, 18000, 20000, 20000, 20000, 20000, 20000, 20000, 20000, 22000, 24000, 26000, 29000, 32000, 35000, 40000, 45000, 50000 };
const int UpCost[] = { 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000, 13000, 14000, 15000, 20000, 22500, 25000, 27500, 30000, 35000, 40000, 45000, 50000, 60000, 70000, 80000, 90000, 100000, 200000, 0, 0 };
const int UpRate[] = { 100, 95, 90, 85, 80, 80, 80, 80, 80, 80, 70, 60, 50, 40, 30, 30, 30, 30, 30, 30, 25, 20, 15, 10, 5, 5, 4, 3, 2, 1 };
const int moonL[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 200, 300, 400, 500, 700, 900, 1100, 1300, 1500, 2000, 2500, 3000, 3500, 4000, 5000, 6000, 7000, 8000, 10000, 12000, 14000, 16000, 19000, 22000, 25000, 30000, 35000, 50000 };
const int P0[] = { 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 7, 9, 11, 13, 15, 16, 17, 18, 19, 20, 22, 24, 26, 28, 30, 34, 38, 42, 46, 50, 55, 60, 65, 75, 85, 95, 100, 200, 400 };
const int P1[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 7, 9, 11, 13, 15, 18, 21, 24, 27, 30, 35, 40, 45, 52, 59, 66, 76, 86, 100 };
const int P2[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 7, 9, 11, 13, 15, 18, 21, 24, 28, 32, 36, 40, 45, 50 };
const int P3[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25 };
 
vector<int> magicTable[5] = {
	{ 1, 4, 7, 10, 13, 14, 17},
	{ 1, 2, 4, 5, 7, 8, 10, 13, 14, 17 },
	{ 1, 2, 4, 5, 7, 8, 10, 11, 13, 14, 16, 17 },
	{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18},
	{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18}
};
 
int magicCost[5] = { 1000, 3000, 8000, 15000, 50000 };
 
struct RNG {
private:
	int idx = 0, tdx = 0;
	const ll a = 1664525;
	const ll c = 1013904223;
	const ll m = 4294967296;
	ll res[5005050];
public:
	RNG() {
		memset(res, 0, sizeof res);
	}
 
	void setRNG() {
		idx = 1;
		tdx = -1;
		cin >> res[0];
		for (int i = 1; i < 5005000; i++) res[i] = (res[i - 1] * a + c) % m;
	}
 
	int getIdx() {
		return idx;
	}
	void setIdx(int x) {
		idx = x;
	}
 
	ll rand() {
		return res[idx++];
	}
 
	ll randInt(ll l, ll r) {
		ll res = l + rand() * (r - l + 1) / m;
		return res;
	}
 
	bool chance(ll p) {
		return randInt(1, 100) <= p;
	}
 
	int choice(int arrSize) {
		return randInt(0, arrSize - 1);
	}
 
	void goTest() {
		assert(tdx == -1);
		tdx = idx;
	}
	void endTest() {
		assert(tdx != -1);
		idx = tdx;
		tdx = -1;
	}
} rng;
 
struct Achievement {
	bool flag[10];
	Achievement() {
		memset(flag, 0, sizeof flag);
		flag[0] = 1;
	}
 
	void done(int idx) {
		if (!flag[idx]) flag[idx] = 1;
	}
} ACV;
 
int x;
ll luna = 1000;
int Estone[5];
int Bstone = 0;
int Blev = 0;
int curPickaxe = 0;
 
struct Pickaxe {
	int magicRank;
	int magicID[3], magicVal[3];
	int smeltLevel;
	int DC;
 
	Pickaxe() {
		memset(magicID, 0, sizeof magicID);
		memset(magicVal, 0, sizeof magicVal);
		magicRank = 0;
		smeltLevel = 0;
		DC = 100;
	}
 
	bool isMaxLevel() {
		return smeltLevel == 30;
	}
 
	ll mine(bool debug = 0) {
		int lev = smeltLevel;
		for (int i = 0; i < 3; i++) if (magicID[i] == 16) lev += magicVal[i];
 
		int bLev = Blev;
		// 최종 배율 계산
		int mult = 100 + max(0, bLev - 20);
		for (int i = 0; i < 3; i++) {
			switch (magicID[i]) {
			case 10:
				mult += magicVal[i];
				break;
			case 11:
				mult += mult * magicVal[i] / 100;
				break;
			case 12:
				mult += mult * magicVal[i] / 100;
				break;
			default:
				break;
			}
		}
 
		// 최종 달빛
		ll lastMoonL = moonL[lev] + min(20, bLev) * 100;
		for (int i = 0; i < 3; i++) {
			switch (magicID[i]) {
			case 1:
				lastMoonL += magicVal[i];
				break;
			case 2:
				lastMoonL += lastMoonL * magicVal[i] / 100;
				break;
			case 3:
				lastMoonL += lastMoonL * magicVal[i] / 100;
				break;
			default:
				break;
			}
		}
 
		// 최종 최소 루나
		ll lastMinLuna = MinLuna[lev] + min(20, bLev) * 100;// +lastMoonL;
		for (int i = 0; i < 3; i++) {
			switch (magicID[i]) {
			case 4:
				lastMinLuna += magicVal[i];
				break;
			case 5:
				lastMinLuna += lastMinLuna * magicVal[i] / 100;
				break;
			case 6:
				lastMinLuna += lastMinLuna * magicVal[i] / 100;
				break;
			default:
				break;
			}
		}
		lastMinLuna = (lastMinLuna + lastMoonL) * mult / 100;
 
		// 최종 최대 루나
		ll lastMaxLuna = MaxLuna[lev] + min(20, bLev) * 200;// +lastMoonL;
		for (int i = 0; i < 3; i++) {
			switch (magicID[i]) {
			case 7:
				lastMaxLuna += magicVal[i];
				break;
			case 8:
				lastMaxLuna += lastMaxLuna * magicVal[i] / 100;
				break;
			case 9:
				lastMaxLuna += lastMaxLuna * magicVal[i] / 100;
				break;
			default:
				break;
			}
		}
		lastMaxLuna = (lastMaxLuna + lastMoonL) * mult / 100;
 
		int lastLuck = 1;
		for (int i = 0; i < 3; i++) {
			if (magicID[i] == 14) {
				lastLuck += magicVal[i];
			}
		}
 
		DC = 100;
		for (int i = 0; i < 3; i++) {
			if (magicID[i] == 17) {
				DC += magicVal[i];
			}
		}
 
		if (lastMinLuna + 100000 <= lastMaxLuna) ACV.done(3);
		if (lastMinLuna > lastMaxLuna) ACV.done(4);
 
		rng.goTest();
		ll res = rng.randInt(lastMinLuna, max(lastMinLuna, lastMaxLuna));
		rng.endTest();
 
		if (debug) {
			cout << res << " | " << lastMinLuna << ' ' << lastMaxLuna << '\n';
			cout << lev << ' ' << mult << ' ' << lastMoonL << '\n';
		}
		for (int i = 0; i < 3; i++) {
			if (magicID[i] == 18) {
				res += res * magicVal[i] / 100;
			}
		}
		return res;
		//for (int i = 0; i < 6; i++) rng.rand();
	}
 
	int smelt(bool test = 0) {
		if (smeltLevel >= 30) return -1;
		ll nd = UpCost[smeltLevel] * DC / 100;
		if (luna < nd) return -1;
		int p = UpRate[smeltLevel];
 
		if (test) rng.goTest();
		int res = rng.chance(p);
		if (test) rng.endTest();
 
		if (!test) {
			luna -= nd;
			if (res) smeltLevel++;
		}
		return res;
	}
 
	vector<int> enchant(bool test = 0) {
 
		vector<int> lst = magicTable[magicRank];
		vector<int> res;
		int sz = lst.size();
		int cost = magicCost[magicRank];
 
		if (luna < cost) {
			return { -1 };
		}
 
		if (test) rng.goTest();
		else luna -= cost;
 
		int cnt = 0;
		for (int i = 0; i < 3; i++) {
			int id = lst[rng.choice(sz)];
			if (id == 16) cnt++;
			int val = 100;
			if (id % 3 == 0 || id >= 14) {} // single
			else {
				// range
				rng.rand();
			}
			res.push_back(id);
		}
 
		if (test) rng.endTest();
		return res;
		//return 1 + cnt;
	}
 
 
	int rank_up(bool test = 0) {
		int p = 0;
		if (magicRank == 0) p = 16;
		else if (magicRank == 1) p = 9;
		else if (magicRank == 2) p = 4;
		else if (magicRank == 3) p = 1;
 
		if (test) rng.goTest();
		bool res = rng.chance(p);
		if (test) rng.endTest();
		else Estone[magicRank + 1]--;
 
		if (!test) {
			if (res) {
				memset(magicID, 0, sizeof magicID);
				memset(magicVal, 0, sizeof magicVal);
				magicRank++;
			}
			else {
				if (magicRank == 0) Bstone += 1;
				else if (magicRank == 1) Bstone += 2;
				else if (magicRank == 2) Bstone += 4;
				else if (magicRank == 3) Bstone += 8;
 
				while (Bstone >= Blev + 1) {
					Blev++;
					Bstone -= Blev;
				}
			}
		}
		return res;
	}
 
} pix[3];
 
void goMine() {
	cout << "mine" << endl;
	ll res = pix[curPickaxe].mine();
	cin >> x;
	ll y = 0;
	cin >> y;
 
	if (res != y) {
		cout << "ERR: " << res << ' ' << y << '\n';
		pix[curPickaxe].mine(1);
		exit(-1);
	}
	for (int i = 0; i < 6; i++) rng.rand();
	luna += y;
	for (int i = 0; i < 5; i++) {
		cin >> y;
		Estone[i] += y;
	}
}
 
 
int craft(int ix) {
	int cost = 0;
	if (ix == 1) cost = 1250;
	else if (ix == 2) cost = 2500;
	else if (ix == 3) cost = 5000;
	else if (ix == 4) cost = 10000;
 
	if (luna < cost || Estone[ix - 1] < 2) return -1;
	luna -= cost;
	Estone[ix - 1] -= 2;
	Estone[ix]++;
	return 1;
}
 
void getStone(int ix, int nd = 1) {
	if (Estone[ix] >= nd) return;
	if (ix == 0) {
		while (Estone[0] < nd) {
			goMine();
		}
		return;
	}
	getStone(ix - 1, 2 * (nd - Estone[ix]));
	assert(Estone[ix - 1] / 2 + Estone[ix] >= nd);
	while (Estone[ix] < nd) {
		int v = craft(ix);
		if (v == -1) goMine();
		else {
			cout << "craft " << ix << endl;
			cin >> x;
		}
	}
}
 
int main() {
 
	rng.setRNG();
 
	// go simul
	while (1) {
		//cout << "Current Luna: " << luna << '\n';
		if (!ACV.flag[0]) {
			cout << "smelt" << endl;
			cin >> x;
			pix[curPickaxe].smelt();
			if (luna == 0) ACV.done(0);
			continue;
		}
 
		if (!ACV.flag[1]) {
			// 30레벨까지 업그레이드
			if (pix[curPickaxe].smelt(1) == 1) {
				cout << "smelt" << endl;
				cin >> x;
				pix[curPickaxe].smelt();
			}
			else {
				goMine();
			}
			if (pix[curPickaxe].isMaxLevel()) ACV.done(1);
			continue;
		}
 
		if (!ACV.flag[2]) {
			// 레전더리 만들기
			getStone(pix[curPickaxe].magicRank + 1);
 
			int res = pix[curPickaxe].rank_up(1);
			if (res != 1) {
				goMine();
			}
			else {
				cout << "rank_up" << endl;
				cin >> x;
				pix[curPickaxe].rank_up();
				pix[curPickaxe].mine();
			}
 
			if (pix[curPickaxe].magicRank == 4) ACV.done(2);
			continue;
		}
 
		if (!ACV.flag[3] || !ACV.flag[4]) {
			while (pix[curPickaxe].enchant(1)[0] == -1) goMine();
			vector<int> res = pix[curPickaxe].enchant();
			cout << "enchant" << endl;
			cin >> x;
			for (int i = 0; i < 3; i++) {
				cin >> pix[curPickaxe].magicID[i] >> pix[curPickaxe].magicVal[i];
				assert(pix[curPickaxe].magicID[i] == res[i]);
			}
 
			//goMine();
			continue;
		}
 
		if (!ACV.flag[7]) {
			goMine();
			if (luna > 100000000) {
				ACV.done(7);
			}
			continue;
		}
 
		// 39렙 만들기
		while (1) {
			vector<int> res = pix[curPickaxe].enchant(1);
			int cnt = 0;
			for (auto f : res) cnt += (f == 16);
			if (cnt == 3) break;
 
			int ix = -1;
			int rdx = rng.getIdx();
 
			for (int i = 1; i < 6; i++) {
				rng.rand();
				res = pix[curPickaxe].enchant(1);
				cnt = 0;
				for (auto f : res) cnt += (f == 16);
				if (cnt == 3) {
					ix = i;
					break;
				}
			}
			rng.setIdx(rdx);
 
			if (ix == -1) {
				goMine();
				continue;
			}
 
			curPickaxe = 1;
			cout << "equip 1" << endl;
			cin >> x;
			for (int i = 0; i < ix; i++) {
				cout << "smelt" << endl;
				pix[1].smelt();
				cin >> x;
			}
			curPickaxe = 0;
			cout << "equip 0" << endl;
			cin >> x;
			break;
		}
 
			
		vector<int> res = pix[curPickaxe].enchant(); 
		int cnt = 0;
		for (auto f : res) cnt += (f == 16);
		assert(cnt == 3);
		cout << "enchant" << endl;
		cin >> x;
		for (int i = 0; i < 3; i++) {
			cin >> pix[curPickaxe].magicID[i] >> pix[curPickaxe].magicVal[i];
		}
		ACV.done(9);
		ACV.done(5);
 
		// 1단계 완료
		break;
	}
 
 
	// pix1 30렙 레전더리 만들기
	curPickaxe = 1;
	cout << "equip 1" << endl;
	cin >> x;
	while (pix[1].smeltLevel < 30) {
		if (pix[1].smelt(1) == -1) {
			curPickaxe = 0;
			cout << "equip 0" << endl;
			cin >> x;
			while (pix[1].smelt(1) == -1) {
				goMine();
			}
			curPickaxe = 1;
			cout << "equip 1" << endl;
			cin >> x;
		}
 
		while (pix[1].smelt(1) != 1) {
			goMine();
		}
		cout << "smelt" << endl;
		cin >> x;
		pix[1].smelt();
	}
 
	while (pix[1].magicRank < 4) {
		getStone(pix[1].magicRank + 1);
		int res = pix[1].rank_up(1);
		if (res != 1) {
			goMine();
		}
		else {
			cout << "rank_up" << endl;
			cin >> x;
			pix[1].rank_up();
			pix[1].mine();
		}
	}
 
	// pix2
	curPickaxe = 2;
	cout << "equip 2" << endl;
	cin >> x;
	while (pix[2].smeltLevel < 30) {
		if (pix[2].smelt(1) == -1) {
			curPickaxe = 0;
			cout << "equip 0" << endl;
			cin >> x;
			while (pix[2].smelt(1) == -1) {
				goMine();
			}
			curPickaxe = 2;
			cout << "equip 2" << endl;
			cin >> x;
		}
 
		while (pix[2].smelt(1) != 1) {
			goMine();
		}
		cout << "smelt" << endl;
		cin >> x;
		pix[2].smelt();
	}
 
	while (pix[2].magicRank < 4) {
		getStone(pix[2].magicRank + 1);
		int res = pix[2].rank_up(1);
		if (res != 1) {
			goMine();
		}
		else {
			cout << "rank_up" << endl;
			cin >> x;
			pix[2].rank_up();
			pix[2].mine();
		}
	}
 
	// level sum 100
	while (1) {
		vector<int> res = pix[2].enchant(1);
		bool ok = 0;
		for (auto f : res) if (f == 16) ok = 1;
		if (ok) break;
		goMine();
	}
 
	pix[2].enchant();
	cout << "enchant" << endl;
	cin >> x;
	for (int i = 0; i < 3; i++) {
		cin >> pix[2].magicID[i] >> pix[2].magicVal[i];
	}
 
	cout << "mine" << endl;
	cin >> x;
	pix[2].mine();
	cout << "exit" << endl;
 
}
