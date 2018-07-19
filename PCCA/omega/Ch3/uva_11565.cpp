#include <iostream>
using namespace std;

int main(){
	
	int cases;
	cin >> cases;
	
	while(cases --){
		
		int k;
		int founded = 0;
		int A, B, C;
		cin >> A >> B >> C;
		
		for(int i = -100; i <= 100; i ++){
			for(int j = i + 1; j <= 100; j ++){
				k = A - i - j;
				if(i * j * k == B && i * i + j * j + k * k == C && k != i && k != j){
					cout << i << " " << j << " " << k << endl;
					founded = 1;
					break;
				}
				
				
			}
			if(founded)
					break;
		}
		
		if(!founded) 
			cout << "No solution." << endl;
	}


	return 0;
}

