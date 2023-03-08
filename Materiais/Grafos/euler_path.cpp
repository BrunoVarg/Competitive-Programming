// Acha um caminho em que visita todas as arestas somente uma vez

class EulerPath{
    int n, m, id=0;
    bool impossible=false, directed;
    vector<int> in, out, deg;
    vector<pair<int,int>> adj[MAX], path;
    vector<bool> visited;
    int src = -1;
    public:
    void add(int a, int b){
        if(directed){
            adj[a].pb({b, id});
            out[a]++, in[b]++;
        }else{
            adj[a].pb({b, id}), adj[b].pb({a, id});
            deg[a]++, deg[b]++;
        }
        id++;
    }

    void dfs(int p, int u){
        while(!adj[u].empty()){
            pair<int, int> p = adj[u].back(); adj[u].pop_back();
            int v, id; tie(v, id) = p;
            if(visited[id]) continue;
            visited[id] = true;
            dfs(u, v);
        }
        if(path.size() and path.back().first != u) impossible=true;
        path.pb({p, u});
    }

    // exists, path
    vector<int> findEulerPath(){
        for(int i=1; i<=n; i++) if(deg[i]%2 != 0) return {};
        dfs(-1, src);
        if((path.size() != m+1) or impossible) return {};
        vector<int> ans;
        reverse(all(path));
        for(int i=0; i<path.size(); i++){
            ans.pb(path[i].second);
        }
        return ans;
    }

    EulerPath(int _n, int _m, bool _directed, int _src=-1): 
    in(n+1), out(n+1), deg(n+1), visited(m, 0),
    n(_n), m(_m), directed(_directed), src(_src){}
};

int32_t main(){ sws; 
    int n, m;
    cin>>n>>m;
    EulerPath ep(n, m, true, 1);
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        ep.add(a, b);
    }
    vector<int> ans = ep.findEulerPath();
    if(ans.size()){
        print(ans, ans.size());
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }

    return 0;
}