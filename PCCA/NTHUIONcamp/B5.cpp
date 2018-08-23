#include <bits/stdc++.h>
using namespace std;

struct bracket{
	int kind;
	int difference;
	int b[6];
	int index;
	string s;
	//size()
};

bool compare (bracket a, bracket b) {
	if (a.kind < b.kind) return true;
	else if (a.kind == b.kind) {
		if (a.difference < b.difference) return true;
		else if (a.difference == b.difference) {
			if (a.s.size() < b.s.size()) return true;
			else if (a.s.size() == b.s.size()) {
				if (a.b[0] + a.b[1] < b.b[0] + b.b[1]) return true;
				else if (a.b[0] + a.b[1] == b.b[0] + b.b[1]) {
					if (a.b[2] + a.b[3] < b.b[2] + b.b[3]) return true;
					else if (a.b[2] + a.b[3] == b.b[2] + b.b[3]) {
						if (a.b[4] + a.b[5] < b.b[4] + b.b[5]) return true;
						else if (a.b[4] + a.b[5] == b.b[4] + b.b[5]) {
							if (a.index < b.index) return true;
						}	
					}
				}
			}
		}
	}
	return false;
}

int main(){

	int T;
	cin >> T;

	while (T --) {
		int N;
		cin >> N;

		vector<bracket> brackets(N);
		for (int i = 0; i < N; i ++) {
			cin >> brackets[i].s;
			
			for (int j = 0; j < 6; j ++) brackets[i].b[j] = 0;

			for (int j = 0; j < brackets[i].s.size(); j ++) {
				if (brackets[i].s[j] == '{') brackets[i].b[0] ++;
				else if (brackets[i].s[j] == '}') brackets[i].b[1] ++;
				else if (brackets[i].s[j] == '[') brackets[i].b[2] ++;
				else if (brackets[i].s[j] == ']') brackets[i].b[3] ++;
				else if (brackets[i].s[j] == '(') brackets[i].b[4] ++;
				else if (brackets[i].s[j] == ')') brackets[i].b[5] ++;
			}

			brackets[i].kind = 0;
			if (brackets[i].b[0] + brackets[i].b[1] > 0)  brackets[i].kind ++;
			if (brackets[i].b[2] + brackets[i].b[3] > 0)  brackets[i].kind ++;
			if (brackets[i].b[4] + brackets[i].b[5] > 0)  brackets[i].kind ++;

			brackets[i].difference = abs(brackets[i].b[0] + brackets[i].b[2] + brackets[i].b[4] - brackets[i].b[1] - brackets[i].b[3] - brackets[i].b[5]);

			brackets[i].index = i;
		}

		sort (brackets.begin(), brackets.end(), compare);

		for (int i = 0; i < N; i ++)
			cout << brackets[i].s << endl;

		if (T) cout << endl;
	}

}
