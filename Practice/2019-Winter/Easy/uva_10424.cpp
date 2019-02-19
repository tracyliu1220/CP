#include <bits/stdc++.h>
using namespace std;

int add1(string str) {
	int sum = 0;
	for (int i = 0; i < str.size(); i ++) {
		if ('a' <= str[i] && str[i] <= 'z')
			sum += (int)(str[i] - 'a') + 1;
		else if ('A' <= str[i] && str[i] <= 'Z')
			sum += (int)(str[i] - 'A') + 1;
	}
	return sum;
}

int add2(int x) {
	if (x < 10) return x;
	int sum = 0;
	while (x) {
		sum += x % 10;
		x /= 10;
	}
	return add2(sum);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str1, str2;
	while (getline(cin, str1)) {
		getline(cin, str2);
		int ans1 = add2(add1(str1));
		int ans2 = add2(add1(str2));
		cout << fixed << setprecision(2) << min(ans1, ans2) * 100 / (double)max(ans1, ans2) << " \%\n";
	}

}
