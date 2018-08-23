nclude <iostream>
#include <vector>
#include <cstdio>
using namespace std;

vector<vector<int> > city;
vector<int> vis;
int ans = 0, cnt = 0;

double DFS(int id, int level){
	vis[id] = 1;
	double sum = 0;
	int deg = 0;

	int if_leaf = 1;
	for(int i = 0; i < city[id].size(); i++){
		if(!vis[city[id][i]]) {
			deg ++;
			sum += DFS(city[id][i], level+1);
			if_leaf = 0;
		}
	}

	if(if_leaf){
		return level;
	}

	return sum / deg;
}


int main(){
	int n, a, b;
	scanf("%d", &n);
	city.resize(n+1);
	vis.resize(n+1);
	for(int i = 1; i < n; i++){
		scanf("%d %d", &a, &b);
		city[a].push_back(b);
		city[b].push_back(a);
	}
	printf("%.8f\n", DFS(1, 0));
	return 0;
}
