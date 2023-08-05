// Acha componentes fortemente conexas
// ou seja, que tem caminho entre todos os pares de vertices
// O(n+m)

// SCC from BenQ
class SCC{
    int N;
    public:
    vector<vector<int>> adj, radj;
    stack<int> st;
    vector<bool> visited;
    // todas as componentes
    vector<int> comps;
    // componente do vertice
    vector<int> comp;
    
    void add(int x, int y) {
        adj[x].pb(y), radj[y].pb(x);
    }
    void dfs(int u){
        visited[u] = true;
        for(auto v: adj[u]) if(!visited[v]) dfs(v);
        st.push(u);
    }
    void dfs2(int u, int c){
        comp[u] = c;
        for(auto v: radj[u]) if(comp[v] == -1) dfs2(v, c);
    }
    void gen() {
        for(int i=1; i<N; i++) if(!visited[i]) dfs(i);
        while(!st.empty()){
            int u = st.top(); st.pop();
            if(comp[u] == -1){
                dfs2(u, u);
                comps.pb(u);
            }
        }
    }
    SCC(int n){
        N = n+1;
        comp.assign(N, -1);
        visited.assign(N, false);
        adj.assign(N, vector<int>());
        radj.assign(N, vector<int>());
    }
};

int32_t main(){ sws; 
    int n, m;
    cin>>n>>m;
    SCC scc(n);
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        scc.add(a, b);
    }
    int comp=0;
    vector<int> ans(n+1);
    scc.gen();
    cout<<scc.comps.size()<<endl;
    for(int i=1; i<=n; i++){
        if(!ans[scc.comp[i]]){
            ans[scc.comp[i]] = ++comp;
        }
    }
    for(int i=1; i<=n; i++){
        cout<<ans[scc.comp[i]]<<" ";
    }
    cout<<endl;
    return 0;
}
