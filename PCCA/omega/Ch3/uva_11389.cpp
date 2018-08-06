#include <bits/stdc++.h>
using namespace std;

int main(){

	int n, d, r;
	while(cin >> n >> d >> r){
		if(!n && !d && !r) break;
		vector<int> morning(n), afternoon(n);

		for(int i = 0; i < n; i ++)
			cin >> morning[i];
		
		for(int i = 0; i < n; i ++)
			cin >> afternoon[i];

		sort(morning.begin(), morning.end());
		sort(afternoon.begin(), afternoon.end());

		int sum = 0;
		for(int i = 0; i < n; i ++){
			if(morning[i] + afternoon[n - i - 1] > d)
				sum += morning[i] + afternoon[n - i - 1] - d; 
		}

		cout << sum * r << endl;
	}
}
