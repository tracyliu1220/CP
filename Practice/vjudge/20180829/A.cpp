//UVA580
#include <bits/stdc++.h>
using namespace std;

int f[105][3] = {0};

int main() {

	// 1 base
	f[1][0] = f[1][1] = 1;

	for (int i = 2; i <= 100; i ++) {
		f[i][0] = f[i-1][0] + f[i-1][1] + f[i-1][2];
		f[i][1] = f[i-1][0];
		f[i][2] = f[i-1][1];
	}
	
	int n;
	while (cin >> n && n) {
		cout << (1 << n) - f[n][0] - f[n][1] - f[n][2] << endl;
	}

}
