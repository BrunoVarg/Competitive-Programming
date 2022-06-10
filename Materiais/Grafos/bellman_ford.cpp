/*
Algoritmo de busca de caminho mínimo em um digrafo (grafo orientado ou dirigido) ponderado, ou seja, cujas arestas têm peso, inclusive negativo.
*/

#include <bits/stdc++.h>
using namespace std;

// pode usar uma tuple
struct Edge {
    // [de onde vem, pra onde vai, peso]
    int from, to, custo;

    Edge(int a=0, int b=0,int c=0 ){
        from = a;
        to=b;
        custo = c;
    }

};

int main(){

    int n, m;
    cin>>n>>m;
    vector<Edge> arestas(m);

    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        arestas[i] = Edge(a, b, c);
    }

    vector<int> distancia(n + 1, 100000000);
    distancia[1]=0;
    for(int i=0; i<n-1; i++){
        for(auto aresta : arestas){
            if (distancia[aresta.from] + aresta.custo < distancia[aresta.to]){
                distancia[aresta.to] = distancia[aresta.from] + aresta.custo;
            }
        }
    }

    for(int i=1; i<=n; i++){
        cout<<"Distancia até o vertice "<<i<<" "<<distancia[i]<<endl;
    }

    return 0;
}