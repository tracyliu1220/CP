#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;


	double t[4], temp;

	int flag = 1;
	double start = -1, end = 1e9;

	int a, b, p, q;

	for (int i = 0; i < n; i ++) {
		cin >> a >> b >> p >> q;

		if (p == 0 && q == 0) {
			if ((x1 - a) * (a - x2) > 0 && (y1 - b) * (b - y2)) flag = 1;
			else flag = 0;
		}
		
		t[0] = (x1 - a) / (double)p;
		t[1] = (x2 - a) / (double)p;

		t[2] = (y1 - b) / (double)q;
		t[3] = (y2 - b) / (double)q;

		if (!(y1 <= b+t[0]*q && b+t[0]*q <= y2 || y2 <= b+t[0]*q && b+t[0]*q <= y1)) t[0] = -1; 
		if (!(y1 <= b+t[1]*q && b+t[1]*q <= y2 || y2 <= b+t[1]*q && b+t[1]*q <= y1)) t[1] = -1; 
		if (!(x1 <= a+t[2]*p && a+t[2]*p <= x2 || x2 <= a+t[2]*p && a+t[2]*p <= x1)) t[2] = -1; 
		if (!(x1 <= a+t[3]*p && a+t[3]*p <= x2 || x2 <= a+t[3]*p && a+t[3]*p <= x1)) t[3] = -1; 

		map<double, int> m;
		for (int i = 0; i < 4; i ++) {
			if (t[i] == -1) continue;
			
			m[t[i]] ++;
		}

		if (m.size() == 0) flag = 0;
		if (m.size() == 1) flag = 0;
		else {
			start = max(start, m.begin()->first);
			end = min(end, (--m.end())->first);
		}
	}

	if (flag && start <= end) printf("%.9f\n", start); 
	else cout << -1 << endl;

}
