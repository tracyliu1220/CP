#include <bits/stdc++.h>
using namespace std;
#define MAX 5005

typedef pair<int, int> pii;
#define F first
#define S second

pii input1[MAX];
int input2[MAX];
int ans[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	int state = 1;
	while (cin >> n && n) {
		for (int i = 0; i < n; i ++) {
			cin >> input1[i].F;
			input1[i].S = i;
		}
		sort(input1, input1 + n);

		for (int i = 0; i < n; i ++) {
			cin >> input2[i];
		}
		sort(input2, input2 + n);

		for (int i = 0; i < n; i ++)
			ans[input1[i].S] = input2[i];

		if (!state) cout << '\n';
		state = 0;

		for (int i = 0; i < n; i ++)
			cout << ans[i] << '\n';
	}
}
