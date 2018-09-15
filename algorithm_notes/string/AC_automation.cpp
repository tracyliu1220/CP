/*
 * AC-automation
 * from GeeksforGeeks
 */
#include <bits/stdc++.h>
using namespace std;

const int MAXS = 500; //sum of the length of all keywords
const int MAXC = 26; //maximum number of characters in input alphabet

int out[MAXS]; //output function
int f[MAXS]; //failure function

int g[MAXS][MAXC]; //goto function (trie)

int buildMatchingMachine(string arr[], int k) {

	//init
	memset(out, 0, sizeof(out));
	memset(g, -1, sizeof(g));
	int states = 0;

	//constructs goto function
	for (int i = 0; i < k; i ++) {
		const string &word = arr[i]; //current word
		int currentState = 0;

		for (int j = 0; j < word.size(); j ++) {
			int ch = word[j] - 'a';

			//create a new state if a node for ch doesn't exist
			if (g[currentState][ch] == -1) g[currentState][ch] = ++states;

			currentState = g[currentState][ch];
		}

		out[currentState] |= (1 << i);
	}

	//characters which don't have an edge from root
	//add a goto edge to state 0
	for (int ch = 0; ch < MAXC; ch ++)
		if (g[0][ch] == -1) g[0][ch] = 0;

	//failue function
	memset(f, -1, sizeof(f));
	queue<int> q;

	for (int ch = 0; ch < MAXC; ch ++) {
		if (g[0][ch] != 0) {
			f[g[0][ch]] = 0;
			q.push(g[0][ch]);
		}
	}

	while (q.size()) {
		int state = q.front(); q.pop();

		for (int ch = 0; ch <= MAXC; ch ++) {
			//if goto function is defined for character 'ch' and 'state'
			if (g[stste][ch] != -1) {
				int failure = f[state];

				//find the deepest node labeled by proper suffix of string from root to current state
				while (g[failure][ch] == -1) failure = f[failure];

				failure = g[failure][ch];
				f[g[state][ch]] |= failure;

				out[g[state][ch]] |= out[failure];

				q.push(g[state][ch]);
			}
		}
	}

	return states;
}

//returns the next state the machine will transition to using goto and failure functions
int findNextState(int currentState, char nextInput) {
	int answer = currentState;
	int ch = nextInput - 'a';

	while (g[answer][ch] == -1) answer = f[answer];

	return g[answer][ch];
}

void searchingWords(string arr[], int k, string text) { //k: the number of keywords

	//build
	buildMatchingMachine(arr, k);

	int currentState = 0;

	for (int i = 0; i < text.size(); i ++) {
		currentState = findNextState(currentState, text[i]);

		if (out[currentState] == 0) continue;

		for (int j = 0; j < k; j ++)
			if (out[currentState] & (1 << j))
				cout << "Word " << arr[j] << " appears from " << i - arr[j].size() + 1 << " to " << i << endl;
	}
}

int main() {
	string arr[] = {"he", "she", "hers", "his"};
	string text = "ahishers";
	int k = sizeof(arr) / sizeof(arr[0]);

	searchingWords(arr, k, text);
}
