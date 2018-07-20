#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

int main(){
	int cases;
	cin >> cases;

	while(cases --){
		int bar, n;
		cin >> bar >> n;
		int sum[MAX] = {0};
		sum[0] = 1;

		int b[n];
		for(int i = 0; i < n; i ++)
			cin >> b[i];
		
		for(int i = 0; i < n; i ++){		
			for(int j = MAX - 1; j >= b[i]; j --){
				if(sum[j - b[i]]) sum[j] = 1;
			}
		}

		if(sum[bar]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
