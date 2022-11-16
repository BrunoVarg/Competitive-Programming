// Constroi e procura por uma string em uma arvore
// Complexidade - O(N*|s|*qtd_char)

#include <bits/stdc++.h>
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int MAX = 2005;

class Trie{
	int node = 0;
	// number of strings
	char c_min;
	int qtd_char, max_size;
	vector<vector<int>> trie;
	vector<int> pref, end;

	public:
	void add(string s){
		int cur = 1;
		for(auto c: s){
			if(!trie[cur][c-c_min]){
				trie[cur][c-c_min] = ++node;
			}
			cur = trie[cur][c-c_min];
			pref[cur]++;
		}
		end[cur]++;
	}
	
	void erase(string s){
		int cur = 1;
		for(auto c: s){
			cur = trie[cur][c-c_min];
			pref[cur]--;
		}
		end[cur]--;
	}

	int find(string s){
		int cur = 1;
		for(auto c: s){
			if(!trie[cur][c-c_min]) return 0;
			cur = trie[cur][c-c_min];
		}
		return cur;
	}

	int count_pref(string s){
		return pref[find(s)];
	}
	
	Trie(int qtd_char_=26, char c_min_ = 'a', int max_size_=MAX): 
	c_min(c_min_), qtd_char(qtd_char_), max_size(max_size_){
		trie.resize(max_size, vector<int>(qtd_char));
		pref.resize(max_size);
		end.resize(max_size);
	}
};

int32_t main(){ sws;
	Trie t;
	t.add("abcd");
	t.add("ad");
	t.erase("ad");
	cout<<t.count_pref("a")<<endl;
	
	return 0;
}
