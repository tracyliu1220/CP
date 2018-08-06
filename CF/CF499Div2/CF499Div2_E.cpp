#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	
	int zero = 0;
	int num[n];
	int Max = 0;
	for(int i = 0; i < n; i ++){
		cin >> num[i];
		if(num[i] > Max)
			Max = num[i];
	}

	for(int i = 0; i < n; i ++)
		cout << num[i] << " ";
	cout << endl;	

	vector<int> sum(Max * k + 1);
	sum[0] = 1;

	for(int i = n - 1; i >= 0; i --){
		for(int j = 1; j <= Max * k; j ++){
			if(sum[j - num[i]]) sum[j] = 1;
		}
		for(int i = 0; i < 50; i ++)
			if(sum[i]) cout << i << " ";
		cout << endl;
	}

	//for(int i = 0; i < 50; i ++)
	//	if(sum[i]) cout << i << " ";
	//cout << endl;

	map<int, int> m;
	map<int, int>::iterator iter;

	for(int i = 1; i <= Max * k; i ++)
		if(sum[i])
			m[i % k] = 1;

	cout << m.size() << endl;
	for(iter = m.begin(); iter != m.end(); iter ++)
		cout << iter->first << " ";
	cout << endl;
}
