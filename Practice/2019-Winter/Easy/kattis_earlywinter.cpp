#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, dm;
	cin >> n >> dm;
	int tmp;
	for (int i = 0; i < n; i ++) {
		cin >> tmp;
		if (tmp <= dm) {
			cout << "It hadn't snowed this early in " << i << " years!\n";
			return 0;
		}
	}
	cout << "It had never snowed this early!\n";
}
