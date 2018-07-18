/*
	AC
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int cases;
	cin >> cases;

	int current;
	while(cases --){
		cin >> current;
		if(!(current % 2))
			cout << current - 1 << " ";
		else
			cout << current << " ";
	}

	cout << endl;
}
