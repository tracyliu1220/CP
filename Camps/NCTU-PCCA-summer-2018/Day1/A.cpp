#include <bits/stdc++.h>
using namespace std;

struct point {int x; int y;};

point leftest;

bool compare (point a, point b) {
	if (a.x == leftest.x && a.y == leftest.y) return true;
	if (b.x == leftest.x && b.y == leftest.y) return false;

	if (a.x == leftest.x && b.x == leftest.x) {
		if (a.y > b.y) return true;
		else return false;
	}else if (a.x == leftest.x && b.x != leftest.x) return false;
	else if (a.x != leftest.x && b.x == leftest.x) return true;

	double ma = (a.y - leftest.y) / (a.x - (double)leftest.x);
	double mb = (b.y - leftest.y) / (b.x - (double)leftest.x);

	if (ma < mb) return true;
	else if (ma == mb) {
		if (a.x < b.x) return true;
		else return false;
	} else return false;

}

int main() {
	
	int T;
	cin >> T;

	vector<point> p;

	while (T --) {
		int N;
		cin >> N;
	
		int x, y;
		char c;
		int minx = 0;
		for (int i = 0; i < N; i ++) {
			cin >> x >> y >> c;
			if (c == 'Y') {
				point pnt;
				pnt.x = x; pnt.y = y;
				p.push_back(pnt);
				if (p.back().x < p[minx].x) minx = p.size() - 1;
				else if (p.back().x == p[minx].x && p.back().y < p[minx].y) minx = p.size() - 1;
			}
		}

		leftest.x = p[minx].x; leftest.y = p[minx].y;
	
		sort(p.begin(), p.end(), compare);

		cout << p.size() << endl;
		for (int i = 0; i < p.size(); i ++)
			cout << p[i].x << " " << p[i].y << endl;

		p.clear();

	}

}
