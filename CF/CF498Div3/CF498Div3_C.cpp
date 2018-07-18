/*
	WA
*/
#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;
	vector<int> v(n);

	for(int i = 0; i < n; i ++)
		cin >> v[i];

	int lsum = 0, rsum = 0, lindex = -1, rindex = n;
	int ans = 0;

	while(lindex != rindex){
		if(lsum == rsum){
			ans = lsum;
			lindex ++;
			lsum += v[lindex];
		}else if(lsum < rsum){
			lindex ++;
			lsum += v[lindex];
		}else{
			rindex --;
			rsum += v[rindex];
		}
	}

	cout << ans << endl;
}
