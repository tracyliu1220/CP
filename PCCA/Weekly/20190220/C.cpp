#include <bits/stdc++.h>
using namespace std;

vector<int> v(1000);
int cnt[1005] = {0};
int G[30][30];

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n * n; i ++) {
		cin >> v[i];
		cnt[v[i]] ++;
	}

	/*
	sort(v.begin(), v.begin() + n * n);
	for (int i = 0; i < n * n; i ++)
		cout << v[i] << ' ';
	cout << '\n';
	*/

	int legal;
	if (n % 2) legal = 2;
	else legal = 1;
	int k;
	int sum = 0;
	for (int i = 0; i < 1005; i ++) {
		if (cnt[i] % 2 != 0) {
			legal --;
			k = i;
		}
		sum += cnt[i] / 4;
	}
	if (n % 2) {
		cnt[k] --;
	}
	// cout << "sum = " << sum << '\n';
	if (legal <= 0 || sum < (n / 2) * (n / 2)) {
		cout << "NO\n";
		return 0;
	}

	int ptr = 0;
	for (int i = 0; i < n / 2; i ++) {
		for (int j = 0; j < n / 2; j ++) {
			while (cnt[ptr] < 4) ptr ++;
			G[i][j] = G[n - i - 1][j] = ptr;
			G[i][n - j - 1] = G[n - i - 1][n - j - 1] = ptr;
			cnt[ptr] -= 4;
		}
	}

	ptr = 0;
	if (n % 2) {
		G[n / 2][n / 2] = k;
		for (int i = 0; i < n / 2; i ++) {
			while (cnt[ptr] < 2) ptr ++;
			G[n / 2][i] = G[n / 2][n - i - 1] = ptr;
			cnt[ptr] -= 2;
		}
		for (int i = 0; i < n / 2; i ++) {
			while (cnt[ptr] < 2) ptr ++;
			G[i][n / 2] = G[n - i - 1][n / 2] = ptr;
			cnt[ptr] -= 2;
		}
	}
	
	cout << "YES\n";
	for (int i = 0; i < n; i ++) { 
		for (int j = 0; j < n; j ++)
		   cout << G[i][j] << ' ';
		cout << '\n';
	}	

}
