/*
	AC
	question:	給一個數列，問是否可能為一個順序1到n陸續丟進stack，pop順序自訂使得剛好為該數列
	problem:	題目看不懂
*/
#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;

	while(cin >> n){
		if(!n)	break;

		int target[n];

		while(cin >> target[0]){

			if(!target[0]) {
				cout << endl;
				break;
			}
			for(int i = 1; i < n; i ++)
				cin >> target[i];

			stack<int> s;

			int t = 0;
			for(int i = 1; i <= n; i ++){
				s.push(i);

				while(s.size() && s.top() == target[t]){
					s.pop();
					t ++;
				}

			}


			if(t == n)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;

		}



	}

	

}