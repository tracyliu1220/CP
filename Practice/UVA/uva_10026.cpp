#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int loop, job;
	vector<map<int, float> > maps;
	
	cin >> loop;
	
	for(int i = 0; i < loop; i ++){
		cin >> job;
		
		int jobs[job][2];
		map<int, float> fines;
		
		
		for(int j = 0; j < job; j++){
			cin >> jobs[j][0] >> jobs[j][1];
			fines[j + 1] = jobs[j][1] / (float)jobs[j][0];
		}
		
		maps.push_back(fines);
		
		
		
	} 
	
	
	for(int i = 0; i < loop; i ++){
		
		map<int, float> :: iterator iter;
		int print_key = 1;
		job = maps[i].size();
		
		for(int j = 0; j < job; j++){
			for(iter = maps[i].begin(); iter != maps[i].end(); iter ++){
				if(iter->second > maps[i][print_key]){
					print_key = iter->first;
				}
			}
			if(j == job - 1)
				cout << print_key;
			else
				cout << print_key << " ";
			maps[i].erase(print_key);
			
			print_key = maps[i].begin()->first;
		}
		
		if(i != loop - 1)
			cout << "\n\n";
		else
			cout << "\n";
	}
	
	return 0;
}

