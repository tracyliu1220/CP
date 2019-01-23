#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	string G[n];
	string GT[m];
	for (int i = 0; i < n; i ++) cin >> G[i];
	for (int i = 0; i < m; i ++) GT[i].resize(n);

	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			GT[j][i] = G[i][j];

	//GT: m->n
	int l = 0, r = 0;
	for (int i = 0; i < m; i ++) {
		l = 0, r = 0;
		for (int j = 0; j <= n; j ++) {
			if (j == n || GT[i][j] == '#') {
				sort(GT[i].begin() + l, GT[i].begin() + r);
				l = j + 1;
			}
			r ++;
		}
	}
	
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			G[i][j] = GT[j][i];

	for (int i = 0; i < n; i ++) 
		cout << G[i] << '\n';

}
