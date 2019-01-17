#include <bits/stdc++.h>
using namespace std;
#define MAX 5000
#define F first
#define S second
typedef pair<int, int> pii;

struct Arr {
	string name;
	int B, Cd, D;
	vector<pii> LU;
	vector<int> C;
};

int N, R;
map<string, int> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> R;
	vector<Arr> Arrs(N);
	for (int i = 0; i < N; i ++) {
		cin >> Arrs[i].name;
		cin >> Arrs[i].B >> Arrs[i].Cd >> Arrs[i].D;
		int D = Arrs[i].D, B = Arrs[i].B;
		int l, u;
		for (int j = 0; j < Arrs[i].D; j ++) {
			cin >> l >> u;
			Arrs[i].LU.push_back( {l, u} );
		}
		m[Arrs[i].name] = i;
		Arrs[i].C.resize(Arrs[i].D + 1);

		Arrs[i].C[D] = Arrs[i].Cd;
		Arrs[i].C[0] = B;
		for (int j = D - 1; j > 0; j --)
			Arrs[i].C[j] = Arrs[i].C[j + 1] 
				* (Arrs[i].LU[j].S - Arrs[i].LU[j].F + 1);
		for (int j = 1; j <= D; j ++)
			Arrs[i].C[0] -= Arrs[i].C[j] * Arrs[i].LU[j - 1].F;
	}

	while (R --) {
		string name; cin >> name;
		int idx = m[name];

		cout << name << "[";
		int ans = Arrs[idx].C[0];
		int input;
		for (int i = 0; i < Arrs[idx].D; i ++) {
			cin >> input;
			ans += Arrs[idx].C[i + 1] * input;
			cout << input << ((i == Arrs[idx].D - 1)? "":", ");
		}
		cout << "] = " << ans << '\n';
	}
}
