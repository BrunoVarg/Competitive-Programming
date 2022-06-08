// DFS

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//------------------------
#define MAXN 50050

int n, m;
bool visited[MAXN];
vector<int> lista[MAXN];
//------------------------

void dfs(int x){
	visited[x] = true;
	for(auto i : lista[x]){
		if(!visited[x]){
			dfs(i);
		}
	}
}

void dfsStack(int x){
	stack<int> s;
	s.push(x);
	while(!s.empty()){
		int v = s.top();
		s.pop();
		visited[v] = true;
		for(auto i : lista[v]){
			if(!visited[i]){
				s.push(i);
			}
		}
	}
}

