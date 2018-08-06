#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	string s1, s2;
	cin >> s1 >> s2;


	int cnt = 0;
	
	for(int i = 0; i < n; i ++){
		if(s1[i] == s2[i]) continue;
		int diff = m[s2[i]] - i;
		cnt += diff;
		for(int j = i; j < n; j ++)
			if(m[s2[j]] < m[s2[i]]) m[s2[j]] ++;
		cout << i << " " << cnt << endl;
	}

	cout << cnt << endl;
}
