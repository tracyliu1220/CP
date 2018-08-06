#include <bits/stdc++.h>
using namespace std;

int n, m;

int main(){

	while(cin >> n >> m){	//n heads, m knights

		if(!n && !m) break;

		vector<int> heads(n), knights(m);

		//n lines of diameters of the dragon's heads
		for(int i = 0; i < n; i ++)
			cin >> heads[i];

		//m lines of the heights of the knights
		for(int i = 0; i < m; i ++)
			cin >> knights[i];

		sort(heads.begin(), heads.end());
		sort(knights.begin(), knights.end());

		int flag = 0;

		int j = 0, cnt = 0;

		for(int i = 0; i <= n; i ++){
			if(i == n){ flag = 1; break;}
			while(knights[j] < heads[i]){
				j ++;
				if(j >= m) break;
			}
			if(j >= m) break;
			if(knights[j] >= heads[i]){
				cnt += knights[j];
				j ++;
			}else break;
		}


		if(flag) cout << cnt << endl;
		else cout << "Loowater is doomed!" << endl;
		
		heads.clear();
		knights.clear();
	}

}
