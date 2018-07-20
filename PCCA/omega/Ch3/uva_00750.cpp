#include <bits/stdc++.h>
using namespace std;

int row[8], cases, a, b, Count = 1;

bool place(int r, int c){
	for(int prev = 0; prev < c; prev ++)
		if(row[prev] == r || abs(row[prev] - r) == abs(prev - c)) return false;
	return true;
}

void backtrack(int c){
	if(c == 8 && row[b] == a){
		printf("%2d     ", Count++);
		for(int i = 0; i < 8; i ++)
			printf(" %d", row[i] + 1);
		printf("\n");
	}
	for(int r = 0; r < 8; r ++)
		if(place(r, c)) {
			row[c] = r;
			backtrack(c + 1);
		}
}

int main(){
	cin >> cases;
	while(cases --){
		Count = 1;
		cin >> a >> b; a--; b --;
		printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
		backtrack(0);
		if(cases) printf("\n");
	}
}



