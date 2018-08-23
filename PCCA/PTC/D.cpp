#include <bits/stdc++.h>
using namespace std;

struct Block {
	int x, y;
};

bool if_fix (Block a, Block b) {
	if (a.x <= b.x && a.y <= b.y) return true;
	else if (a.y > b.y) return false;
	
	double diagonal = a.x * a.x + a.y * a.y;
	double d = sqrt(diagonal - b.y * b.y);

	double cos_theta = d * a.x / diagonal + b.y * a.y / diagonal,
		   sin_theta = b.y * a.x / diagonal - d * a.y / diagonal;
	
	double w = a.x * cos_theta + a.y * sin_theta;
	
	if (w <= b.x) return true;
	else return false;
}

int main() {
	while (1) {
		Block a, b;
		cin >> a.x >> a.y >> b.x >> b.y;
		if (if_fix(a, b)) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}
