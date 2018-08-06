#include <bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define MIN 1e-8

int main(){

	int n, m;
	int flag = 1;
	cin >> n >> m;	//planets, weight of the payload
	
	int a[n], b[n];

	for(int i = 0; i < n; i ++){ //ai, number of tons (lift up)
		cin >> a[i];
		if(a[i] < 2)
			flag = 0;
	}

	for(int i = 0; i < n; i ++){ //bi, number of tons (land)
		cin >> b[i];
		if(b[i] < 2)
			flag = 0;
	}

	double R = MAX;
	double L = 0;
	double M;
	double W;

	while(R - L > MIN && flag){
		M = (R + L) / 2;
		
		W = m + M;
		W -= W / a[0];

		for(int i = 1; i < n; i ++){
			W -= W / b[i];
			W -= W / a[i];
		}

		W -= W / b[0];

		if(W < m)
			L = M;
		else
			R = M;
	}

	if(flag && L >= 0 && L <= MAX)
		cout << L << endl;
	else
		cout << -1 << endl;
	

}
