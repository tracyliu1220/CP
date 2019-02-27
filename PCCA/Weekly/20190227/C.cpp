#include <bits/stdc++.h>
using namespace std;

map<string, int> idx;
struct ph {
	string name;
	vector<string> number;
};
vector<ph> phone;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	int cnt = 0;
	int T, n; cin >> T;
	phone.resize(T);

	for (int t = 0; t < T; t ++) {
		cin >> str;
		int id;
		if (idx.count(str)) {
			id = idx[str];
		} else {
			idx[str] = cnt; cnt ++;
			id = idx[str];
			phone[id].name = str;
		}

		cin >> n;
		for (int i = 0; i < n; i ++) {
			cin >> str;
			int subti = 0;
			for (int j = 0; j < phone[id].number.size(); j ++) {
				string num = phone[id].number[j];
				if (num.size() > str.size()) {
					int suffix = 1;
					for (int k = 0; k < str.size(); k ++) {
						if (num[num.size() - str.size() + k] != str[k])
							suffix = 0;
					}
					if (suffix) {
						subti = 1;
						break;
					}
				} else {
					int suffix = 1;
					for (int k = 0; k < num.size(); k ++) {
						if (str[str.size() - num.size() + k] != num[k])
							suffix = 0;
					}
					if (suffix) {
						phone[id].number[j] = str;
						subti = 1;
						break;
					}
				}
			}
			if (!subti) phone[id].number.push_back(str);
		}	
	}

	cout << cnt << '\n';
	for (int i = 0; i < cnt; i ++) {
		cout << phone[i].name << ' ';
		cout << phone[i].number.size() << ' ';
		for (int j = 0; j < phone[i].number.size(); j ++) {
			cout << phone[i].number[j] << ' ';
		}
		cout << '\n';
	}

}
