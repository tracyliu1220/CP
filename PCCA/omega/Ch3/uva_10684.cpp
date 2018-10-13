#include <bits/stdc++.h>
using namespace std;
#define MAX 10005
typedef long long LL;

int n;

int main() {

	cin >> n;		

	LL Max = 0;
	LL sum = 0;
	int current;

	for (int i = 0; i < n; i ++) {
		cin >> current;
		if (sum < 0) sum = current;
		else sum += current;
		Max = max(Max, sum);
	}
	
	cout << Max << endl;	
}
