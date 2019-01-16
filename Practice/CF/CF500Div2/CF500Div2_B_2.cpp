#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, x;
	cin >> n >> x;

	int flag = 0;
	map<int, int> m;

	int a[n];
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		if(m.count(a[i])) flag = 1;
		m[a[i]] = 1;
	}

	if(flag){
		cout << 0 << endl;
		return 0;
	}

	flag = 0;

	int pre;
	for(int i = 0; i < n; i ++){
		pre = a[i];
		a[i] &= x;

		if(m.count(a[i]) && a[i] != pre)
			flag = 1;

		a[i] = pre;
	}

	if(flag){
		cout << 1 << endl;
		return 0;
	}

	flag = 0;

	for(int i = 0; i < n; i ++){
		if(m.count(a[i] & x) && a[i] != (a[i] & x))
			flag = 1;
		m[a[i] & x] = 1;
	}

	if(flag)
		cout << 2 << endl;
	else
		cout << -1 << endl;

}
