#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;
typedef long long LL;
typedef pair<int, long long> PIL;

map<int, LL> dp;
int path = 0;
int *wanted;

struct node{
	int index;
	int weight;
	vector<node*> children;
};


LL MWIS(struct node *n){
	if(n->children.size() == 0){
		wanted[n->index] = 1;
		return n->weight;
	}
		
	if(dp.count(n->index) == 1){
		return dp[n->index];
	}

	LL child_MWIS = 0;
	LL grandchild_MWIS = 0;

	for(int i = 0; i < n->children.size(); i ++){
		child_MWIS += MWIS(n->children[i]);
		for(int j = 0; j < n->children[i]->children.size(); j ++)
			grandchild_MWIS += MWIS(n->children[i]->children[j]);
	}

	if(child_MWIS > n->weight + grandchild_MWIS){
		wanted[n->index] = 2;
		return dp[n->index] = child_MWIS;
	}else{
		wanted[n->index] = 1;
		return dp[n->index] = n->weight + grandchild_MWIS;
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int total;

	while (cin >> total && total) {

		path = 0;
	
		node nodes[total];
		vector<int> if_parent(total, 1);
	
		for(int i = 0; i < total; i ++){
			cin >> nodes[i].weight;
			nodes[i].index = i;
		}
	
		int child, parent;
	
		for(int i = 0; i < total - 1; i ++){
			cin >> child >> parent;
			if_parent[child - 1] = 0;
			nodes[parent - 1].children.push_back(&nodes[child - 1]);
		}
	
		for(int i = 0; i < total; i ++){
			if(if_parent[i]){
				parent = i;
				break;
			}
		}
	
		cout << MWIS(&nodes[parent]) << endl;
		dp.clear();
	}
	
	cin >> total;

	return 0;
}
