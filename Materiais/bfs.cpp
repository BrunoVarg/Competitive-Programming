// BFS

#include <bits/stdc++.h>[]
using namespace std;

//------------------------
#define MAXN 50050

int n, m;
bool visited[MAXN];
vector<int> lista[MAXN];
//------------------------

void bfs(int x){
	
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		int v = q.front();
		q.pop();
		visited[v] = true;
		for(auto i : lista[v]){
			if(!visited[i]){
				q.push(i);
			}
		}
	}
}
