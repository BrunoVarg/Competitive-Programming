#include <bits/stdc++.h>
using namespace std;
//g++ -std=c++17 -O2 -Wall x.cpp -o x

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(msg, x) cout << msg << " = " << x << endl
#define pb push_back
#define ff first
#define ss second
typedef long long ll;
const int MAX = 110;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;


struct Edge {
    // [de onde vem, pra onde vai, peso]
    int from, to, custo;

    Edge(int a=0, int b=0,int c=0 ){
        from = a;
        to=b;
        custo = c;
    }

};

int main(){ sws; 

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