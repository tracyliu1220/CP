/*
 * button-up
 */
#include <bits/stdc++.h>
using namespace std;

int main(){

	int cases;
	cin >> cases;

	while(cases --){
		
		int M, C;
		cin >> M >> C;  //budget, number of garments we have to buy

		int m[25][210] = {0};
		m[0][0] = 1;

		int nC;

		for(int i = 1; i <= C; i ++){

			cin >> nC;
			int current;
			for(int j = 0; j < nC; j ++){
				cin >> current;

				for(int k = current; k <= M; k ++){
					if(m[i - 1][k - current])
						m[i][k] = 1;
				}
			}
		}


		int flag = 0;
		int ans = 0;
		for(int i = M; i >= 0; i --){
			if(m[C][i]){
				ans = i;
				flag = 1;
				break;
			}
		}

		if(flag) cout << ans << endl;
		else cout << "no solution" << endl;

	}

}
