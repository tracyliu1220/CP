/*
	AC
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> v;
	int temp;
	int index = 1;

	v.push_back(0);

	while(cin >> temp){
		v.push_back(temp);
		sort(v.begin(), v.end());

		if(index % 2){
			cout << v[(index + 1) / 2] << endl;
		}else{
			cout << (v[index / 2] + v[index / 2 + 1]) / 2 << endl;
		}

		index ++;
	}

}