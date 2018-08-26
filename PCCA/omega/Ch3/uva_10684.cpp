#include <bits/stdc++.h>
using namespace std;
#define MAX 10005

int n;

int main() {

	while (cin >> n && n) {
		
		int Max = 0;
		int sum = 0;
		int current;

		for (int i = 0; i < n; i ++) {
			cin >> current;
			if (sum < 0) sum = current;
			else sum += current;
			Max = max(Max, sum);
		}
		if (Max) cout << "The maximum winning streak is " << Max << "." << endl;
		else cout << "Losing streak." << endl;

	}

}
