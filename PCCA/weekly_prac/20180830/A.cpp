//15:40
#include <bits/stdc++.h>
using namespace std;
#define MAX 1e9

int N, B, H, W; //participants, budget, hetels, weeks

int main() {

	while (cin >> N >> B >> H >> W) {
		
		int p, r;
		int ans = MAX;

		for (int i = 0; i < H; i ++) {
			cin >> p;
			for (int i = 0; i < W; i ++){
				cin >> r;
				if (r >= N && p * N <= B)
				   ans = min(ans, p * N);	
			}
		}

		if (ans == 1e9) cout << "stay home" << endl;
		else cout << ans << endl;

	}

}
