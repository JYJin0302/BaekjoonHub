#include <bits/stdc++.h>
using namespace std;

struct Cube {
	vector<int> u;  // up
	vector<int> f;  // front
	vector<int> d;  // down
	vector<int> l;  // left
	vector<int> r;  // right
	vector<int> b;  // back

	// 시계방향 90도 회전
	void tiltU(){
		int b1, b2;
		b1 = u[0];
		u[0] = u[2];
		u[2] = u[3];
		u[3] = u[1];
		u[1] = b1;

		b1 = f[0], b2 = f[1];
		tie(f[0], f[1]) = { r[0], r[1] };
		tie(r[0], r[1]) = { b[0], b[1] };
		tie(b[0], b[1]) = { l[0], l[1] };
		tie(l[0], l[1]) = { b1, b2 };
	}
	void tiltF() {
		int b1, b2;
		b1 = f[0];
		f[0] = f[2];
		f[2] = f[3];
		f[3] = f[1];
		f[1] = b1;

		b1 = u[2], b2 = u[3];
		tie(u[2], u[3]) = { l[3], l[1] };
		tie(l[3], l[1]) = { d[1], d[0] };
		tie(d[1], d[0]) = { r[0], r[2] };
		tie(r[0], r[2]) = { b1, b2 };
	}
	void tiltD() {
		int b1, b2;
		b1 = d[0];
		d[0] = d[2];
		d[2] = d[3];
		d[3] = d[1];
		d[1] = b1;

		b1 = f[2], b2 = f[3];
		tie(f[2], f[3]) = { l[2], l[3] };
		tie(l[2], l[3]) = { b[2], b[3] };
		tie(b[2], b[3]) = { r[2], r[3] };
		tie(r[2], r[3]) = { b1, b2 };
	}
	void tiltL() {
		int b1, b2;
		b1 = l[0];
		l[0] = l[2];
		l[2] = l[3];
		l[3] = l[1];
		l[1] = b1;

		b1 = u[0], b2 = u[2];
		tie(u[0], u[2]) = { b[3], b[1] };
		tie(b[3], b[1]) = { d[0], d[2] };
		tie(d[0], d[2]) = { f[0], f[2] };
		tie(f[0], f[2]) = { b1, b2 };
	}
	void tiltR() {
		int b1, b2;
		b1 = r[0];
		r[0] = r[2];
		r[2] = r[3];
		r[3] = r[1];
		r[1] = b1;

		b1 = u[3], b2 = u[1];
		tie(u[3], u[1]) = { f[3], f[1] };
		tie(f[3], f[1]) = { d[3], d[1] };
		tie(d[3], d[1]) = { b[0], b[2] };
		tie(b[0], b[2]) = { b1, b2 };
	}
	void tiltB() {
		int b1, b2;
		b1 = b[0];
		b[0] = b[2];
		b[2] = b[3];
		b[3] = b[1];
		b[1] = b1;

		b1 = u[0], b2 = u[1];
		tie(u[0], u[1]) = { r[1], r[3] };
		tie(r[1], r[3]) = { d[3], d[2] };
		tie(d[3], d[2]) = { l[2], l[0] };
		tie(l[2], l[0]) = { b1, b2 };
	}

	bool solved() {
		if (*max_element(u.begin(), u.end()) != *min_element(u.begin(), u.end())) return false;
		if (*max_element(f.begin(), f.end()) != *min_element(f.begin(), f.end())) return false;
		if (*max_element(d.begin(), d.end()) != *min_element(d.begin(), d.end())) return false;
		if (*max_element(l.begin(), l.end()) != *min_element(l.begin(), l.end())) return false;
		if (*max_element(r.begin(), r.end()) != *min_element(r.begin(), r.end())) return false;
		if (*max_element(b.begin(), b.end()) != *min_element(b.begin(), b.end())) return false;
		return true;
	}
};


int main() {
	int a;
	Cube cube;
	for (int i = 0; i < 24; i++) {
		cin >> a;
		if (i / 4 == 0) cube.u.push_back(a);
		else if (i / 4 == 1) cube.f.push_back(a);
		else if (i / 4 == 2) cube.d.push_back(a);
		else if (i / 4 == 3) cube.l.push_back(a);
		else if (i / 4 == 4) cube.r.push_back(a);
		else cube.b.push_back(a);
	}

	for (int phase = 0; phase < 6; phase++) {
		if (phase == 0) {
			cube.tiltU();
			if (cube.solved()) {
				cout << 1;
				return 0;
			}
			cube.tiltU();
			cube.tiltU();
			if (cube.solved()) {
				cout << 1;
				return 0;
			}
			cube.tiltU();
		}
		else if (phase == 1) {
			cube.tiltF();
			if (cube.solved()) {
				cout << 1;
				return 0;
			}
			cube.tiltF();
			cube.tiltF();
			if (cube.solved()) {
				cout << 1;
				return 0;
			}
			cube.tiltF();
		}
		else if (phase == 2) {
			cube.tiltD();
			if (cube.solved()) {
				cout << 1;
				return 0;
			}
			cube.tiltD();
			cube.tiltD();
			if (cube.solved()) {
				cout << 1;
				return 0;
			}
			cube.tiltD();
		}
		else if (phase == 3) {
			cube.tiltL();
			if (cube.solved()) {
				cout << 1;
				return 0;
			}
			cube.tiltL();
			cube.tiltL();
			if (cube.solved()) {
				cout << 1;
				return 0;
			}
			cube.tiltL();
		}
		else if (phase == 4){
			cube.tiltR();
			if (cube.solved()) {
				cout << 1;
				return 0;
			}
			cube.tiltR();
			cube.tiltR();
			if (cube.solved()) {
				cout << 1;
				return 0;
			}
			cube.tiltR();
		}
		else {
			cube.tiltB();
			if (cube.solved()) {
				cout << 1;
				return 0;
			}
			cube.tiltB();
			cube.tiltB();
			if (cube.solved()) {
				cout << 1;
				return 0;
			}
			cube.tiltB();
		}
	}
	cout << 0;
}