//read:		20:26
//start:	20:30
//submit:	20:42
#include <bits/stdc++.h>
using namespace std;
#define MIN 1e-6
typedef long long LL;

LL sum[30005];
int coin[11] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};

int main() {

	double tar;
	while (scanf("%lf", &tar) && tar) {
		
		int t = tar * 100 + MIN;
		memset(sum, 0, sizeof(sum));
		
		sum[0] = 1;

		for (int c = 0; c < 11; c ++) {
			for (int i = coin[c]; i <= t; i ++) {
				if (sum[i - coin[c]]) sum[i] += sum[i - coin[c]];
			}
		}

		printf("%6.2f%17lld\n", tar, sum[t]);


	}
}
