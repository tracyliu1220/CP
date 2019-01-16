#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	while(1){
		if(!n) break;

		int s[n];
		for(int i = 0; i < n; i ++)
			cin >> s[i];

		for(int a = 0; a < n - 5; a ++)
			for(int b = a + 1; b < n - 4; b ++)
				for(int c = b + 1; c < n - 3; c ++)
					for(int d = c + 1; d < n - 2; d ++)
						for(int e = d + 1; e < n - 1; e ++)
							for(int f = e + 1; f < n; f ++)
								cout << s[a] << " "  << s[b] << " " <<  s[c] << " " << s[d] << " " << s[e] << " " << s[f] << endl;
			
		cin >> n;
		if(n) cout << endl;
	}
}
