// topological sort
// retorna uma ordenacao topologica
// caso for um dag, se nao, retorna vazio se tiver ciclo
// O(n+m)

int n;
int visited[MAX];
vector<int> adj[MAX];
int pos=0;
vector<int> ord;

bool has_cycle=false;
void dfs(int v){
    if(visited[v]) return;
    visited[v] = true;
    for(auto u : adj[v]){
        if(visited[u] == 1) has_cycle=true;
        else if(!visited[u]) dfs(u);
    }
    ord[pos] = v;
    visited[v] = 2;
    pos--;
}

vector<int> topo_sort(int n){
    ord.resize(n);
    for(int i=0; i<n; i++){
        if(!visited[i]) dfs(i);
    }

    if(has_cycle) return {};
    else return ord;
}

int main(){
    int m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        adj[a].pb(b);
    }

    has_cycle = false;
    pos = n-1;
    vector<int> ans = topo_sort(n);

    return 0;
}