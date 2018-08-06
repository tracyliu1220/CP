#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	int letters[27] = {0};

	for(int i = 0; i < n; i ++)
		letters[s[i] - 'a' + 1] = 1;

	int i = 0;
	int cnt = 0;
	int sum = 0;

	while(i < 27 && cnt < k){
		if(letters[i]){
			cnt ++;
			sum += i;
			i += 2;
		}else
			i ++;
	}

	if(cnt == k)
		cout << sum << endl;
	else
		cout << -1 << endl;
}
