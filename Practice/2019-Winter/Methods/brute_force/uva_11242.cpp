#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	while (cin >> n && n) {
		cin >> m;
		vector<int> F, R;
		int tmp;
		for (int i = 0; i < n; i ++) {
			cin >> tmp;
			F.push_back(tmp);
		}
		for (int i = 0; i < m; i ++) {
			cin >> tmp;
			R.push_back(tmp);
		}
		vector<double> D;
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				D.push_back(R[j] / (double)F[i]);
			}
		}
		sort(D.begin(), D.end());
		double Max = 0;
		for (int i = 1; i < D.size(); i ++) {
			Max = max(Max, D[i] / D[i - 1]);
		}
		cout << fixed << setprecision(2) << Max << '\n';
	}	
}
