#include <bits/stdc++.h>
using namespace std;

int gcd(int m, int n){
	if(n == 0) return m;
	return gcd(n, m % n);
}

int main(){

	int T;
	int a, b, c, d;
	int x1, x2, y1, y2;
	int x, y; //gcd

	cin >> T;

	while(T --){
		
		cin >> a >> b >> c >> d;
		if(a < 0){
			x1 = b;
			x2 = -a * 2;
		}else{
			x1 = -b;
			x2 = a * 2;
		}
		y1 = 4 * a * d - 4 * a * c + b * b;
		y2 = 4 * a * a;

		x = gcd(x1, x2); if(x < 0) x = -x;
		y = gcd(y1, y2); if(y < 0) y = -y;

		x1 /= x; x2 /= x;
		y1 /= y; y2 /= y;

		if(x1 == 0) x2 = 1;
		if(y1 == 0) y2 = 1;

		cout << x1 << "/" << x2 << " " << y1 << "/" << y2 << endl; 
	}

}
