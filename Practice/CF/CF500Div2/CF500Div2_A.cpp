#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	int sum1 = 0, sum2 = 0;
	int temp;

	for(int i = 0; i < n; i ++){
		cin >> temp;
		sum1 += temp;
	}

	for(int i = 0; i < n; i ++){
		cin >> temp;
		sum2 += temp;
	}

	if(sum1 >= sum2) cout << "Yes" << endl;
	else cout << "No" << endl;

}
