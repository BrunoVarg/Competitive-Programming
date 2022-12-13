/*
Algoritmo de busca de caminho minimo em um digrafo (grafo orientado ou dirigido) ponderado, ou seja, cujas arestas tem peso, inclusive negativo.
Acha ciclo negativo
O(V*E)
*/

int d[MAX];
int parent[MAX];
vector<pair<int,int>> adj[MAX];
 
int32_t main(){ sws; 
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        d[i] = LLINF;
    }
    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        adj[a].pb({b,c});
    }
    d[1] = 0;

    int src_cycle = -1;
    for(int j=1; j<=n and src_cycle; j++){
        src_cycle = 0;
        for(int u=1; u <= n; u++){
            for(auto [v, w]: adj[u]){
                if(d[u] + w < d[v]){
                    d[v] = d[u] + w;
                    parent[v] = u;
                    src_cycle = v;
                }
            }
        }
    }
    // there is no negative cycle
    if(!src_cycle){cout<<"NO"<<endl;}
    else {
        // there is negative cycle
        cout<<"YES"<<endl;
        vector<int> v;
        int a = src_cycle;
        for(int i = 0; i < n; i++)
            src_cycle = parent[src_cycle];

        int atual=src_cycle;
        while(true){
            v.pb(atual);
            if(atual == src_cycle && v.size()>1)break;
            atual = parent[atual];
        }
        reverse(all(v));
        print(v, (int)v.size());
    }
 
    return 0;
}
