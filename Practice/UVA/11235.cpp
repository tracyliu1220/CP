#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int a[MAX];
int block[MAX];
int lt[MAX], rt[MAX];

int st[4*MAX];

int L(int i) {return i << 1;}

int R(int i) {return (i << 1) + 1;}

void buildST(int p, int l, int r){
	if(l == r) st[p] = l;
	else{
		buildST(L(p), l, (l+r)/2);
		buildST(R(p), (l+r)/2 + 1, r);
		int p1 = st[L(p)], p2 = st[R(p)];
		st[p] = (block[p1] > block[p2]) ? p1 : p2;
	}
}

int quertST(int p, int l, int r, int x, int y){
	if(x < r || y < l) return -1;
	if(l >= x && r <= y) return st[p];
	int p1 = quertST(L(p), l, (l+r)/2, x, y);
	int p2 = quertST(R(p), (l+r)/2 + 1, r, x, y);
	if(p1 == -1) return p2;
	if(p2 == -1) return p1;
	return (block[p1] > block[p2]) ? p1 : p2;
}


int main(){
	int n, q, x, y;
	while(scanf("%d", &n) != EOF && n != 0){
		scanf("%d", &q);
		memset(a, 0, sizeof(a));
		int blo = 0;
		scanf("%d", &a[0]);
		for(int i = 1; i < n; i++){
			scanf("%d", &a[i]);
			if(a[i] != a[i-1])
				block[blo++] = i - 1;
		}
		block[blo] = n-1;
		int j = 0, temp = 0;
		for(int i = 0; i < n; i++){
			if(i <= block[j]){
				lt[i] = temp;
				rt[i] = block[j];
			}
			else{
				lt[i] = temp = block[j] + 1;
				rt[i] = block[j+1];
			}
			j++;
		}

		for(int i = 0; i < n; i++){
			cout << lt[i] << " " << rt[i] << endl;
		}
		buildST(1, 0, n - 1);

		// query
		for(int i = 0; i < q; i++){
			scanf("%d %d", &x, &y);
			int ans1 = quertST(1, 0, n-1, rt[x], lt[y]-1);
			int ans2 = quertST(1, 0, n-1, x, rt[x]);
			int ans3 = quertST(1, 0, n-1, lt[y], y);
			printf("%d\n", max(ans1, max(ans2, ans3)));
		}
	}
	return 0;
}
