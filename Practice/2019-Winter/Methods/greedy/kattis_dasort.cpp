#include <bits/stdc++.h>
using namespace std;

int n;
int a[1005];
int b[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T; cin >> T; while (T --) {
		int id; cin >> id; cout << id << ' ';
		cin >> n;
		for (int i = 0; i < n; i ++) {
			cin >> a[i];
			b[i] = a[i];
		}
		sort(a, a + n);
		int ptr = 0;
		for (int i = 0; i < n; i ++) {
			if (b[i] == a[ptr]) {
				ptr ++;
			}
		}
		cout << n - ptr << '\n';
	}	
}
