/*
Lowest Common ancestor (LCA) - é o nome típico dado para o seguinte problema: dado uma Árvore cuja raiz é um vértice arbitrário e dois vértices u,v que a pertencem, diga qual é o nó mais baixo(relativo a raiz) que é ancestral de u,v.
*/

#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e5;
int depth[SIZE];
vector<int> graph[SIZE];

void pre_process_depth(int u, int d) {
	depth[u] = d;
	for(auto adj : graph[u]) {
		pre_process_depth(adj, d + 1);
	}
}

int p2k[SIZE][log2(SIZE)+1];
int lca(int u, int v) {
	if(depth[u] < depth[v]) swap(u,v);
	for (int i = 20; i >= 0; --i) {
		if(depth[p2k[u][i]] >= depth[v])
			u = p2k[u][i];	
	}
	if(u == v) return u;
	for (int i = 20; i >= 0; --i) {
		if(p2k[v][i] != p2k[u][i]) {
			v = p2k[v][i];
			u = p2k[u][i];
		}
	}
	return pai[v];
}

int climb(int node, int k){
	for(int i = 20; i >= 0; i--) {
		if(k >= (1 << i)) {
			node = p2k(node,i);
			k -= (1 << i);
		}
	}
	return node;
}

int dist(int u, int v){
	return depth[u] + depth[v] -2*depth[lca(u,v)];
}

int main() {
	// codigo
	// le os pais e monta o grafo
	pai[raiz] = raiz;
	pre_proccess_depth(raiz); // tipicamente qual vertice é a raiz nao importa
	for(int node = 0; node < SIZE; node++){
		p2k[node][0] = pai[node];
	}
	for(int node = 0; node < SIZE; node++) {
		for(int k = 1; k <= log2(SIZE); k++) {
			p2k[node][k] = p2k[p2k[node][k-1]][k-1];
		}
	}
	// resolve problema
}