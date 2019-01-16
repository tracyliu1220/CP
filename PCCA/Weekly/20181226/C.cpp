#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int x, y, _x, _y;
    int T;
    
    while(cin >> T && T){
        
        cin >> x >> y;
        while(T --){
            
            cin >> _x >> _y;
            
            if(_x - x > 0 && _y - y > 0)      cout << "NE\n";
            else if(_x - x < 0 && _y - y > 0) cout << "NO\n";
            else if(_x - x > 0 && _y - y < 0) cout << "SE\n";
            else if(_x - x < 0 && _y - y < 0) cout << "SO\n";
            else cout << "divisa\n";
        }
    }
}
