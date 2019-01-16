#include <bits/stdc++.h>
using namespace std;

int main() {

	int T;
	cin >> T;

	while (T --) {

		int n, m;
		cin >> n >> m;

		if (n % (m + 1)) cout << "first" << endl;
		else cout << "second" << endl;
	}
}
