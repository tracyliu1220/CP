#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define F first
#define S second

double F(double x, double vx, double vy) {
	return (-(x * x / 2 / vx / vx) + (vy / vx) * x);
}

int main() {
	int n; double d, b; 
	cin >> d >> n >> b; //distance, obstacles, bounces
	vector<pii> P(n);
	for (int i = 0; i < n; i ++)
		cin >> P[i].F >> P[i].S;

	double ans = 1e9;
	for (int bounce = 1; bounce <= b + 1; bounce ++) {
		double l = d / bounce;
		//BS Vy
		double L = sqrt(l / 2), R = 1e9, M;
		int t = 100; while (t --) {
			M = (L + R) / 2;
			int legal = 1;
			for (int i = 0; i < n; i ++) {
				double p = P[i].F, h = P[i].S;
				p = p - (int)(p / l) * l;
				if (F(p, l / 2 / M, M) < h) {
					legal = 0;
					break;
				}
			}
			if (legal) R = M;
			else L = M;
		}
		ans = min(ans, sqrt(L * L + l * l / 4 / L / L));
	}

	cout << fixed << setprecision(8) << ans << '\n';
}
