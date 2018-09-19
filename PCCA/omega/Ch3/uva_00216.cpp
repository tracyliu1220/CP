#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

int n, cnt = 1;
vector<pair<int, int> > v;
vector<vector<double> > dp;
vector<vector<int> > from;

double dis(pair<int, int> a, pair<int, int> b) {
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second)) + 16;
}

double TSP(int x, int msk) {
	if (msk == (1 << n) - 1) return dp[x][msk] = 0;
	if (dp[x][msk] != INF) return dp[x][msk];

	double Min = INF;
	int min_to;

	for (int k = 0; k < n; k ++) {
		if (k != x && !(msk & (1 << k))) {
			double tmp = TSP(k, (1 << k) | msk) + dis(v[k], v[x]);
			if (Min > tmp) {
				Min = tmp;
				min_to = k;
			}
		}
	}
	from[x][msk] = min_to;
	return dp[x][msk] = Min;
}

int main() {

	int cases = 1;

	while (cin >> n && n) {
		v.clear();	
	
		int x, y;
		for (int i = 0; i < n; i ++) {
			cin >> x >> y;
			v.push_back(make_pair(x, y));
		}

		dp.clear();		dp.resize(n, vector<double>(1 << n, INF));
		from.clear(); 	from.resize(n, vector<int>(1 << n, INF));

		for (int i = 0; i < n; i ++) dp[i][(1 << n) - 1] = 0;
	
		int min_end;
		double Min = INF;

		for (int i = 0; i < n; i ++) {
			double tmp = TSP(i, 1 << i);
			if (Min > tmp) {
				Min = tmp;
				min_end = i;
			}
		}

		cout << "**********************************************************\n";
		cout << "Network #" << cases ++ << '\n';

		int msk = 1 << min_end;
		int cur = min_end, lst = min_end;

		for (int i = 0; i < n; i ++) {
			if (cur != lst) 
			    printf(
					"Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",
					v[lst].first, v[lst].second, v[cur].first, v[cur].second, dis(v[cur], v[lst]));		
			lst = cur;
			msk |= (1 << cur);
			cur = from[cur][msk];
		}

		printf("Number of feet of cable required is %.2lf.\n", dp[min_end][(1 << min_end)]);
	}

}
