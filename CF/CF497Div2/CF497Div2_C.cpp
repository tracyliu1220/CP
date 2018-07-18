#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	int max = 0;
	map<int, int> m;
	int current;

	for(int i = 0; i < n; i ++){
		cin >> current;
		m[current] ++;
		if(m[current] > max) max = m[current];
	}

	cout << n - max << endl;
}
