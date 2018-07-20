#include <bits/stdc++.h>
using namespace std;
#define MAX 101

int cases, N, K;
vector<int> toNxt[MAX];
int color[MAX]; //black=1, white=2
int max_num;
vector<int> container, ans;

void init(int N){
	container.clear();
	max_num = 0;
	for(int i = 1; i <= N; i ++){
		toNxt[i].clear();
		color[i] = 0;
	}

}

void backtracking(int n){
	if(n > N){
		//the most || equal to max_num && the last one is black
		if(container.size() > max_num || container.size() == max_num && color[n - 1] == 1){
			max_num = container.size();
			ans = container;
		}
		return;
	}

	bool is_black = true;
	for(int i = 0; i < toNxt[n].size(); i ++)
		if(color[toNxt[n][i]] == 1) is_black = false;

	if(is_black){
		container.push_back(n);
		color[n] = 1;

		backtracking(n + 1);

		container.pop_back();
		color[n] = 0;
	}

	color[n] = 2;

	backtracking(n + 1);

	color[n] = 0;
}

int main(){
	cin >> cases;
	while(cases --){
		cin >> N >> K;
		init(N);

		int n1, n2;
		for(int i = 0; i < K; i ++){
			cin >> n1 >> n2;
			toNxt[n1].push_back(n2);
			toNxt[n2].push_back(n1);
		}

		backtracking(1);

		cout << max_num << endl;
		for(int i = 0; i < ans.size(); i ++)
			cout << ans[i] << ((i == ans.size() - 1)? '\n' : ' ');
	}
}
