// Acha o menor caminho de um ponto inicial para todos os outros
// Complexidade: O(NlogN)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> pii;

const int N = 100005;
const ll oo = 1e18;

ll d[N]; // vetor onde guardamos as distancias

int n; // numeros de vertices
vector<pair<int, ll>> adj[N];

void dijkstra(int start){
	for(int u = 1; u <= n; u++)
		d[u] = oo;

	priority_queue<pii, 
	vector<pii>,
	greater<pii> > pq;

	d[start] = 0;
	pq.push({d[start], start});

	ll dt, w;
	int u, v;
	while(!pq.empty()){
		auto [dt, u] = pq.top(); pq.pop();
		if(dt > d[u]) continue;
		for(auto [v, w] : adj[u]){
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				pq.push({d[v], v});
			}
		}
	}
}

int main(){

	// le o input, qnt de vertices, arestas
	// e vertice inicial(start)
	int start = 0; // inicial
	dijkstra(start); 

	for(int u = 1; u <= n; u++){
		printf("Distancia de %d para %d: %lld\n", start, u, d[u]);
	}

}
