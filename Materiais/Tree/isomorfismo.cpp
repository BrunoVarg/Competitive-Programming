// Verificar se árvores são isomorfas
// enraizando nas centroids
// O(VlogV)

map<vector<int>, int> hasher;
struct tree_iso{
    int n;
    vector<vector<int>> adj;
    vector<int> sub, centroids;

    tree_iso(int n_):n(n_), adj(n_+1), sub(n_+1){} 

    void dfs_centroid(int v, int p) {
        sub[v] = 1;
        bool is_cent = true;
        for (int u : adj[v]) if (u != p) {
            dfs_centroid(u, v), sub[v] += sub[u];
            if(sub[u] > n/2) is_cent = false;
        }
        if (is_cent and (n - sub[v] <= n/2)) centroids.pb(v);
    }

    int hashify(int v, int p){
        vector<int> ch;
        for(int u : adj[v]) if (u != p) ch.pb(hashify(u, v));
        sort(ch.begin(), ch.end());
        if(!hasher[ch]) hasher[ch] = hasher.size();
        return hasher[ch];
    }

    ll to_hash() {
        centroids.clear();
        dfs_centroid(1, -1);
        if (centroids.size() == 1) return hashify(centroids[0], -1);
        ll h1 = hashify(centroids[0], -1);
        ll h2 = hashify(centroids[1], -1);
        return (min(h1, h2) << 30) + max(h1, h2);
    }
};