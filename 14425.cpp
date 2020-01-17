#include<iostream>
using namespace std;

typedef struct trie {
	bool end=false;
	trie *next[26];
	trie() {
		for (int i = 0; i < 26; i++) {
			next[i] = nullptr;
		}
	}
	~trie() {
		for (int i = 0; i < 26; i++) {
			if (next[i] != nullptr) {
				delete next[i];
			}
		}
	}
	void update(char* input, int idx) {
		if (input[idx+1] == '\0') {
			end = true;
		}
		else {
			if (next[input[idx + 1] - 'a'] == nullptr ) {
				next[input[idx + 1] - 'a'] = new trie();
			}
			next[input[idx + 1] - 'a']->update(input, idx + 1);
		}
	}
	bool find(char* input, int idx) {
		if (this->end == true) {
			return true;
		}
		else if(input[idx+1]=='\0' || next[input[idx + 1] - 'a']==nullptr) {
			return false;
		}
		else {
			return next[input[idx + 1] - 'a']->find(input, idx + 1);
		}
	}
}trie;
int main(void)
{
	int N, M;
	char inputs[10001];
	cin >> N >> M;

	trie *begin=new trie[26];
	for (int i = 0; i < N; i++) {
		cin >> inputs;
		begin[inputs[0]-'a'].update(inputs, 0);
	}
	int ans = 0;
	for (int i = 0; i < M; i++) {
		cin >> inputs;
		if (begin[inputs[0] - 'a'].find(inputs, 0)) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}