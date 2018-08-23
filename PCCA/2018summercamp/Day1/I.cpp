#include <bits/stdc++.h>
using namespace std;

int main() {
	double n, h;
	scanf("%lf %lf", &n, &h);	

	for (int i = 1; i < n; i ++) {
		printf("%.8f", sqrt(i / n) * h);
		if (i == n - 1) printf("\n");
		else printf(" ");
	}
}
