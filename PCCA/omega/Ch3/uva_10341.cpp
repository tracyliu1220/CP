#include <bits/stdc++.h>
using namespace std;
#define MIN 1e-10

int p, q, r, s, t, u;

double calculate(double x){
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + (double)u;
}


int main(){

	while(cin >> p >> q >> r >> s >> t >> u){
		double L = 0.0, R = 1.0, M;
		for(int i = 0; i < 100; i ++){
			M = (L + R) / 2.0;
			if(calculate(M) <= 0) R = M;
			else L = M;
		}
		if(fabs(calculate(M)) > MIN)
			printf("No solution\n");
		else
			printf("%.4lf\n", M);
	}
}
