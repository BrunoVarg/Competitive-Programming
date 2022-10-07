#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 100005;
const ll oo = 1e18;

ll d[N]; // vetor onde guardamos as distancias

int n; // numeros de vertices
vector<pair<int, ll>> g[N];

void dijkstra(int start){
	for(int u = 1; u <= n; u++)
		d[u] = oo;

	priority_queue<pair<ll, int>, vector<pair<ll, int>>,
	greater<pair<ll, int>> > pq;

	d[start] = 0;
	pq.emplace(d[start], start);

	ll dt, w;
	int u, v;
	while(!pq.empty()){
		tie(dt, u) = pq.top(); pq.pop();
		if(dt > d[u]) continue;
		for(auto edge : g[u]){
			tie(v, w) = edge;
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				pq.emplace(d[v], v);
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
