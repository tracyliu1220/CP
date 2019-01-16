#include <bits/stdc++.h>
using namespace std;

int h[2000], w[2000];
int incr[2000] = {0}, decr[2000] = {0};

int main() {

	int cases;
	cin >> cases;

	for (int c = 1; c <= cases; c ++) {
		
		int n;
		cin >> n;

		int incMax = 0, decMax = 0;
		memset(incr, 0, sizeof(incr));
		memset(decr, 0, sizeof(decr));
		
		for (int i = 0; i < n; i ++) 
			cin >> h[i];

		for (int i = 0; i < n; i ++)
			cin >> w[i];

		incMax = decMax = incr[0] = decr[0] = w[0];

		for (int i = 1; i < n; i ++) {
			incr[i] = w[i]; decr[i] = w[i];
			for (int j = 0; j < i; j ++) {
				if (h[j] < h[i]) incr[i] = max(incr[i], incr[j] + w[i]);
				if (h[j] > h[i]) decr[i] = max(decr[i], decr[j] + w[i]);
			}

			incMax = max(incMax, incr[i]);
			decMax = max(decMax, decr[i]);
				
		}

		cout << "Case " << c << ". ";

		if (incMax >= decMax)
			cout << "Increasing (" << incMax << "). Decreasing (" << decMax << ").\n";
		else
			cout << "Decreasing (" << decMax << "). Increasing (" << incMax << ").\n";

		
	}
}
