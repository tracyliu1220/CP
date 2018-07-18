/*
	AC
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	int flag = 1;
	cin >> s;

	int i = 0;

	while(i < s.length()){
		if(s[i] == 'n' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
			i ++;
			continue;
		}
		i ++;
		if(i == s.length() || s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u'){
			flag = 0;
			break;
		}
		i ++;
	}

	if(flag) cout << "YES" << endl;
	else cout << "NO" << endl;

}
