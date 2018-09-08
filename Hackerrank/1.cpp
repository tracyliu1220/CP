#include <bits/stdc++.h>
using namespace std;

int main() {
	int s;
	cin >> s;

	if (s >= 110) 
		cout << (s - 90) * 500 << " License removed\n";
	else if (s >= 90)
		cout << (s - 90) * 300 << " Warning\n";
	else
		cout << "0 No punishment\n";
}