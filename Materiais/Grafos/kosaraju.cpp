// Acha componentes fortemente conexas
// ou seja, que tem caminho entre todos os pares de vertices
// O(n+m)
bool visited[MAX];
int n;
vector<int> adj[MAX];
vector<int> adj2[MAX];// grafo inverso
stack<int> st;
int conex[MAX]; // conexo de cada vertice
void dfs(int u){
    visited[u] = true;
    for(auto v : adj[u]){
        if(!visited[v]) dfs(v);
    }
    st.push(u);
}
// strongly connected component
void scc(int u, int c){
    // cout<<u<<" ";
    visited[u] = true;
    conex[u] = c;
    for(auto v : adj2[u]){
        if(!visited[v]) scc(v, c);
    }
}

void kosaraju(){
    for(int i=1; i<=n; i++)visited[i]=false;
    for(int i=1; i<=n; i++) if(!visited[i]) dfs(i);  

    for(int i=1; i<=n; i++)visited[i]=false;
    while(!st.empty()){
        int u = st.top(); st.pop();
        if(!visited[u]) scc(u, u);
    }
}
int main(){
    int m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        adj[a].pb(b);
        adj2[b].pb(a);
    }

    kosaraju();

    return 0;
}