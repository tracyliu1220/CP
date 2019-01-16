//UVA674
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL c[8000] = {0};
int coin[6] = {0, 50, 25, 10, 5, 1};

int main() {

	c[0] = 1;
	
	//for (int i = 0; i < 8000; i ++) c[i] = 1;

	for (int i = 1; i <= 5; i ++) {
		for (int j = coin[i]; j <= 7489; j ++)
			c[j] += c[j - coin[i]];
	}
	
	//for (int i = 0; i < 10; i ++)
	//	cout << c[i] << endl;


	int n;
	while (cin >> n)
		cout << c[n] << endl;

}
